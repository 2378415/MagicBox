package com.magicbullet.capture.core;

import android.app.PendingIntent;
import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.content.IntentFilter;
import android.hardware.usb.UsbConstants;
import android.hardware.usb.UsbDevice;
import android.hardware.usb.UsbDeviceConnection;
import android.hardware.usb.UsbEndpoint;
import android.hardware.usb.UsbInterface;
import android.hardware.usb.UsbManager;
import android.os.Handler;
import android.os.HandlerThread;
import android.os.Looper;
import android.os.SystemClock;
import android.util.Log;

import androidx.core.content.ContextCompat;

import java.util.ArrayList;
import java.util.List;
import java.util.Locale;

/**
 * The MagicBox control port (CH343 -> UART0), driven with the binary protocol only.
 *
 * <p>Frame: {@code 0x5A | cmd | seq | len(u16 LE) | payload | crc8(cmd..payload)}, CRC poly 0x07.
 * Replies come back as {@code cmd | 0x80} with the request seq; asynchronous event frames land
 * in 0xE0..0xEF. Motion is fire-and-forget, so only an explicit {@code PING} (0x35) measures
 * the link.
 *
 * <p>Why there is no serial library here: this is a CH343 (0x1A86/0x55D3) and it is not
 * register-compatible with the CH340/CH341 that every Android driver implements. Its line
 * setting is a single vendor request ({@code 0xA1}), not the CH341 register file, so the driver
 * below follows WCH's own {@code ch343.c}: divisor/factor from {@code ch343_get()} packed into
 * wIndex, LCR bits into wValue. Requesting DTR/RTS lines is one {@code 0xA4} write with the
 * inverted control mask, and motion in/out is plain bulk transfer.
 */
public final class ControlPort {

    private static final String TAG = "ControlPort";

    public static final int CMD_MOTION = 0x31;
    public static final int CMD_BUTTON = 0x32;
    public static final int CMD_WHEEL = 0x33;
    public static final int CMD_QUERY = 0x34;
    public static final int CMD_PING = 0x35;
    public static final int CMD_SUMV = 0x36;
    public static final int CMD_SUMV_STOP = 0x37;
    public static final int CMD_SUMV_STATE = 0x38;
    public static final int CMD_EVT_CTL = 0x39;
    public static final int CMD_EVT_READ = 0x3A;
    public static final int CMD_EVT_STAT = 0x3B;
    /** Aiming entry: dx i16, dy i16, max_ms u8, flags u8 [, dead_min u8]. */
    public static final int CMD_AIM = 0x3C;
    /** 12 B: active, last_result, last_counts u16, last_dur_ms u16, aborted u16, rounds u16,
     *  dead_hits u8, gen u8. */
    public static final int CMD_AIM_STATE = 0x3D;
    /** 8 B: btn_in u16, btn_sent u16, wait_max_us u16, motion_dropped u16. */
    public static final int CMD_HID_STAT = 0x3E;
    /** 12 B: in_chg u32, out_chg u32, extra u32 — button loop audit. */
    public static final int CMD_BTN_AUDIT = 0x3F;
    /** Clears the box-side AIM counters (rounds/aborted/dead hits/last result). */
    public static final int CMD_AIM_RESET = 0x40;
    /** Clears the box-side event ring and its counters. */
    public static final int CMD_EVT_RESET = 0x41;
    /** 10 B: report_id, len, 8 report bytes — what the box last put on the wire. */
    public static final int CMD_LAST_HID = 0x42;
    /** 按键轨迹日志：请求 since u16，回包 total u16 + count u8 + count×8B 记录。 */
    public static final int CMD_BTN_LOG = 0x44;
    public static final int CMD_EVT_PUSH = 0xE1;

    /** AIM flags. */
    public static final int AIM_FLAG_SESSION_CLAMP = 0x01;
    public static final int AIM_FLAG_TURBO = 0x02;

    /** Defaults from the interface document: hand-like motion, randomised seed. */
    public static final int DEFAULT_SPEED = 400;
    /**
     * 2026-11-11 firmware rework: {@code 0x00} is the aiming profile (trapezoid, 1% arc, no tremor),
     * {@code 0x40} (bit6) switches to the humanised profile, {@code 0x80} (bit7) is "as fast as the
     * endpoint allows". bit1/bit2/bit5 only mean something inside bit6; bit3/bit4 were removed.
     */
    public static final int MODE_AIM = 0x00;
    public static final int MODE_HUMAN = 0x40;
    public static final int MODE_TURBO = 0x80;
    /** Bit that gates the humanised profile; tremor/sub-motion/anti-stick only apply with it. */
    public static final int MODE_BIT_HUMAN = 0x40;
    public static final int MODE_BIT_TREMOR = 0x02;
    public static final int MODE_BIT_SUBMOVE = 0x04;
    public static final int DEFAULT_MODE = MODE_AIM;

    /** Firmware >= 2026-11-10 runs at 921600; older builds answered at 115200. */
    private static final int[] BAUD_LADDER = {921600, 115200};
    private static final int MAX_PAYLOAD = 64;
    private static final int WRITE_TIMEOUT_MS = 200;
    private static final int READ_TIMEOUT_MS = 100;
    /** logcat 会被系统丢弃（实测整段消失），所以同一条日志也落盘，便于事后取现场。 */
    private static final long LOG_MAX_BYTES = 256L * 1024;
    private static final String ACTION_PERMISSION = "com.magicbullet.capture.CONTROL_USB_PERMISSION";

    // CH343 vendor requests (WCH ch343.c)
    /** CH343 vendor/product id (VID_1A86 & PID_55D3). */
    private static final int VENDOR_ID = 0x1A86;
    private static final int PRODUCT_ID = 0x55D3;
    private static final int REQ_VENDOR_OUT = 0x40;
    private static final int REQ_VENDOR_IN = 0xC0;
    private static final int CMD_LINE = 0xA1;      // CMD_C1: baud divisor + LCR
    private static final int CMD_CONTROL = 0xA4;   // CMD_C2: DTR/RTS
    private static final int CMD_VERSION = 0x5F;   // CMD_C6: two version bytes

