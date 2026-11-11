package com.magicbullet.capture.core;

import android.app.Activity;
import android.hardware.usb.UsbConstants;
import android.hardware.usb.UsbDevice;
import android.os.Handler;
import android.os.HandlerThread;
import android.os.Looper;
import android.os.SystemClock;
import android.util.Log;
import com.jiangdg.utils.Size;
import android.view.SurfaceHolder;

import com.jiangdg.uvc.IFrameCallback;
import com.jiangdg.uvc.UVCCamera;
import com.jiangdg.usb.USBMonitor;

import java.io.File;
import java.nio.ByteBuffer;
import java.util.LinkedHashSet;
import java.util.List;
import java.util.Locale;
import java.util.Set;

/**
 * Owns the one and only {@link USBMonitor} + {@link UVCCamera} pair.
 *
 * <p>Fragments never touch libuvc directly: they attach/detach a Surface and listen
 * for state. That keeps the USB session alive across tab switches - the camera is
 * only closed when the Activity really goes away.
 */
public final class UvcSession implements USBMonitor.OnDeviceConnectListener {

    private static final String TAG = "UvcSession";

    public interface Listener {
        void onStatus(String status, String detail);

        void onPreviewInfo(String device, String mode);

        /** Fired after the capture mode was renegotiated (or rejected). */
        default void onCaptureMode(int width, int height, int fps, boolean ok) {
        }
    }

    /**
     * Called on the capture thread for every frame, right after it leaves the UVC
     * pipeline. Keep it cheap: anything slow here drops frames.
     */
    public interface FrameListener {
        void onFrame(long timestampNanos, int width, int height);
    }

    /** Raw RGBX pixels, valid only inside the callback. */
    public interface RawFrameListener {
        void onFrame(ByteBuffer rgbx, long timestampNanos, int width, int height);
    }

    /** Selectable capture modes, YUY2 only: the card's MJPEG path is CPU-bound on this phone. */
    public static final int[][] CAPTURE_MODES = {
            {2560, 1440, 60},
            {2560, 1440, 30},
            {1920, 1080, 60},
            {1920, 1080, 30},
    };

    private static final int[][] SIZE_ATTEMPTS = {
            {1920, 1080, 60, UVCCamera.FRAME_FORMAT_YUYV},
            {1280, 720, 60, UVCCamera.FRAME_FORMAT_YUYV},
            {1920, 1080, 60, UVCCamera.FRAME_FORMAT_MJPEG},
            {1920, 1080, 30, UVCCamera.FRAME_FORMAT_YUYV},
            {1280, 720, 30, UVCCamera.FRAME_FORMAT_YUYV},
            {640, 480, 30, UVCCamera.FRAME_FORMAT_YUYV},
    };

    private final Activity mActivity;
    private final USBMonitor mMonitor;
    private final UsbPermissionFlow mPermission;
    private final HandlerThread mThread;
    private final Handler mCameraHandler;
    private final Handler mMain = new Handler(Looper.getMainLooper());
    private final Object mLock = new Object();

    private UVCCamera mCamera;
    private UsbDevice mDevice;
    private SurfaceHolder mSurface;
    private boolean mPreviewing;
    private int mFrameFps = 60;
    private volatile boolean mStreaming;
    private boolean mOpening;
    private boolean mRegistered;
    private boolean mDestroyed;

    private Listener mListener;
    private volatile FrameListener mFrameListener;
    private volatile RawFrameListener mRawFrameListener;
    private volatile int mFrameWidth;
    private volatile int mFrameHeight;
    private long mFpsWindowStartNanos;
    private int mFpsWindowCount;
    private String mStatus = "等待 USB 采集卡…";
    private String mDetail = "";
    private String mDeviceText = "未连接";
    private String mModeText = "—";

