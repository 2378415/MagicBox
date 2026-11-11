package com.magicbullet.capture.widget;

import android.content.Context;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.DashPathEffect;
import android.graphics.Paint;
import android.graphics.RectF;
import android.util.AttributeSet;
import android.view.MotionEvent;
import android.view.View;

import androidx.annotation.Nullable;

import com.magicbullet.capture.core.RoiConfig;

/**
 * Draws the crop rectangle over the preview and lets it be dragged.
 *
 * <p>The rectangle outside the crop is dimmed so it is obvious that the rest of the frame is not
 * looked at. Coordinates are kept normalised in {@link RoiConfig}; the view only converts them to
 * screen space, using a letterbox-aware mapping so a 4:3 capture inside a 16:9 view still lines
 * up.
 */
public class RoiPickerView extends View {

    public interface Listener {
        void onRoiChanged(RoiConfig roi);
    }

    private final Paint mBorderPaint = new Paint(Paint.ANTI_ALIAS_FLAG);
    private final Paint mDimPaint = new Paint(Paint.ANTI_ALIAS_FLAG);
    private final Paint mTextPaint = new Paint(Paint.ANTI_ALIAS_FLAG);
    private final Paint mTextBgPaint = new Paint(Paint.ANTI_ALIAS_FLAG);
    private final RectF mDisplay = new RectF();
    private final RectF mRect = new RectF();

    private RoiConfig mRoi = RoiConfig.FULL;
    private int mFrameW;
    private int mFrameH;
    private float mGrabDx;
    private float mGrabDy;
    private Listener mListener;

    public RoiPickerView(Context context) {
        this(context, null);
    }

    public RoiPickerView(Context context, @Nullable AttributeSet attrs) {
        super(context, attrs);
        float density = getResources().getDisplayMetrics().density;
        mBorderPaint.setStyle(Paint.Style.STROKE);
        mBorderPaint.setStrokeWidth(2f * density);
        mBorderPaint.setColor(Color.WHITE);
        mBorderPaint.setPathEffect(new DashPathEffect(new float[]{12f * density, 8f * density}, 0));
        mDimPaint.setStyle(Paint.Style.FILL);
        mDimPaint.setColor(0x66000000);
        mTextPaint.setTextSize(12f * density);
        mTextPaint.setColor(Color.WHITE);
        mTextBgPaint.setStyle(Paint.Style.FILL);
        mTextBgPaint.setColor(0xCC000000);
    }

    public void setListener(Listener listener) {
        mListener = listener;
    }

    /** Source frame size; needed to convert the pixel crop into screen space. */
    public void setFrame(int width, int height) {
        if (width == mFrameW && height == mFrameH) {
            return;
        }
        mFrameW = width;
        mFrameH = height;
        invalidate();
    }

    public void setRoi(RoiConfig roi) {
        mRoi = roi == null ? RoiConfig.FULL : roi;
        invalidate();
    }

    @Override
    protected void onDraw(Canvas canvas) {
        super.onDraw(canvas);
        if (!mRoi.enabled || mFrameW <= 0 || mFrameH <= 0) {
            return;
        }
        updateDisplayRect();
        int[] bounds = mRoi.bounds(mFrameW, mFrameH);
        float scale = mDisplay.width() / mFrameW;
        float side = bounds[2] * scale;
        float left = mDisplay.left + bounds[0] * scale;
        float top = mDisplay.top + bounds[1] * scale;
        mRect.set(left, top, left + side, top + side);

        // Dim everything outside the crop.
        canvas.drawRect(mDisplay.left, mDisplay.top, mDisplay.right, mRect.top, mDimPaint);
        canvas.drawRect(mDisplay.left, mRect.bottom, mDisplay.right, mDisplay.bottom, mDimPaint);
        canvas.drawRect(mDisplay.left, mRect.top, mRect.left, mRect.bottom, mDimPaint);
        canvas.drawRect(mRect.right, mRect.top, mDisplay.right, mRect.bottom, mDimPaint);

        canvas.drawRect(mRect, mBorderPaint);

        String label = bounds[2] + "² · " + String.format(java.util.Locale.US, "%.2f",
                mRoi.magnification(mFrameW)) + "×";
        float textWidth = mTextPaint.measureText(label);
        float textHeight = mTextPaint.getTextSize();
        float textTop = Math.max(mDisplay.top, mRect.top - textHeight - 6f);
        canvas.drawRect(mRect.left, textTop, mRect.left + textWidth + 10f,
                textTop + textHeight + 6f, mTextBgPaint);
        canvas.drawText(label, mRect.left + 5f, textTop + textHeight, mTextPaint);
    }

    private void updateDisplayRect() {
        float viewW = getWidth();
        float viewH = getHeight();
        float scale = Math.min(viewW / mFrameW, viewH / mFrameH);
        float w = mFrameW * scale;
        float h = mFrameH * scale;
        float left = (viewW - w) / 2f;
        float top = (viewH - h) / 2f;
        mDisplay.set(left, top, left + w, top + h);
    }

    @Override
    public boolean onTouchEvent(MotionEvent event) {
        if (!mRoi.enabled || mFrameW <= 0) {
            return false;
        }
        updateDisplayRect();
        switch (event.getActionMasked()) {
            case MotionEvent.ACTION_DOWN:
                if (!mRect.contains(event.getX(), event.getY())) {
                    return false;
                }
                mGrabDx = event.getX() - mRect.centerX();
                mGrabDy = event.getY() - mRect.centerY();
                return true;
            case MotionEvent.ACTION_MOVE: {
                float cx = event.getX() - mGrabDx;
                float cy = event.getY() - mGrabDy;
                float halfW = mRect.width() / 2f;
                float halfH = mRect.height() / 2f;
                cx = Math.max(mDisplay.left + halfW, Math.min(mDisplay.right - halfW, cx));
                cy = Math.max(mDisplay.top + halfH, Math.min(mDisplay.bottom - halfH, cy));
                float nx = (cx - mDisplay.left) / mDisplay.width();
                float ny = (cy - mDisplay.top) / mDisplay.height();
                mRoi = mRoi.withCenter(nx, ny);
                invalidate();
                if (mListener != null) {
                    mListener.onRoiChanged(mRoi);
                }
                return true;
            }
            case MotionEvent.ACTION_UP:
            case MotionEvent.ACTION_CANCEL:
                return true;
            default:
                return super.onTouchEvent(event);
        }
    }
}