    // LCR halves of the 0xA1 request
    private static final int LCR_COUNT = 0x80 | 0x04 | 0x08;      // enable RX/TX, clock
    private static final int LCR_VALUE = 0x80 | 0x40 | 0x03;      // 8 data bits, 1 stop, no parity
    private static final int CTRL_DTR = 0x20;
    private static final int CTRL_RTS = 0x40;

    public interface Listener {
        /** Connection state changed: {@code status} is a headline, {@code detail} the reason. */
        void onState(String status, String detail);

        /** One diagnostic line (link handshake, RTT, write failures, raw replies). */
        void onLog(String line);
    }

    /** The consumed-key channel: edges pushed by the box, plus its own view of what reached the PC. */
    public interface EvtListener {
        /** A subscribed button changed. {@code mask} is the full button bitmap, {@code edge} the bits that changed. */
        void onEvt(int mask, int edge);

        /** Periodic EVT_STAT: {@code lastFwd} is the button byte the PC actually saw. */
        void onEvtStat(int lastFwd, int flags, int subscribedMask, int cur);
    }

    /** One {@code 0x3D AIM_STATE} snapshot. */
    public static final class AimState {
        public final int active;
        /** 1 started/arrived · 2 replaced · 3 rejected · 4 dead zone · 5 watchdog · 6 over limit. */
        public final int lastResult;
        public final int lastCounts;
        public final int lastDurMs;
        public final int aborted;
        public final int rounds;
        public final int deadHits;
        public final int gen;

        AimState(int active, int lastResult, int lastCounts, int lastDurMs, int aborted,
                 int rounds, int deadHits, int gen) {
            this.active = active;
            this.lastResult = lastResult;
            this.lastCounts = lastCounts;
            this.lastDurMs = lastDurMs;
            this.aborted = aborted;
            this.rounds = rounds;
            this.deadHits = deadHits;
            this.gen = gen;
        }

        public static String resultText(int result) {
            switch (result) {
                case 1:
                    return "到位";
                case 2:
                    return "被替换";
                case 3:
                    return "拒绝";
                case 4:
                    return "死区";
                case 5:
                    return "看门狗";
                case 6:
                    return "超限";
                default:
                    return "未知";
            }
        }
    }

    public interface AimStateListener {
        void onAimState(AimState state);
    }

    private static ControlPort sInstance;

    private final Context mContext;
    private final UsbManager mUsb;
    private final Handler mMain = new Handler(Looper.getMainLooper());
    private final HandlerThread mWorker;
    private final Handler mWorkerHandler;
    private final Object mWriteLock = new Object();
    private final List<String> mLog = new ArrayList<>();

    private Listener mListener;
    private volatile EvtListener mEvtListener;
    private volatile AimStateListener mAimStateListener;
    private volatile AimState mLastAimState;
    private volatile boolean mSawAimState;
    private volatile HidStat mLastHidStat;
    private volatile BtnAudit mLastBtnAudit;
    private volatile LastHid mLastHid;
    private volatile int mLastBtnLogTotal;
    /** Safety net: force a release report whenever the real mouse has no button held. */
    private volatile boolean mAutoRelease = true;
    private UsbDeviceConnection mConnection;
    private UsbEndpoint mEpIn;
    private UsbEndpoint mEpOut;
    private Thread mReader;
    private volatile boolean mOpen;
    private int mBaud;
    private String mDeviceLabel = "未连接";
    /** 当前已打开的 USB 设备，用于插拔广播比对。 */
    private UsbDevice mDevice;
    private String mStatus = "控制口未连接";
    private String mDetail = "";

    private int mSeq = 1;
    private volatile int mMode = DEFAULT_MODE;
    private volatile double mLastRttMs = -1;
    private long mPingSentNanos;
    private long mTxFrames;
    private long mRxFrames;

    /** Stream parser state: {@code mBuf[0..mLen)} is unparsed input. */
    private final byte[] mBuf = new byte[1024];
    private int mLen;
    /** 连续写/读失败计数：达到阈值就判定链路已断（设备被拔/重新枚举后旧 fd 会一直返回 -1）。 */
    private int mTxFailures;
    private int mRxFailures;
    private static final int FAILURE_LIMIT = 3;

    private final BroadcastReceiver mPermissionReceiver = new BroadcastReceiver() {
        @Override
        public void onReceive(Context context, Intent intent) {
            String action = intent.getAction();
            UsbDevice attached = intent.getParcelableExtra(UsbManager.EXTRA_DEVICE);
            if (UsbManager.ACTION_USB_DEVICE_DETACHED.equals(action)) {
                if (attached != null && mDevice != null
                        && attached.getDeviceId() == mDevice.getDeviceId()) {
                    handleLinkLost("设备被拔出");
                }
                return;
            }
            if (UsbManager.ACTION_USB_DEVICE_ATTACHED.equals(action)) {
                // 重新插上：权限通常仍然有效，直接自动连回去，省得每次手动点「连接」
                if (attached != null && attached.getVendorId() == VENDOR_ID
                        && attached.getProductId() == PRODUCT_ID) {
                    log("检测到 CH343 重新插入：" + describe(attached));
                    if (mUsb != null && mUsb.hasPermission(attached)) {
                        mWorkerHandler.post(() -> openNow(attached));
                    } else {
                        state("需要 USB 授权", "点「连接」后在系统弹窗允许");
                    }
                }
                return;
            }
            if (!ACTION_PERMISSION.equals(action)) {
                return;
            }
            UsbDevice device = intent.getParcelableExtra(UsbManager.EXTRA_DEVICE);
            boolean granted = intent.getBooleanExtra(UsbManager.EXTRA_PERMISSION_GRANTED, false);
            if (device == null) {
                state("USB 授权失败", "系统没有带回设备信息");
                return;
            }
            if (!granted) {
                state("USB 授权被拒绝", "在系统弹窗里允许访问 CH343 后再试");
                return;
            }
            log("USB 授权已授予：" + describe(device));
            mWorkerHandler.post(() -> openNow(device));
        }
    };