    public UvcSession(Activity activity) {
        mActivity = activity;
        mMonitor = new USBMonitor(activity, this);
        mPermission = new UsbPermissionFlow(activity, mMonitor, mPermissionCallback);
        mThread = new HandlerThread("uvc-camera");
        mThread.start();
        mCameraHandler = new Handler(mThread.getLooper());
        android.content.SharedPreferences prefs = prefs();
        mFrameWidth = prefs.getInt("w", 1920);
        mFrameHeight = prefs.getInt("h", 1080);
        mFrameFps = prefs.getInt("fps", 60);
    }

    private android.content.SharedPreferences prefs() {
        return mActivity.getSharedPreferences("uvc_capture", android.content.Context.MODE_PRIVATE);
    }

    /** The capture mode currently in use, as {@code {width, height, fps}}. */
    public int[] captureMode() {
        return new int[]{mFrameWidth, mFrameHeight, mFrameFps};
    }

    /**
     * Stores the capture mode. libuvc only honours the frame interval when the stream is opened,
     * and this card refuses to stream again after a close without a replug, so the caller
     * recreates the activity instead of renegotiating the live stream.
     */
    public void setCaptureMode(int width, int height, int fps) {
        prefs().edit().putInt("w", width).putInt("h", height).putInt("fps", fps).apply();
        mFrameWidth = width;
        mFrameHeight = height;
        mFrameFps = fps;
        mMain.post(() -> {
            Listener listener = mListener;
            if (listener != null) {
                listener.onCaptureMode(width, height, fps, true);
            }
        });
    }

    // ------------------------------------------------------------------ lifecycle

    public void start() {
        if (mDestroyed) {
            return;
        }
        try {
            if (!mRegistered) {
                mMonitor.register();
                mRegistered = true;
            }
        } catch (Throwable t) {
            Log.e(TAG, "USBMonitor.register failed", t);
            post("USB 监控启动失败", String.valueOf(t));
            return;
        }
        mMain.postDelayed(this::scanAndOpen, 300);
    }

    /**
     * Activity went to the background. Deliberately keeps the camera streaming: the
     * capture card never re-locks its HDMI receiver once the UVC stream stops, and a
     * physical cable replug would be the only way back.
     */
    public void stop() {
        mPermission.stopPolling();
    }

    public void destroy() {
        mDestroyed = true;
        mPermission.stopPolling();
        closeCamera();
        try {
            mMonitor.unregister();
        } catch (Throwable t) {
            Log.w(TAG, "USBMonitor.unregister failed", t);
        }
        try {
            mMonitor.destroy();
        } catch (Throwable t) {
            Log.w(TAG, "USBMonitor.destroy failed", t);
        }
        mThread.quitSafely();
    }

    public void setListener(Listener listener) {
        mListener = listener;
        if (listener != null) {
            listener.onStatus(mStatus, mDetail);
            listener.onPreviewInfo(mDeviceText, mModeText);
        }
    }

    public void setFrameListener(FrameListener listener) {
        mFrameListener = listener;
    }

    public void setRawFrameListener(RawFrameListener listener) {
        mRawFrameListener = listener;
    }

    private int mLastBright = -1;

