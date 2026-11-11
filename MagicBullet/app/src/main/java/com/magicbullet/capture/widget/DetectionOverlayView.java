package com.magicbullet.capture.widget;

import android.content.Context;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.graphics.RectF;
import android.util.AttributeSet;
import android.view.View;

import androidx.annotation.Nullable;

import com.magicbullet.capture.core.Detection;

import java.util.Collections;
import java.util.List;
import java.util.Locale;

/**
 * Draws detection boxes on top of the preview SurfaceView.
 *
 * <p>Requires {@code SurfaceView#setZOrderMediaOverlay(true)} on the preview, otherwise
 * the surface is composited above the window and would cover this view.
 */
public class DetectionOverlayView extends View {

    private static final int COLOR_PERSON = 0xFF4C8DFF;
    private static final int COLOR_VEHICLE = 0xFF3FB950;
    private static final int COLOR_ANIMAL = 0xFFD29922;
    private static final int COLOR_OTHER = 0xFFF85149;

    private final Paint mBoxPaint = new Paint(Paint.ANTI_ALIAS_FLAG);
    private final Paint mTextPaint = new Paint(Paint.ANTI_ALIAS_FLAG);
    private final Paint mLabelBgPaint = new Paint(Paint.ANTI_ALIAS_FLAG);
    private final RectF mRect = new RectF();

    private List<Detection> mDetections = Collections.emptyList();
    private String mStats = "";

    private final Paint mAimPaint = new Paint(Paint.ANTI_ALIAS_FLAG);
    private final Paint mPredPaint = new Paint(Paint.ANTI_ALIAS_FLAG);
    private final RectF mAimBox = new RectF();
    private boolean mHasAim;
    private boolean mAiming;
    private boolean mShowPredicted = true;
    private float mPredX;
    private float mPredY;

    /** Predicted point in normalised coordinates is only shown while aiming. */
    public void clearAim() {
        mHasAim = false;
        mAiming = false;
        invalidate();
    }

    public DetectionOverlayView(Context context) {
        this(context, null);
    }

    public DetectionOverlayView(Context context, @Nullable AttributeSet attrs) {
        super(context, attrs);
        float density = getResources().getDisplayMetrics().density;
        mBoxPaint.setStyle(Paint.Style.STROKE);
        mBoxPaint.setStrokeWidth(2.5f * density);
        mTextPaint.setTextSize(11f * density);
        mTextPaint.setColor(Color.WHITE);
        mLabelBgPaint.setStyle(Paint.Style.FILL);
        mLabelBgPaint.setColor(0xCC000000);
        float density2 = getResources().getDisplayMetrics().density;
        mAimPaint.setStyle(Paint.Style.STROKE);
        mAimPaint.setStrokeWidth(3f * density2);
        mAimPaint.setColor(0xFFFF9F0A);
        mPredPaint.setStyle(Paint.Style.STROKE);
        mPredPaint.setStrokeWidth(1.5f * density2);
        mPredPaint.setColor(0xFF8CE1FF);
        mPredPaint.setPathEffect(
                new android.graphics.DashPathEffect(new float[]{6f * density2, 4f * density2}, 0));
    }

    public void setDetections(List<Detection> detections, String stats) {
        mDetections = detections != null ? detections : Collections.emptyList();
        mStats = stats != null ? stats : "";
        invalidate();
    }

    /**
     * The target the aim loop is currently working on, plus where feed-forward predicts it will be
     * after the pipeline latency. Coordinates are normalised to the frame.
     */
    public void setAimTarget(boolean aiming, boolean hasTarget, float left, float top,
                             float right, float bottom, float predictedX, float predictedY,
                             boolean showPredicted) {
        mAiming = aiming;
        mHasAim = hasTarget;
        mAimBox.set(left, top, right, bottom);
        mPredX = predictedX;
        mPredY = predictedY;
        mShowPredicted = showPredicted;
        invalidate();
    }

    @Override
    protected void onDraw(Canvas canvas) {
        super.onDraw(canvas);
        int width = getWidth();
        int height = getHeight();

        for (Detection detection : mDetections) {
            mBoxPaint.setColor(colorOf(detection.label));
            mRect.set(detection.left * width, detection.top * height,
                    detection.right * width, detection.bottom * height);
            canvas.drawRect(mRect, mBoxPaint);
            drawLabel(canvas, detection, mRect);
        }

        if (!mStats.isEmpty()) {
            drawStats(canvas);
        }
        if (mAiming) {
            drawAim(canvas, width, height);
        }
    }

    /** Highlighted lock box, plus the feed-forward prediction point when enabled. */
    private void drawAim(Canvas canvas, int width, int height) {
        if (!mHasAim) {
            return;
        }
        mRect.set(mAimBox.left * width, mAimBox.top * height,
                mAimBox.right * width, mAimBox.bottom * height);
        canvas.drawRect(mRect, mAimPaint);
        if (!mShowPredicted) {
            return;
        }
        float px = mPredX * width;
        float py = mPredY * height;
        float density = getResources().getDisplayMetrics().density;
        float arm = 8f * density;
        canvas.drawLine(px - arm, py, px + arm, py, mPredPaint);
        canvas.drawLine(px, py - arm, px, py + arm, mPredPaint);
        canvas.drawCircle(px, py, 3f * density, mPredPaint);
    }

    private void drawLabel(Canvas canvas, Detection detection, RectF box) {
        String text = detection.label.isEmpty()
                ? String.format(Locale.US, "%.2f", detection.score)
                : String.format(Locale.US, "%s %.2f", detection.label, detection.score);
        float textWidth = mTextPaint.measureText(text);
        float textHeight = mTextPaint.getTextSize();
        float left = box.left;
        float top = Math.max(0f, box.top - textHeight - 4f);

        canvas.drawRect(left, top, left + textWidth + 8f, top + textHeight + 4f, mLabelBgPaint);
        canvas.drawText(text, left + 4f, top + textHeight, mTextPaint);
    }

    private void drawStats(Canvas canvas) {
        float density = getResources().getDisplayMetrics().density;
        float pad = 8f * density;
        float textWidth = mTextPaint.measureText(mStats);
        float textHeight = mTextPaint.getTextSize();
        canvas.drawRect(pad, pad, pad + textWidth + 10f, pad + textHeight + 8f, mLabelBgPaint);
        canvas.drawText(mStats, pad + 5f, pad + textHeight + 1f, mTextPaint);
    }

    private static int colorOf(String label) {
        if ("person".equals(label)) {
            return COLOR_PERSON;
        }
        if ("vehicle".equals(label)) {
            return COLOR_VEHICLE;
        }
        if ("animal".equals(label)) {
            return COLOR_ANIMAL;
        }
        return COLOR_OTHER;
    }
}