    private ControlPort(Context context) {
        mContext = context.getApplicationContext();
        mUsb = (UsbManager) mContext.getSystemService(Context.USB_SERVICE);
        mWorker = new HandlerThread("control-port");
        mWorker.start();
        mWorkerHandler = new Handler(mWorker.getLooper());
        IntentFilter filter = new IntentFilter(ACTION_PERMISSION);
        filter.addAction(UsbManager.ACTION_USB_DEVICE_ATTACHED);
        filter.addAction(UsbManager.ACTION_USB_DEVICE_DETACHED);
        ContextCompat.registerReceiver(mContext, mPermissionReceiver, filter,
                ContextCompat.RECEIVER_EXPORTED);
    }

    public static synchronized ControlPort get(Context context) {
        if (sInstance == null) {
            sInstance = new ControlPort(context);
        }
        return sInstance;
    }

    // ------------------------------------------------------------------ state

    public void setListener(Listener listener) {
        mListener = listener;
        if (listener != null) {
            listener.onState(mStatus, mDetail);
        }
    }

    public boolean isOpen() {
        return mOpen;
    }

    public String deviceLabel() {
        return mDeviceLabel;
    }

    public int baud() {
        return mBaud;
    }

    public double lastRttMs() {
        return mLastRttMs;
    }

    /** SUMV mode bits actually used for the next trajectory. */
    public int mode() {
        return mMode;
    }

    public void setMode(int mode) {
        mMode = mode & 0xFF;
        log(String.format(Locale.US, "SUMV mode = 0x%02X（手颤 %s · 子运动 %s · 过冲 %s）",
                mMode, bit(mMode, 0x02), bit(mMode, 0x04), bit(mMode, 0x08)));
    }

    private static String bit(int mode, int mask) {
        return (mode & mask) != 0 ? "开" : "关";
    }

    public List<String> logLines() {
        synchronized (mLog) {
            return new ArrayList<>(mLog);
        }
    }

    // ------------------------------------------------------------------ connect

    /** Finds the control port, asks for USB permission if needed, then opens and handshakes. */
    public void connect() {
        mWorkerHandler.post(() -> {
            if (mOpen) {
                log("已经连上了");
                return;
            }
            UsbDevice device = findControlPort();
            if (device == null) {
                state("未发现控制口",
                        "把盒子的 CH343 控制口插到手机上（VID 1A86 / PID 55D3）。\n"
                                + "采集卡也占着 USB 口时需要一个 Hub。");
                log("probe: 没有 1A86:55D3 设备");
                return;
            }
            state("发现控制口", describe(device) + "，正在申请 USB 权限…");
            log("probe: " + describe(device));
            if (!mUsb.hasPermission(device)) {
                PendingIntent intent = PendingIntent.getBroadcast(mContext, 0,
                        new Intent(ACTION_PERMISSION).setPackage(mContext.getPackageName()),
                        PendingIntent.FLAG_MUTABLE);
                mUsb.requestPermission(device, intent);
                return;
            }
            openNow(device);
        });
    }

    private UsbDevice findControlPort() {
        for (UsbDevice device : mUsb.getDeviceList().values()) {
            if (device.getVendorId() == 0x1A86) {
                return device;
            }
        }
        return null;
    }

    private void openNow(UsbDevice device) {
        closeQuietly();
        mDevice = device;
        mTxFailures = 0;
        mRxFailures = 0;
        UsbDeviceConnection connection = mUsb.openDevice(device);
        if (connection == null) {
            state("打开失败", "UsbManager.openDevice() 返回 null（权限或系统占用）");
            return;
        }
        UsbInterface target = null;
        UsbEndpoint in = null;
        UsbEndpoint out = null;
        for (int i = 0; i < device.getInterfaceCount(); i++) {
            UsbInterface candidate = device.getInterface(i);
            UsbEndpoint candidateIn = null;
            UsbEndpoint candidateOut = null;
            for (int e = 0; e < candidate.getEndpointCount(); e++) {
                UsbEndpoint endpoint = candidate.getEndpoint(e);
                if (endpoint.getType() != UsbConstants.USB_ENDPOINT_XFER_BULK) {
                    continue;
                }
                if (endpoint.getDirection() == UsbConstants.USB_DIR_IN) {
                    candidateIn = endpoint;
                } else {
                    candidateOut = endpoint;
                }
            }
            if (candidateIn != null && candidateOut != null) {
                target = candidate;
                in = candidateIn;
                out = candidateOut;
                break;
            }
        }
        if (target == null) {
            log("设备里没有成对的 bulk 端点");
            connection.close();
            state("打开失败", "CH343 没有找到 bulk IN/OUT 端点");
            return;
        }
        if (!connection.claimInterface(target, true)) {
            log("claimInterface(" + target.getId() + ") 失败");
            connection.close();
            state("打开失败", "无法独占接口 " + target.getId());
            return;
        }
        mConnection = connection;
        mEpIn = in;
        mEpOut = out;
        mDeviceLabel = describe(device);
        mOpen = true;
        mLen = 0;
        mTxFrames = 0;
        mRxFrames = 0;
        log(String.format(Locale.US, "接口 %d · bulk IN 0x%02X / OUT 0x%02X",
                target.getId(), in.getAddress(), out.getAddress()));
        log("版本寄存器: " + version());

        startReader();
        state("控制口已打开", mDeviceLabel + "，正在握手…");

        int baud = handshake();
        if (baud <= 0) {
            state("握手失败",
                    "串口能打开，但 921600/115200 都没有收到 PING 回包。\n"
                            + "确认盒子已上电、控制口没有被 PC 占用，再点一次连接。");
            closeQuietly();
            return;
        }
        state("控制口就绪",
                mDeviceLabel + "\n" + baud + " 8N1 · PING "
                        + String.format(Locale.US, "%.2f ms", mLastRttMs));
    }