    /**
     * Latency probe: average luma of the frame, logged only on black<->white
     * transitions. Used to measure PC-screen -> frame-callback latency by flashing a
     * full-screen window on the source and comparing timestamps.
     */
    private void probeLuma(ByteBuffer frame) {
        int capacity = frame.capacity();
        if (capacity <= 0) {
            return;
        }
        long sum = 0;
        int count = 0;
        for (int i = 0; i < capacity; i += 4096) {
            sum += frame.get(i) & 0xFF;
            count++;
        }
        int avg = (int) (sum / count);
        int bright = avg > 128 ? 1 : 0;
        if (mLastBright != -1 && bright != mLastBright) {
            Log.i(TAG, "PROBE " + (bright == 1 ? "bright" : "dark")
                    + " avg=" + avg
                    + " wall=" + System.currentTimeMillis()
                    + " mono=" + SystemClock.elapsedRealtimeNanos());
        }
        mLastBright = bright;
    }
    private final IFrameCallback mFrameCallback = new IFrameCallback() {
        @Override
        public void onFrame(ByteBuffer frame) {
            long now = SystemClock.elapsedRealtimeNanos();
            probeLuma(frame);
            FrameListener listener = mFrameListener;
            if (listener != null) {
                listener.onFrame(now, mFrameWidth, mFrameHeight);
            }
            RawFrameListener raw = mRawFrameListener;
            if (raw != null) {
                raw.onFrame(frame, now, mFrameWidth, mFrameHeight);
            }

            mFpsWindowCount++;
            if (mFpsWindowStartNanos == 0L) {
                mFpsWindowStartNanos = now;
                return;
            }
            long elapsed = now - mFpsWindowStartNanos;
            if (elapsed >= 1_000_000_000L) {
                double fps = mFpsWindowCount * 1_000_000_000.0 / elapsed;
                Log.d(TAG, "capture fps=" + String.format(Locale.US, "%.1f", fps)
                        + " (" + mFrameWidth + "x" + mFrameHeight + ")");
                PipelineStats.get().setCaptureFps(fps);
                PipelineStats.get().publish();
                mFpsWindowStartNanos = now;
                mFpsWindowCount = 0;
            }
        }
    };

    public boolean isCameraOpen() {
        synchronized (mLock) {
            return mCamera != null;
        }
    }

    public void onRequestPermissionsResult(int requestCode, int[] grantResults) {
        mPermission.onRequestPermissionsResult(requestCode, grantResults);
    }

    // ------------------------------------------------------------------ preview surface

    /** Called when the preview Surface becomes available (tab shown / surface created). */
    public void attachSurface(SurfaceHolder holder) {
        mSurface = holder;
        final UVCCamera camera;
        synchronized (mLock) {
            camera = mCamera;
        }
        Log.i(TAG, "attachSurface cameraOpen=" + (camera != null) + " valid="
                + (holder != null && holder.getSurface() != null && holder.getSurface().isValid()));
        if (camera == null) {
            return;
        }
        mCameraHandler.post(() -> {
            try {
                camera.setPreviewDisplay(holder.getSurface());
                if (!mStreaming) {
                    camera.startPreview();
                    mStreaming = true;
                }
                mPreviewing = true;
            } catch (Throwable t) {
                Log.e(TAG, "attachSurface failed", t);
            }
        });
    }

    /** Called when the preview Surface goes away (tab hidden). Keeps the camera open. */
    public void detachSurface() {
        mSurface = null;
        final UVCCamera camera;
        synchronized (mLock) {
            camera = mCamera;
        }
        Log.i(TAG, "detachSurface cameraOpen=" + (camera != null) + " previewing=" + mPreviewing);
        if (camera == null || !mPreviewing) {
            return;
        }
        mCameraHandler.post(() -> {
            try {
                // Detach the window but keep the stream alive: this capture card only
                // re-locks its HDMI receiver on a physical hot-plug, so a stopPreview()
                // here would black out the preview until someone replugs the cable.
                camera.setPreviewDisplay((android.view.Surface) null);
            } catch (Throwable t) {
                Log.w(TAG, "detach surface failed", t);
            } finally {
                mPreviewing = false;
            }
        });
    }

    // ------------------------------------------------------------------ device flow

    public void rescan() {
        mMain.post(this::scanAndOpen);
    }

    private void scanAndOpen() {
        if (mDestroyed) {
            return;
        }
        mPermission.stopPolling();

        List<UsbDevice> devices;
        try {
            devices = mMonitor.getDeviceList();
        } catch (Throwable t) {
            Log.e(TAG, "getDeviceList failed", t);
            post("读取 USB 设备失败", String.valueOf(t));
            return;
        }
        if (devices == null || devices.isEmpty()) {
            post("未发现 USB 设备", "请确认：OTG 已开启、采集卡已插好、线材支持 USB 3.0");
            setDeviceText("未连接");
            return;
        }

        UsbDevice uvc = null;
        for (UsbDevice device : devices) {
            if (isUvcDevice(device)) {
                uvc = device;
                break;
            }
        }
        if (uvc == null) {
            post("发现了 USB 设备，但没有 UVC 视频接口", "");
            setDeviceText("未连接");
            return;
        }
        setDeviceText(deviceLabel(uvc));
        tryOpen(uvc);
    }

