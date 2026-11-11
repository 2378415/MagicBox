package com.magicbullet.capture.core;

import android.Manifest;
import android.app.Activity;
import android.content.pm.PackageManager;
import android.hardware.usb.UsbDevice;
import android.os.Handler;
import android.os.Looper;
import android.os.SystemClock;
import android.util.Log;

import com.jiangdg.usb.USBMonitor;

/**
 * The two permission gates that stand between the app and a UVC capture card.
 *
 * <p>1. CAMERA. {@code UsbUserPermissionManager#requestPermission} answers "denied"
 * immediately - without showing any dialog - when the caller lacks CAMERA and the
 * device reports video capture. Every UVC capture card does, so this is mandatory.
 *
 * <p>2. USB device access. The system broadcast is the primary signal, but it is not
 * delivered reliably on every ROM, so the grant is also polled with
 * {@link USBMonitor#hasPermission(UsbDevice)}.
 */
public final class UsbPermissionFlow {

    private static final String TAG = "UsbPermissionFlow";
    private static final long POLL_INTERVAL_MS = 400L;
    private static final int POLL_TRIES = 15;
    public static final int REQ_CAMERA = 1001;

    public interface Callback {
        void onStatus(String status, String detail);

        void onUsbAccessGranted(UsbDevice device);

        void onUsbAccessDenied(UsbDevice device, long waitedMs);

        void onCameraPermissionResult(boolean granted);
    }

    private final Activity mActivity;
    private final USBMonitor mMonitor;
    private final Callback mCallback;
    private final Handler mMain = new Handler(Looper.getMainLooper());

    private UsbDevice mPending;
    private int mPollCount;
    private long mRequestedAtMs;

    public UsbPermissionFlow(Activity activity, USBMonitor monitor, Callback callback) {
        mActivity = activity;
        mMonitor = monitor;
        mCallback = callback;
    }

    public boolean hasCamera() {
        return mActivity.checkSelfPermission(Manifest.permission.CAMERA)
                == PackageManager.PERMISSION_GRANTED;
    }

    /**
     * @return true when CAMERA is already granted; otherwise the request is started
     * and false is returned.
     */
    public boolean ensureCamera() {
        if (hasCamera()) {
            return true;
        }
        mCallback.onStatus("需要相机权限",
                "Android 规定：访问 UVC 视频类 USB 设备前必须先授予 CAMERA 权限，\n"
                        + "否则系统会直接回「未授权」，不会弹任何授权框。\n"
                        + "正在申请相机权限…");
        mActivity.requestPermissions(new String[]{Manifest.permission.CAMERA}, REQ_CAMERA);
        return false;
    }

    public boolean onRequestPermissionsResult(int requestCode, int[] grantResults) {
        if (requestCode != REQ_CAMERA) {
            return false;
        }
        boolean granted = grantResults.length > 0
                && grantResults[0] == PackageManager.PERMISSION_GRANTED;
        Log.i(TAG, "CAMERA permission granted=" + granted);
        mCallback.onCameraPermissionResult(granted);
        return true;
    }

    public boolean isPendingFor(UsbDevice device) {
        return mPending != null && device != null
                && mPending.getDeviceId() == device.getDeviceId();
    }

    public long waitedMs() {
        return mRequestedAtMs > 0 ? SystemClock.elapsedRealtime() - mRequestedAtMs : -1L;
    }

    /**
     * Asks the system for USB access. Must only be called with CAMERA granted.
     *
     * @return true when the request reached the system (result arrives by broadcast
     * or by polling)
     */
    public boolean requestUsb(UsbDevice device) {
        if (!hasCamera()) {
            return false;
        }
        mPending = device;
        mPollCount = 0;
        mRequestedAtMs = SystemClock.elapsedRealtime();

        boolean failed;
        try {
            // USBMonitor.requestPermission returns true when the request could NOT
            // be made (see its javadoc), false when the system accepted it.
            failed = mMonitor.requestPermission(device);
        } catch (Throwable t) {
            Log.e(TAG, "requestPermission threw", t);
            stopPolling();
            mCallback.onStatus("USB 权限请求失败", String.valueOf(t));
            return false;
        }
        if (failed) {
            stopPolling();
            mCallback.onStatus("USB 权限请求没有发出去",
                    "系统直接拒绝了这次请求，连弹窗都没有。\n"
                            + "点「重新扫描」重试；仍然不行就拔插采集卡后再试。");
            return false;
        }
        mMain.postDelayed(mPoller, POLL_INTERVAL_MS);
        return true;
    }

    /** Called when the permission broadcast reports a denial. */
    public void onBroadcastDenied(UsbDevice device) {
        long waited = waitedMs();
        stopPolling();
        mCallback.onUsbAccessDenied(device, waited);
    }

    public void stopPolling() {
        mMain.removeCallbacks(mPoller);
        mPending = null;
        mPollCount = 0;
    }

    private final Runnable mPoller = new Runnable() {
        @Override
        public void run() {
            final UsbDevice device = mPending;
            if (device == null) {
                return;
            }
            boolean granted;
            try {
                granted = mMonitor.hasPermission(device);
            } catch (Throwable t) {
                granted = false;
            }
            if (granted) {
                Log.i(TAG, "permission granted (polled) for deviceId=" + device.getDeviceId());
                stopPolling();
                mCallback.onUsbAccessGranted(device);
                return;
            }
            if (++mPollCount >= POLL_TRIES) {
                Log.w(TAG, "permission still denied after " + POLL_TRIES + " polls");
                long waited = waitedMs();
                stopPolling();
                mCallback.onUsbAccessDenied(device, waited);
                return;
            }
            mMain.postDelayed(this, POLL_INTERVAL_MS);
        }
    };
}