    /** Tries the documented rate first, then the pre-2026-11-10 one. */
    private int handshake() {
        for (int baud : BAUD_LADDER) {
            if (!setBaud(baud)) {
                continue;
            }
            log(baud + " 8N1 已配置，发 PING…");
            for (int attempt = 0; attempt < 3; attempt++) {
                if (ping(600)) {
                    mBaud = baud;
                    return baud;
                }
            }
            log(baud + " 无回包");
        }
        return 0;
    }

    public void disconnect() {
        mWorkerHandler.post(() -> {
            closeQuietly();
            state("控制口已断开", "");
        });
    }

    private void closeQuietly() {
        mOpen = false;
        mDevice = null;
        Thread reader = mReader;
        mReader = null;
        if (reader != null) {
            try {
                reader.join(300);
            } catch (InterruptedException ignored) {
                Thread.currentThread().interrupt();
            }
        }
        UsbDeviceConnection connection = mConnection;
        mConnection = null;
        mEpIn = null;
        mEpOut = null;
        if (connection != null) {
            try {
                connection.close();
            } catch (Throwable ignored) {
                // already closed
            }
        }
        mBaud = 0;
        mLastRttMs = -1;
        mDeviceLabel = "未连接";
    }

    // ------------------------------------------------------------------ CH343 configuration

    /**
     * Programs one line setting: wValue carries the LCR halves, wIndex the baud divisor and
     * prescaler exactly as WCH's {@code ch343_get()} derives them. Returns false when the
     * transfer failed or the baud rate cannot be expressed.
     */
    private boolean setBaud(int baud) {
        UsbDeviceConnection connection = mConnection;
        if (connection == null) {
            return false;
        }
        int[] factor = baudFactor(baud);
        if (factor == null) {
            log(baud + " 无法用 CH343 分频表示");
            return false;
        }
        int value = LCR_COUNT | (LCR_VALUE << 8);
        int index = (factor[0] << 8) | factor[1];
        int rc = connection.controlTransfer(REQ_VENDOR_OUT, CMD_LINE, value, index, null, 0,
                WRITE_TIMEOUT_MS);
        log(String.format(Locale.US, "0xA1 baud=%d value=0x%04X index=0x%04X rc=%d",
                baud, value, index, rc));
        if (rc < 0) {
            return false;
        }
        // DTR/RTS off: the port must not be reset when the app attaches.
        int control = connection.controlTransfer(REQ_VENDOR_OUT, CMD_CONTROL,
                ~(0) & 0xFFFF, 0, null, 0, WRITE_TIMEOUT_MS);
        if (control < 0) {
            log("0xA4 控制线设置失败 rc=" + control);
        }
        return true;
    }

    /** WCH's divisor/prescaler search for the generic CH343 (clock 6/12 MHz). */
    static int[] baudFactor(int baud) {
        int prescaler;
        int clock;
        switch (baud) {
            case 6000000:
            case 4000000:
            case 2400000:
            case 921600:
            case 307200:
            case 256000:
                prescaler = 7;
                clock = 12000000;
                break;
            default:
                if (baud > 6000000 / 255) {
                    prescaler = 3;
                    clock = 6000000;
                } else if (baud > 750000 / 255) {
                    prescaler = 2;
                    clock = 750000;
                } else if (baud > 93750 / 255) {
                    prescaler = 1;
                    clock = 93750;
                } else {
                    prescaler = 0;
                    clock = 11719;
                }
                break;
        }
        int divisor = clock / baud;
        if (divisor == 0 || divisor == 0xFF) {
            return null;
        }
        if ((clock / divisor - baud) > (baud - clock / (divisor + 1))) {
            divisor++;
        }
        divisor = 256 - divisor;
        return new int[]{divisor & 0xFF, prescaler};
    }

    private String version() {
        UsbDeviceConnection connection = mConnection;
        if (connection == null) {
            return "—";
        }
        byte[] buffer = new byte[2];
        int rc = connection.controlTransfer(REQ_VENDOR_IN, CMD_VERSION, 0, 0, buffer,
                buffer.length, WRITE_TIMEOUT_MS);
        if (rc != buffer.length) {
            return "读取失败 rc=" + rc;
        }
        return String.format(Locale.US, "%02X %02X", buffer[0] & 0xFF, buffer[1] & 0xFF);
    }

    // ------------------------------------------------------------------ frames

    /** Human-like relative motion: the device owns the pointer for the duration. */
    public void sumv(int dx, int dy, int speed) {
        sumv(dx, dy, speed, mMode, 0);
    }

    /** Human-like relative motion: the device owns the pointer for the duration. */
    public void sumv(int dx, int dy, int speed, int mode, int seed) {        byte[] payload = new byte[8];
        putShort(payload, 0, dx);
        putShort(payload, 2, dy);
        putShort(payload, 4, clampSpeed(speed));
        payload[6] = (byte) mode;
        payload[7] = (byte) seed;
        sendFrame(CMD_SUMV, payload);
        log(String.format(Locale.US, "→ SUMV dx=%d dy=%d speed=%d mode=0x%02X seed=%d",
                dx, dy, clampSpeed(speed), mode, seed));
    }

    /** Convenience for the direction buttons. */
    public void flick(int dx, int dy) {
        sumv(dx, dy, 800, mMode, 0);
    }

    /** Asks the box for its own counter block: the proof that a trajectory really executed. */
    public void querySumvState() {
        sendFrame(CMD_SUMV_STATE, new byte[0]);
        log("→ SUMV_STATE");
    }

    /** Public log hook for modules that want their events visible in the page log. */
    public void logNote(String line) {
        log(line);
    }

    public void setEvtListener(EvtListener listener) {
        mEvtListener = listener;
    }

    public void setAimStateListener(AimStateListener listener) {
        mAimStateListener = listener;
    }

    /** Latest {@code AIM_STATE}, or null before the first reply. */
    public AimState lastAimState() {
        return mLastAimState;
    }

    /** False means the box never answered {@code 0x3D}: firmware without the AIM entry. */
    public boolean sawAimState() {
        return mSawAimState;
    }