    private void tryOpen(UsbDevice device) {
        if (isCameraOpen()) {
            return;
        }
        boolean granted;
        try {
            granted = mMonitor.hasPermission(device);
        } catch (Throwable t) {
            granted = false;
        }
        if (granted) {
            openCamera(device, null);
            return;
        }
        if (mPermission.isPendingFor(device)) {
            return;
        }
        if (!mPermission.ensureCamera()) {
            return;
        }
        post("等待 USB 权限…", "请在系统弹窗中允许访问该 USB 设备");
        mPermission.requestUsb(device);
    }

    private final UsbPermissionFlow.Callback mPermissionCallback = new UsbPermissionFlow.Callback() {
        @Override
        public void onStatus(String status, String detail) {
            post(status, detail);
        }

        @Override
        public void onUsbAccessGranted(UsbDevice device) {
            openCamera(device, null);
        }

        @Override
        public void onUsbAccessDenied(UsbDevice device, long waitedMs) {
            if (waitedMs >= 0 && waitedMs < 500) {
                post("USB 权限被拒绝",
                        "系统在 " + waitedMs + " ms 后就回了「未授权」。\n"
                                + "这么快 = 系统弹窗根本没有出现，是系统直接拒绝了这个请求。\n"
                                + "点「重新扫描」再试一次。");
            } else {
                post("USB 权限被拒绝",
                        "系统返回了「未授权」（等待 " + waitedMs + " ms）。\n"
                                + "这个耗时说明弹窗确实出现过，是被取消或拒绝了。\n"
                                + "点「重新扫描」再申请一次。");
            }
        }

        @Override
        public void onCameraPermissionResult(boolean granted) {
            if (granted) {
                post("相机权限已授予", "正在重新扫描采集卡…");
                mMain.postDelayed(UvcSession.this::scanAndOpen, 200);
            } else {
                post("相机权限被拒绝",
                        "没有 CAMERA 权限时，系统会直接拒绝 UVC 设备的 USB 授权请求，\n"
                                + "弹窗根本不会出现。\n"
                                + "请到 设置 → 应用 → MagicBullet → 权限 里打开「相机」。");
            }
        }
    };

    // ------------------------------------------------------------------ camera

