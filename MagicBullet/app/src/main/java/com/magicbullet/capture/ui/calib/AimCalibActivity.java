package com.magicbullet.capture.ui.calib;

import android.app.Activity;
import android.content.pm.ActivityInfo;
import android.graphics.Bitmap;
import android.os.Bundle;
import android.os.Handler;
import android.os.Looper;
import android.view.View;
import android.view.WindowManager;
import android.widget.TextView;

import com.magicbullet.capture.R;
import com.magicbullet.capture.core.AimConfig;
import com.magicbullet.capture.core.AimRect;
import com.magicbullet.capture.core.FrameSnapshot;
import com.magicbullet.capture.widget.CalibView;

import java.util.Locale;

/**
 * Full-screen landscape crosshair calibration.
 *
 * <p>Portrait preview can only place the aim rectangle to within a few pixels, which is too coarse
 * when the goal is "put the rectangle centre exactly on the game's crosshair". This screen freezes
 * one frame, lets the user pinch to 12x, drag the box with eight handles, nudge by single frame
 * pixels and read the result in a loupe, then writes the rectangle back to {@link AimConfig}.
 */
public class AimCalibActivity extends Activity implements CalibView.Listener {

    private static final long GRAB_TIMEOUT_MS = 2500L;
    private static final long GRAB_POLL_MS = 100L;

    private CalibView mView;
    private TextView mInfo;
    private TextView mHint;
    private AimConfig mConfig;
    private final Handler mMain = new Handler(Looper.getMainLooper());
    private long mGrabStartMs;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setRequestedOrientation(ActivityInfo.SCREEN_ORIENTATION_SENSOR_LANDSCAPE);
        getWindow().addFlags(WindowManager.LayoutParams.FLAG_KEEP_SCREEN_ON);
        setContentView(R.layout.activity_aim_calib);
        mConfig = AimConfig.load(this);
        mView = findViewById(R.id.calib_view);
        mInfo = findViewById(R.id.calib_info);
        mHint = findViewById(R.id.calib_hint);
        mView.setListener(this);
        mView.setRect(mConfig.rect());

        findViewById(R.id.calib_save).setOnClickListener(v -> save());
        findViewById(R.id.calib_cancel).setOnClickListener(v -> finish());
        findViewById(R.id.calib_centre).setOnClickListener(v -> mView.centreRect());
        findViewById(R.id.calib_zoom_1).setOnClickListener(v -> mView.setZoom(1f));
        findViewById(R.id.calib_zoom_2).setOnClickListener(v -> mView.setZoom(2f));
        findViewById(R.id.calib_zoom_4).setOnClickListener(v -> mView.setZoom(4f));
        findViewById(R.id.calib_zoom_8).setOnClickListener(v -> mView.setZoom(8f));
        findViewById(R.id.calib_up).setOnClickListener(v -> mView.nudge(0, -1));
        findViewById(R.id.calib_down).setOnClickListener(v -> mView.nudge(0, 1));
        findViewById(R.id.calib_left).setOnClickListener(v -> mView.nudge(-1, 0));
        findViewById(R.id.calib_right).setOnClickListener(v -> mView.nudge(1, 0));
        findViewById(R.id.calib_grid).setOnClickListener(v -> {
            mView.setShowGrid(!gridOn);
            gridOn = !gridOn;
        });
        findViewById(R.id.calib_loupe).setOnClickListener(v -> {
            mView.setShowLoupe(!loupeOn);
            loupeOn = !loupeOn;
        });
        renderInfo();
    }

    private boolean gridOn = true;
    private boolean loupeOn = true;

    @Override
    protected void onResume() {
        super.onResume();
        hideSystemUi();
        Bitmap ready = FrameSnapshot.bitmap();
        if (ready != null) {
            // 入口已经抓好了冻结帧（相机在预览页 onPause 后会停，必须提前抓）
            mView.setBitmap(ready);
            mView.setRect(mConfig.rect());
            mHint.setText(String.format(Locale.US, "%d × %d · 冻结帧",
                    FrameSnapshot.width(), FrameSnapshot.height()));
            renderInfo();
            return;
        }
        // 兜底：流还在跑的话自己抓一张
        FrameSnapshot.request();
        mGrabStartMs = System.currentTimeMillis();
        mHint.setText(R.string.calib_grabbing);
        mMain.postDelayed(mGrabPoll, GRAB_POLL_MS);
    }

    @Override
    protected void onPause() {
        super.onPause();
        mMain.removeCallbacks(mGrabPoll);
    }

    private final Runnable mGrabPoll = new Runnable() {
        @Override
        public void run() {
            Bitmap bitmap = FrameSnapshot.bitmap();
            if (bitmap != null) {
                mView.setBitmap(bitmap);
                mView.setRect(mConfig.rect());
                mHint.setText(String.format(Locale.US, "%d × %d · 冻结帧",
                        FrameSnapshot.width(), FrameSnapshot.height()));
                renderInfo();
                return;
            }
            if (System.currentTimeMillis() - mGrabStartMs > GRAB_TIMEOUT_MS) {
                mHint.setText(R.string.calib_grab_failed);
                // Still usable: the rectangle can be dragged on a blank canvas.
                return;
            }
            mMain.postDelayed(this, GRAB_POLL_MS);
        }
    };

    private void hideSystemUi() {
        View decor = getWindow().getDecorView();
        decor.setSystemUiVisibility(View.SYSTEM_UI_FLAG_IMMERSIVE_STICKY
                | View.SYSTEM_UI_FLAG_FULLSCREEN
                | View.SYSTEM_UI_FLAG_HIDE_NAVIGATION
                | View.SYSTEM_UI_FLAG_LAYOUT_STABLE);
    }

    private void save() {
        AimRect rect = mView.getRect();
        mConfig.rect(rect);
        // save() = persist + 通知监听者（预览页/瞄准页）。之前只 persist()，
        // 预览页拿不到通知，所以保存后要切页才看到新框。
        mConfig.save();
        setResult(RESULT_OK);
        finish();
    }

    @Override
    public void onAimRectChanged(AimRect rect) {
        renderInfo();
    }

    @Override
    public void onViewChanged(float zoom) {
        renderInfo();
    }

    private void renderInfo() {
        AimRect rect = mView.getRect();
        int frameW = FrameSnapshot.width();
        int frameH = FrameSnapshot.height();
        if (frameW <= 0 || frameH <= 0) {
            frameW = 1920;
            frameH = 1080;
        }
        int[] b = rect.boundsPx(frameW, frameH);
        mInfo.setText(String.format(Locale.US,
                "框 %d×%d px · 中心 (%d, %d) · 缩放 %.1f×",
                b[2], b[3], Math.round(rect.anchorX(frameW)), Math.round(rect.anchorY(frameH)),
                mView.zoom()));
    }
}