    /**
     * Aims in counts with a hard time budget (0x3C). The box runs a constant-velocity profile inside
     * {@code maxMs}, which is what makes a per-frame closed loop lag-free compared to SUMV ramps.
     *
     * @param maxMs  4..255 ms; 0 is treated as 8 by the firmware
     * @param flags  {@link #AIM_FLAG_SESSION_CLAMP} / {@link #AIM_FLAG_TURBO}
     * @param deadMin Chebyshev residual (counts) that already counts as "arrived"
     */
    public void aim(int dx, int dy, int maxMs, int flags, int deadMin) {
        sendFrame(CMD_AIM, aimPayload(dx, dy, maxMs, flags, deadMin));
    }

    /** {@code dx i16, dy i16, max_ms u8, flags u8, dead_min u8} — length-gated on the firmware. */
    static byte[] aimPayload(int dx, int dy, int maxMs, int flags, int deadMin) {
        byte[] payload = new byte[7];
        putShort(payload, 0, dx);
        putShort(payload, 2, dy);
        payload[4] = (byte) Math.max(0, Math.min(255, maxMs));
        payload[5] = (byte) (flags & 0xFF);
        payload[6] = (byte) Math.max(1, Math.min(255, deadMin));
        return payload;
    }

    public void aimState() {
        sendFrame(CMD_AIM_STATE, new byte[0]);
    }

    /** Button-priority counters: proves the box sends every key report first. */
    public static final class HidStat {
        public final int btnIn;
        public final int btnSent;
        public final int waitMaxUs;
        public final int overflow;
        /** 1 秒内按键字节变化 > 50 次的窗口数（0 = 没有洪泛）。 */
        public final int flood;
        /** 5 ms 内同值重复被合并 / 反向成对被抵消的次数。 */
        public final int merged;
        public final int cancel;

        HidStat(int btnIn, int btnSent, int waitMaxUs, int overflow, int flood,
                int merged, int cancel) {
            this.btnIn = btnIn;
            this.btnSent = btnSent;
            this.waitMaxUs = waitMaxUs;
            this.overflow = overflow;
            this.flood = flood;
            this.merged = merged;
            this.cancel = cancel;
        }
    }

    public void hidStat() {
        sendFrame(CMD_HID_STAT, new byte[0]);
    }

    public HidStat lastHidStat() {
        return mLastHidStat;
    }

    /** Button loop audit (0x3F): request count vs emitted reports vs unexplained extras. */
    public static final class BtnAudit {
        public final int inChg;
        public final int outChg;
        public final int extra;

        BtnAudit(int inChg, int outChg, int extra) {
            this.inChg = inChg;
            this.outChg = outChg;
            this.extra = extra;
        }

        /** Healthy when every requested change was emitted once and nothing appeared by itself. */
        public boolean healthy() {
            return extra == 0 && outChg >= inChg;
        }
    }

    public void btnAudit() {
        sendFrame(CMD_BTN_AUDIT, new byte[0]);
    }

    /** Resets the AIM_STATE counters so a latched result or saturated counter cannot persist. */
    public void aimReset() {
        sendFrame(CMD_AIM_RESET, new byte[0]);
    }

    public void evtReset() {
        sendFrame(CMD_EVT_RESET, new byte[0]);
    }

    /** 上一条真正发给主机的 HID 报告（诊断"按键字节到底是多少"）。 */
    public static final class LastHid {
        public final int reportId;
        public final int length;
        public final byte[] bytes;
        /** 最近 8 条上线报告的按键字节（最新在最后；老固件为空）。 */
        public final byte[] history;

        LastHid(int reportId, int length, byte[] bytes, byte[] history) {
            this.reportId = reportId;
            this.length = length;
            this.bytes = bytes;
            this.history = history;
        }

        /** First byte of the report is the button bitmap for the usual mouse layouts. */
        public int buttons() {
            return bytes.length > 0 ? (bytes[0] & 0x1F) : 0;
        }