    private void openCamera(UsbDevice device, USBMonitor.UsbControlBlock ctrlBlock) {
        Log.i(TAG, "openCamera requested: " + deviceLabel(device));
        mCameraHandler.post(() -> {
            synchronized (mLock) {
                if (mCamera != null || mOpening || mDestroyed) {
                    return;
                }
                mOpening = true;
            }
            UVCCamera camera = null;
            try {
                camera = new UVCCamera();
                USBMonitor.UsbControlBlock block = ctrlBlock;
                if (block == null) {
                    block = mMonitor.openDevice(device);
                }
                if (block == null) {
                    throw new IllegalStateException("openDevice() returned null");
                }
                camera.open(block);
                dumpSupportedModes(camera);

                int[] chosen = configurePreview(camera);

                // Frame tap for the detector. RAW avoids a colour conversion we do not
                // read yet; switch to YUV/NV21 when the model needs pixels.
                mFrameWidth = chosen[0];
                mFrameHeight = chosen[1];
                mFrameFps = chosen[2];
                prefs().edit().putInt("w", mFrameWidth).putInt("h", mFrameHeight)
                        .putInt("fps", mFrameFps).apply();
                try {
                    camera.setFrameCallback(mFrameCallback, UVCCamera.PIXEL_FORMAT_RGBX);
                } catch (Throwable t) {
                    Log.w(TAG, "setFrameCallback failed", t);
                }

                synchronized (mLock) {
                    mCamera = camera;
                    mDevice = device;
                    mPreviewing = false;
                }
                post("预览已启动",
                        deviceLabel(device) + "\n"
                                + chosen[0] + "x" + chosen[1] + " @ " + chosen[2] + "fps");
                final String mode = chosen[0] + "x" + chosen[1] + " @ " + chosen[2] + "fps  "
                        + (chosen[3] == UVCCamera.FRAME_FORMAT_YUYV ? "YUY2" : "MJPEG");
                setModeText(mode);
                final int cw = chosen[0];
                final int ch = chosen[1];
                final int cf = chosen[2];
                mMain.post(() -> {
                    Listener listener = mListener;
                    if (listener != null) {
                        listener.onCaptureMode(cw, ch, cf, true);
                    }
                });

                SurfaceHolder holder = mSurface;
                if (holder != null) {
                    attachSurface(holder);
                }
            } catch (Throwable t) {
                Log.e(TAG, "openCamera failed", t);
                synchronized (mLock) {
                    mCamera = null;
                    mDevice = null;
                }
                if (camera != null) {
                    try {
                        camera.destroy();
                    } catch (Throwable ignored) {
                        // nothing else we can do
                    }
                }
                post("打开采集卡失败", String.valueOf(t));
            } finally {
                synchronized (mLock) {
                    mOpening = false;
                }
            }
        });
    }

    /**
     * Writes every size the camera advertises for both formats to cache/uvc_modes.txt, so the
     * question "can this card do 2K?" is answered by the device instead of by guesswork.
     */
    private void dumpSupportedModes(UVCCamera camera) {
        try {
            StringBuilder text = new StringBuilder();
            int[] formats = {UVCCamera.FRAME_FORMAT_YUYV, UVCCamera.FRAME_FORMAT_MJPEG};
            for (int format : formats) {
                text.append(format == UVCCamera.FRAME_FORMAT_YUYV ? "YUY2" : "MJPEG").append(':');
                List<com.jiangdg.utils.Size> sizes = camera.getSupportedSizeList(format);
                if (sizes == null) {
                    text.append(" <none>\n");
                    continue;
                }
                Set<String> unique = new LinkedHashSet<>();
                for (com.jiangdg.utils.Size size : sizes) {
                    unique.add(size.width + "x" + size.height);
                }
                for (String size : unique) {
                    text.append(' ').append(size);
                }
                text.append('\n');
            }
            text.append("raw: ").append(camera.getSupportedSize()).append('\n');
            QnnRuntime.writeText(new File(mActivity.getCacheDir(), "uvc_modes.txt"),
                    text.toString());
        } catch (Throwable t) {
            Log.w(TAG, "dumpSupportedModes failed", t);
        }
    }
    private int[] configurePreview(UVCCamera camera) {
        Throwable lastError = null;
        // The mode picked on the preview page wins; everything else is a fallback.
        int[][] attempts = new int[SIZE_ATTEMPTS.length + 1][];
        int[] preferred = {mFrameWidth > 0 ? mFrameWidth : 1920,
                mFrameHeight > 0 ? mFrameHeight : 1080, mFrameFps,
                UVCCamera.FRAME_FORMAT_YUYV};
        attempts[0] = preferred;
        System.arraycopy(SIZE_ATTEMPTS, 0, attempts, 1, SIZE_ATTEMPTS.length);
        for (int[] attempt : attempts) {
            try {
                camera.setPreviewSize(attempt[0], attempt[1], 1, attempt[2],
                        attempt[3], UVCCamera.DEFAULT_BANDWIDTH);
                return attempt;
            } catch (Throwable t) {
                lastError = t;
                Log.w(TAG, "setPreviewSize rejected: " + attempt[0] + "x" + attempt[1]
                        + "@" + attempt[2], t);
            }
        }
        throw new IllegalStateException("采集卡不支持任何可用预览格式", lastError);
    }