        public String describe() {
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < length && i < bytes.length; i++) {
                sb.append(String.format(Locale.US, "%02X ", bytes[i]));
            }
            return String.format(Locale.US, "id=%d len=%d 按钮=0x%02X [%s]",
                    reportId, length, buttons(), sb.toString().trim());
        }
    }

    public void lastHid() {
        sendFrame(CMD_LAST_HID, new byte[0]);
    }

    public LastHid lastHidReport() {
        return mLastHid;
    }

    /** 记录（固件侧环形日志的一条）。 */
    public static final class BtnTrace {
        public final int timeUs;
        public final int raw;
        public final int forwarded;
        public final int source;

        BtnTrace(int timeUs, int raw, int forwarded, int source) {
            this.timeUs = timeUs;
            this.raw = raw;
            this.forwarded = forwarded;
            this.source = source;
        }

        public String describe() {
            String src;
            switch (source) {
                case 0: src = "透传"; break;
                case 1: src = "被抗抖吞掉"; break;
                case 2: src = "瞄准期屏蔽层"; break;
                case 3: src = "注入"; break;
                default: src = "未知" + source; break;
            }
            return String.format(Locale.US, "t=%.1fms 原始=0x%02X 转发=0x%02X %s",
                    timeUs / 1000f, raw, forwarded, src);
        }
    }

    public int lastBtnLogTotal() {
        return mLastBtnLogTotal;
    }

    public void btnLog(int since) {
        sendFrame(CMD_BTN_LOG, new byte[]{(byte) (since & 0xFF), (byte) ((since >> 8) & 0xFF)});
    }

    public BtnAudit lastBtnAudit() {
        return mLastBtnAudit;
    }

    /**
     * Forces one HID report with this button bitmap (0x32). The box emits it immediately, which is
     * the only way to clear a button the PC still believes is held.
     */
    public void button(int mask) {
        sendFrame(CMD_BUTTON, new byte[]{(byte) (mask & 0x1F)});
    }

    /** @param mask button bitmap to force; 0 releases everything */
    public void buttonRelease(String why) {
        button(0);
        log("→ BUTTON 0x00（" + why + "）");
    }

    /** Stops a running trajectory in place (0x37). Sent on aim release and on target loss. */
    public void sumvStop() {
        sendFrame(CMD_SUMV_STOP, new byte[0]);
        log("→ SUMV_STOP");
    }

    /**
     * Subscribes buttons (0x39). {@code push} asks for unsolicited 0xE1 frames; {@code consume}
     * decides whether the PC still sees the click - the box defaults to pass-through, so a hotkey
     * MUST pass consume=true or the click lands in whatever has focus.
     */
    public void evtSubscribe(int mask, boolean push, boolean consume) {
        byte[] payload = new byte[]{(byte) (mask != 0 ? 1 : 0), (byte) (mask & 0x1F),
                (byte) (push ? 1 : 0), (byte) (consume ? 1 : 0)};
        sendFrame(CMD_EVT_CTL, payload);
        log(String.format(Locale.US, "→ EVT_CTL enable=%d mask=0x%02X push=%d consume=%d",
                mask != 0 ? 1 : 0, mask & 0x1F, push ? 1 : 0, consume ? 1 : 0));
    }

    /** Event-ring status; doubles as the 1 Hz heartbeat the subscription needs to stay alive. */
    public void evtStat() {
        sendFrame(CMD_EVT_STAT, new byte[0]);
    }

    public boolean ping() {
        return ping(400);
    }

    /** One PING round trip; returns whether a matching reply arrived in time. */
    public boolean ping(int timeoutMs) {
        if (!mOpen) {
            log("串口未连接，PING 跳过");
            return false;
        }
        int counter = (int) (SystemClock.elapsedRealtimeNanos() & 0x7FFFFFFF);
        byte[] payload = new byte[4];
        putInt(payload, 0, counter);
        mLastRttMs = -1;
        mPingSentNanos = System.nanoTime();
        sendFrame(CMD_PING, payload);
        long deadline = SystemClock.elapsedRealtime() + timeoutMs;
        while (SystemClock.elapsedRealtime() < deadline) {
            if (mLastRttMs >= 0) {
                return true;
            }
            try {
                Thread.sleep(5);
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
                return false;
            }
        }
        return false;
    }

    private void sendFrame(int cmd, byte[] payload) {
        byte[] frame = buildFrame(cmd, payload);
        UsbDeviceConnection connection = mConnection;
        UsbEndpoint endpoint = mEpOut;
        if (connection == null || endpoint == null || !mOpen) {
            log("串口未连接，帧丢弃（cmd=0x" + Integer.toHexString(cmd) + "）");
            return;
        }
        try {
            synchronized (mWriteLock) {
                int offset = 0;
                while (offset < frame.length) {
                    int written = connection.bulkTransfer(endpoint, offset == 0 ? frame
                                    : slice(frame, offset), frame.length - offset, WRITE_TIMEOUT_MS);
                    if (written <= 0) {
                        throw new IllegalStateException("bulkTransfer 返回 " + written);
                    }
                    offset += written;
                }
            }
            mTxFrames++;
            mTxFailures = 0;
        } catch (Throwable t) {
            if (connection != mConnection) {
                return; // 这条连接已经被替换掉，失败无关紧要
            }
            log("写失败: " + t);
            if (++mTxFailures >= FAILURE_LIMIT) {
                handleLinkLost("写入连续失败：" + t.getMessage());
            } else {
                state("写入失败", String.valueOf(t));
            }
        }
    }

    /**
     * 判定链路已断：设备被拔掉或重新枚举后，旧连接上的 bulkTransfer 会一直返回 -1。
     * 这里关掉连接并通知 UI，等 ACTION_USB_DEVICE_ATTACHED 或用户点「连接」再恢复。
     */
    private void handleLinkLost(String why) {
        if (!mOpen && mConnection == null) {
            return;
        }
        mOpen = false;
        mTxFailures = 0;
        mRxFailures = 0;
        mDevice = null;
        mWorkerHandler.removeCallbacksAndMessages(null);
        try {
            UsbDeviceConnection connection = mConnection;
            mConnection = null;
            if (connection != null) {
                connection.close();
            }
        } catch (Throwable ignored) {
            // closing a dead connection can throw; nothing to do
        }
        log("链路已断开：" + why);
        state("连接已断开", why + " · 请重新插入或点「连接」");
    }

    private static byte[] slice(byte[] src, int offset) {
        byte[] out = new byte[src.length - offset];
        System.arraycopy(src, offset, out, 0, out.length);
        return out;
    }

    private byte[] buildFrame(int cmd, byte[] payload) {
        return frameFor(cmd, mSeq++, payload);
    }

    /** Frame builder without the sequence counter; also used by the unit tests. */
    static byte[] frameFor(int cmd, int seq, byte[] payload) {
        int len = payload == null ? 0 : payload.length;
        byte[] body = new byte[4 + len];
        body[0] = (byte) cmd;
        body[1] = (byte) (seq & 0xFF);
        body[2] = (byte) (len & 0xFF);
        body[3] = (byte) ((len >> 8) & 0xFF);
        if (len > 0) {
            System.arraycopy(payload, 0, body, 4, len);
        }
        byte[] frame = new byte[1 + body.length + 1];
        frame[0] = 0x5A;
        System.arraycopy(body, 0, frame, 1, body.length);
        frame[frame.length - 1] = (byte) crc8(body, 0, body.length);
        return frame;
    }

    static int crc8(byte[] data, int offset, int length) {
        int crc = 0;
        for (int i = 0; i < length; i++) {
            crc ^= data[offset + i] & 0xFF;
            for (int bit = 0; bit < 8; bit++) {
                crc = (crc & 0x80) != 0 ? ((crc << 1) ^ 0x07) & 0xFF : (crc << 1) & 0xFF;
            }
        }
        return crc;
    }

    // ------------------------------------------------------------------ reader

    private void startReader() {
        Thread thread = new Thread(this::readLoop, "control-port-rx");
        thread.setDaemon(true);
        mReader = thread;
        thread.start();
    }

    private void readLoop() {
        byte[] chunk = new byte[512];
        while (mOpen) {
            UsbDeviceConnection connection = mConnection;
            UsbEndpoint endpoint = mEpIn;
            if (connection == null || endpoint == null) {
                break;
            }
            int read = connection.bulkTransfer(endpoint, chunk, chunk.length, READ_TIMEOUT_MS);
            if (connection != mConnection) {
                break; // 连接已被替换（重连/断开），本线程退休
            }
            if (read > 0) {
                append(chunk, read);
            }
            // read <= 0：注意 Android 的 bulkTransfer 把"超时"和"出错"都返回 -1，
            // 空闲时必然一直 -1，所以读侧不能据此判定断链，只靠写失败次数与拔插广播。
        }
        Log.i(TAG, "reader stopped");
    }

    /** Appends to the parse buffer and drains every complete frame. */
    private void append(byte[] data, int count) {
        synchronized (mBuf) {
            if (mLen + count > mBuf.length) {
                mLen = 0; // a runaway text line: start over rather than overflow
            }
            System.arraycopy(data, 0, mBuf, mLen, count);
            mLen += count;
            int pos = 0;
            while (pos < mLen) {
                if ((mBuf[pos] & 0xFF) != 0x5A) {
                    pos++;
                    continue;
                }
                if (mLen - pos < 5) {
                    break;
                }
                int len = (mBuf[pos + 3] & 0xFF) | ((mBuf[pos + 4] & 0xFF) << 8);
                if (len > MAX_PAYLOAD) {
                    pos++;
                    continue;
                }
                int need = 5 + len + 1;
                if (mLen - pos < need) {
                    break;
                }
                int crc = crc8(mBuf, pos + 1, 4 + len);
                if (crc != (mBuf[pos + need - 1] & 0xFF)) {
                    log("CRC 错帧，丢弃（cmd=0x"
                            + Integer.toHexString(mBuf[pos + 1] & 0xFF) + "）");
                    pos++;
                    continue;
                }
                int cmd = mBuf[pos + 1] & 0xFF;
                int seq = mBuf[pos + 2] & 0xFF;
                byte[] payload = new byte[len];
                System.arraycopy(mBuf, pos + 5, payload, 0, len);
                pos += need;
                mRxFrames++;
                dispatch(cmd, seq, payload);
            }
            if (pos > 0) {
                System.arraycopy(mBuf, pos, mBuf, 0, mLen - pos);
                mLen -= pos;
            }
        }
    }

    private void dispatch(int cmd, int seq, byte[] payload) {
        if (cmd == (CMD_PING | 0x80)) {
            double rtt = (System.nanoTime() - mPingSentNanos) / 1e6;
            mLastRttMs = rtt;
            String extra = payload.length >= 12
                    ? String.format(Locale.US, " clock_us=%d plans=%d last_seq=%d",
                    readInt(payload, 4), readShort(payload, 8), payload[10] & 0xFF)
                    : "";
            log(String.format(Locale.US, "← PING seq=%d %.2f ms%s", seq, rtt, extra));
            return;
        }
        if (cmd == CMD_EVT_PUSH) {
            if (payload.length >= 8) {
                int mask = payload[6] & 0xFF;
                int edge = payload[7] & 0xFF;
                log(String.format(Locale.US, "← EVT_PUSH seq=%d mask=0x%02X edge=0x%02X",
                        readShort(payload, 4), mask, edge));
                EvtListener listener = mEvtListener;
                if (listener != null) {
                    listener.onEvt(mask, edge);
                }
            }
            return;
        }
        if (cmd >= 0xE0 && cmd <= 0xEF) {
            log("← 事件帧 cmd=0x" + Integer.toHexString(cmd) + " " + hex(payload));
            return;
        }
        if (cmd == (CMD_EVT_STAT | 0x80) && payload.length >= 12) {
            int nextSeq = readShort(payload, 0);
            int pending = payload[2] & 0xFF;
            int overflow = readInt(payload, 3);
            int mask = payload[7] & 0xFF;
            int pendingBits = payload[8] & 0xFF;
            int cur = payload[9] & 0xFF;
            int lastFwd = payload[10] & 0xFF;
            int flags = payload[11] & 0xFF;
            if (mAutoRelease && cur == 0) {
                // Safety net: the box can park in "left button still down" when a release lands
                // inside an aim window (firmware copies the button byte into every injected
                // report). cur == 0 means the real mouse holds nothing, so forcing a release
                // report cannot cut a real click short.
                buttonRelease("安全释放：真实鼠标无按键，PC 可能卡在按下");
            }
            log(String.format(Locale.US,
                    "← EVT_STAT next=%d pending=%d overflow=%d mask=0x%02X pendBits=0x%02X "
                            + "cur=0x%02X last_fwd=0x%02X flags=0x%02X",
                    nextSeq, pending, overflow, mask, pendingBits, cur, lastFwd, flags));
            EvtListener listener = mEvtListener;
            if (listener != null) {
                listener.onEvtStat(lastFwd, flags, mask, cur);
            }
            return;
        }
        if (cmd == (CMD_SUMV_STATE | 0x80) && payload.length >= 29) {
            log(String.format(Locale.US,
                    "← SUMV_STATE running=%d samples=%d aborted=%d rounds=%d muted=%d "
                            + "forwarded=%d speed_eff=%d remain_ms=%d",
                    payload[0] & 0xFF, readInt(payload, 1), readInt(payload, 5),
                    readInt(payload, 9), readInt(payload, 13), readInt(payload, 17),
                    readInt(payload, 21), readInt(payload, 25)));
            return;
        }
        if (cmd == (CMD_AIM_STATE | 0x80) && payload.length >= 12) {
            AimState state = new AimState(payload[0] & 0xFF, payload[1] & 0xFF,
                    readShort(payload, 2), readShort(payload, 4), readShort(payload, 6),
                    readShort(payload, 8), payload[10] & 0xFF, payload[11] & 0xFF);
            mLastAimState = state;
            mSawAimState = true;
            log(String.format(Locale.US,
                    "← AIM_STATE active=%d result=%d(%s) counts=%d dur=%dms aborted=%d "
                            + "rounds=%d dead=%d gen=%d",
                    state.active, state.lastResult, AimState.resultText(state.lastResult),
                    state.lastCounts, state.lastDurMs, state.aborted, state.rounds,
                    state.deadHits, state.gen));
            AimStateListener listener = mAimStateListener;
            if (listener != null) {
                listener.onAimState(state);
            }
            return;
        }
        if (cmd == (CMD_BTN_LOG | 0x80) && payload.length >= 3) {
            int total = readShort(payload, 0);
            int count = payload[2] & 0xFF;
            mLastBtnLogTotal = total;
            log(String.format(Locale.US, "← BTN_LOG total=%d count=%d", total, count));
            for (int i = 0; i < count && 3 + (i + 1) * 8 <= payload.length; i++) {
                int off = 3 + i * 8;
                BtnTrace e = new BtnTrace(readInt(payload, off),
                        payload[off + 4] & 0xFF, payload[off + 5] & 0xFF, payload[off + 6] & 0xFF);
                log("   · " + e.describe());
            }
            return;
        }
        if (cmd == (CMD_LAST_HID | 0x80) && payload.length >= 10) {
            byte[] bytes = new byte[8];
            System.arraycopy(payload, 2, bytes, 0, Math.min(8, payload.length - 2));
            byte[] hist = new byte[0];
            if (payload.length >= 18) {
                hist = new byte[8];
                System.arraycopy(payload, 10, hist, 0, 8);
            }
            LastHid last = new LastHid(payload[0] & 0xFF, payload[1] & 0xFF, bytes, hist);
            mLastHid = last;
            log("← LAST_HID " + last.describe());
            return;
        }
        if (cmd == (CMD_BTN_AUDIT | 0x80) && payload.length >= 12) {
            BtnAudit audit = new BtnAudit(readInt(payload, 0), readInt(payload, 4), readInt(payload, 8));
            mLastBtnAudit = audit;
            log(String.format(Locale.US, "← BTN_AUDIT in_chg=%d out_chg=%d extra=%d（%s）",
                    audit.inChg, audit.outChg, audit.extra, audit.healthy() ? "正常" : "异常"));
            return;
        }
        if (cmd == (CMD_HID_STAT | 0x80) && payload.length >= 8) {
            // 10 字节 = 旧 8 字节 + flood（老固件只回 8 字节，flood 记 0）
            HidStat stat = new HidStat(readShort(payload, 0), readShort(payload, 2),
                    readShort(payload, 4), readShort(payload, 6),
                    payload.length >= 10 ? readShort(payload, 8) : 0,
                    payload.length >= 14 ? readShort(payload, 10) : 0,
                    payload.length >= 14 ? readShort(payload, 12) : 0);
            mLastHidStat = stat;
            log(String.format(Locale.US,
                    "← HID_STAT 按键 in=%d sent=%d wait_max=%dus 队列溢出=%d",
                    stat.btnIn, stat.btnSent, stat.waitMaxUs, stat.overflow));
            return;
        }
        log("← 回包 cmd=0x" + Integer.toHexString(cmd) + " seq=" + seq + " len="
                + payload.length + " " + hex(payload));
    }

    // ------------------------------------------------------------------ helpers

    private void state(String status, String detail) {
        mStatus = status;
        mDetail = detail;
        mMain.post(() -> {
            Listener listener = mListener;
            if (listener != null) {
                listener.onState(status, detail);
            }
        });
    }

    private void log(String line) {
        Log.i(TAG, line);
        appendLogFile(line);
        synchronized (mLog) {
            mLog.add(line);
            while (mLog.size() > 200) {
                mLog.remove(0);
            }
        }
        mMain.post(() -> {
            Listener listener = mListener;
            if (listener != null) {
                listener.onLog(line);
            }
        });
    }

    private void appendLogFile(String line) {
        try {
            java.io.File file = new java.io.File(mContext.getCacheDir(), "control.log");
            if (file.length() > LOG_MAX_BYTES) {
                //noinspection ResultOfMethodCallIgnored
                file.delete();
            }
            try (java.io.FileWriter writer = new java.io.FileWriter(file, true)) {
                writer.write(line + "\n");
            }
        } catch (Throwable ignored) {
            // diagnostics only
        }
    }

    private static int clampSpeed(int speed) {
        // 2026-11-11: the firmware clamps to [50, 65535] and derives the per-report cap from speed.
        return Math.max(50, Math.min(65535, speed <= 0 ? DEFAULT_SPEED : speed));
    }

    private static String describe(UsbDevice device) {
        String name;
        try {
            name = device.getProductName();
        } catch (Throwable t) {
            name = null;
        }
        if (name == null || name.isEmpty()) {
            name = device.getDeviceName();
        }
        return String.format(Locale.US, "%s (VID:%04X PID:%04X)",
                name, device.getVendorId(), device.getProductId());
    }

    private static String hex(byte[] data) {
        if (data.length == 0) {
            return "";
        }
        StringBuilder sb = new StringBuilder(data.length * 3);
        for (byte b : data) {
            sb.append(String.format(Locale.US, "%02X ", b));
        }
        return sb.toString().trim();
    }

    private static void putShort(byte[] dst, int offset, int value) {
        dst[offset] = (byte) (value & 0xFF);
        dst[offset + 1] = (byte) ((value >> 8) & 0xFF);
    }

    private static void putInt(byte[] dst, int offset, int value) {
        dst[offset] = (byte) (value & 0xFF);
        dst[offset + 1] = (byte) ((value >> 8) & 0xFF);
        dst[offset + 2] = (byte) ((value >> 16) & 0xFF);
        dst[offset + 3] = (byte) ((value >> 24) & 0xFF);
    }

    private static int readInt(byte[] src, int offset) {
        if (src.length < offset + 4) {
            return 0;
        }
        return (src[offset] & 0xFF) | ((src[offset + 1] & 0xFF) << 8)
                | ((src[offset + 2] & 0xFF) << 16) | ((src[offset + 3] & 0xFF) << 24);
    }

    private static int readShort(byte[] src, int offset) {
        if (src.length < offset + 2) {
            return 0;
        }
        return (src[offset] & 0xFF) | ((src[offset + 1] & 0xFF) << 8);
    }
}