    private void closeCamera() {
        UVCCamera camera;
        synchronized (mLock) {
            camera = mCamera;
            mCamera = null;
            mDevice = null;
            mPreviewing = false;
            mStreaming = false;
        }
        if (camera == null) {
            return;
        }
        try {
            camera.setFrameCallback(null, 0);
        } catch (Throwable ignored) {
            // camera may already be gone
        }
        try {
            camera.stopPreview();
        } catch (Throwable ignored) {
            // already stopped
        }
        try {
            camera.destroy();
        } catch (Throwable t) {
            Log.w(TAG, "camera.destroy failed", t);
        }
    }

    // ------------------------------------------------------------------ USBMonitor callbacks

    @Override
    public void onAttach(UsbDevice device) {
        Log.i(TAG, "onAttach: " + deviceLabel(device));
        if (!isUvcDevice(device)) {
            return;
        }
        // Refresh the label even when the camera is already open (the card can drop
        // and re-appear while our UVC stream keeps running).
        setDeviceText(deviceLabel(device));
        if (isCameraOpen()) {
            return;
        }
        mMain.post(() -> tryOpen(device));
    }

    @Override
    public void onDetach(UsbDevice device) {
        Log.i(TAG, "onDetach: " + deviceLabel(device));
        closeCamera();
        setDeviceText("未连接");
        setModeText("—");
        post("USB 设备已拔出", "");
    }

    @Override
    public void onConnect(UsbDevice device, USBMonitor.UsbControlBlock ctrlBlock,
                          boolean createNew) {
        Log.i(TAG, "onConnect: " + deviceLabel(device) + ", createNew=" + createNew);
        openCamera(device, ctrlBlock);
    }

    @Override
    public void onDisconnect(UsbDevice device, USBMonitor.UsbControlBlock ctrlBlock) {
        Log.i(TAG, "onDisconnect: " + deviceLabel(device));
        closeCamera();
    }

    @Override
    public void onCancel(UsbDevice device) {
        Log.w(TAG, "onCancel: permission denied for " + deviceLabel(device));
        mPermission.onBroadcastDenied(device);
    }

    // ------------------------------------------------------------------ helpers

    private void post(String status, String detail) {
        mStatus = status;
        mDetail = detail;
        mMain.post(() -> {
            Listener listener = mListener;
            if (listener != null) {
                listener.onStatus(status, detail);
            }
        });
    }

    private void setDeviceText(String text) {
        mDeviceText = text;
        mMain.post(() -> {
            Listener listener = mListener;
            if (listener != null) {
                listener.onPreviewInfo(text, mModeText);
            }
        });
    }

    private void setModeText(String text) {
        mModeText = text;
        mMain.post(() -> {
            Listener listener = mListener;
            if (listener != null) {
                listener.onPreviewInfo(mDeviceText, text);
            }
        });
    }

    public static boolean isUvcDevice(UsbDevice device) {
        if (device == null) {
            return false;
        }
        if (device.getDeviceClass() == UsbConstants.USB_CLASS_VIDEO) {
            return true;
        }
        for (int i = 0; i < device.getInterfaceCount(); i++) {
            if (device.getInterface(i).getInterfaceClass() == UsbConstants.USB_CLASS_VIDEO) {
                return true;
            }
        }
        return false;
    }

    public static String deviceLabel(UsbDevice device) {
        if (device == null) {
            return "未连接";
        }
        String name = null;
        try {
            name = device.getProductName();
        } catch (Throwable ignored) {
            // productName may need permission on some ROMs
        }
        if (name == null || name.isEmpty()) {
            name = device.getDeviceName();
        }
        return String.format(Locale.US, "%s (VID:%04X PID:%04X)",
                name, device.getVendorId(), device.getProductId());
    }
}
