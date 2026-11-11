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

import com.magicbullet.capture.core.AimRect;

import java.util.Locale;

/**
 * The aim rectangle over the live preview: drag the inside to move it, grab an edge or a corner to
 * resize it.
 *
 * <p>The crosshair is drawn at the rectangle's centre because that centre *is* the aim anchor - a
 * separate anchor parameter would only allow the two to disagree. Coordinates stay normalised in
 * {@link AimRect}; the view maps them through a letterbox-aware display rect so a non-16:9 capture
 * still lines up with what the box actually sees.
 */
public class AimRectView extends View {

    public interface Listener {
        void onAimRectChanged(AimRect rect);
    }

    private static final int NONE = 0;
    private static final int MOVE = 1;
    private static final int LEFT = 2;
    private static final int RIGHT = 3;
    private static final int TOP = 4;
    private static final int BOTTOM = 5;
    private static final int TOP_LEFT = 6;
    private static final int TOP_RIGHT = 7;
    private static final int BOTTOM_LEFT = 8;
    private static final int BOTTOM_RIGHT = 9;

    private static final int MIN_SIZE_PX = 64;

    private final Paint mBorderPaint = new Paint(Paint.ANTI_ALIAS_FLAG);
    private final Paint mDimPaint = new Paint(Paint.ANTI_ALIAS_FLAG);
    private final Paint mHandlePaint = new Paint(Paint.ANTI_ALIAS_FLAG);
    private final Paint mCrossPaint = new Paint(Paint.ANTI_ALIAS_FLAG);

    private final Paint mTextPaint = new Paint(Paint.ANTI_ALIAS_FLAG);
    private final Paint mTextBgPaint = new Paint(Paint.ANTI_ALIAS_FLAG);
    private final RectF mDisplay = new RectF();
    private final RectF mRect = new RectF();

    private AimRect mAimRect = AimRect.DEFAULT;
    private int mFrameW;
    private int mFrameH;
    private boolean mEditable = true;
    private int mDragMode = NONE;
    private float mLastX;
    private float mLastY;
    private float mDownX;
    private float mDownY;
    private Listener mListener;

    public AimRectView(Context context) {
        this(context, null);
    }

    public AimRectView(Context context, @Nullable AttributeSet attrs) {
        super(context, attrs);
        float density = getResources().getDisplayMetrics().density;
        mBorderPaint.setStyle(Paint.Style.STROKE);
        mBorderPaint.setStrokeWidth(2f * density);
        mBorderPaint.setColor(0xFFFF9F0A);
        mBorderPaint.setPathEffect(new DashPathEffect(new float[]{10f * density, 7f * density}, 0));
        mDimPaint.setStyle(Paint.Style.FILL);
        mDimPaint.setColor(0x55000000);
        mHandlePaint.setStyle(Paint.Style.FILL);
        mHandlePaint.setColor(0xFFFF9F0A);
        mCrossPaint.setStyle(Paint.Style.FILL);
        mCrossPaint.setColor(0xFFFF3B30);

        mTextPaint.setTextSize(12f * density);
        mTextPaint.setColor(Color.WHITE);
        mTextBgPaint.setStyle(Paint.Style.FILL);
        mTextBgPaint.setColor(0xCC000000);
    }

    public void setListener(Listener listener) {
        mListener = listener;
    }

    public void setEditable(boolean editable) {
        mEditable = editable;
        invalidate();
    }

    public void setFrame(int width, int height) {
        if (width == mFrameW && height == mFrameH) {
            return;
        }
        mFrameW = width;
        mFrameH = height;
        invalidate();
    }

    public void setAimRect(AimRect rect) {
        mAimRect = rect == null ? AimRect.DEFAULT : rect;
        invalidate();
    }

    @Override
    protected void onDraw(Canvas canvas) {
        super.onDraw(canvas);
        if (mFrameW <= 0 || mFrameH <= 0) {
            return;
        }
        updateDisplayRect();
        toScreen(mAimRect, mRect);

        // Dim everything outside the aim rectangle: only this area is looked at.
        canvas.drawRect(mDisplay.left, mDisplay.top, mDisplay.right, mRect.top, mDimPaint);
        canvas.drawRect(mDisplay.left, mRect.bottom, mDisplay.right, mDisplay.bottom, mDimPaint);
        canvas.drawRect(mDisplay.left, mRect.top, mRect.left, mRect.bottom, mDimPaint);
        canvas.drawRect(mRect.right, mRect.top, mDisplay.right, mRect.bottom, mDimPaint);
        canvas.drawRect(mRect, mBorderPaint);

        // 准心 = 一个很小的红点（瞄准点就是矩形中心），不套白环
        float density = getResources().getDisplayMetrics().density;
        float cx = mRect.centerX();
        float cy = mRect.centerY();
        canvas.drawCircle(cx, cy, 1.0f * density, mCrossPaint);

        if (mEditable) {
            drawHandles(canvas, density);
        }

        int[] bounds = mAimRect.boundsPx(mFrameW, mFrameH);
        String label = String.format(Locale.US, "%d × %d · 准心 %.2f,%.2f",
                bounds[2], bounds[3], mAimRect.x + mAimRect.w / 2f, mAimRect.y + mAimRect.h / 2f);
        float textWidth = mTextPaint.measureText(label);
        float textHeight = mTextPaint.getTextSize();
        float textTop = Math.max(mDisplay.top, mRect.top - textHeight - 8f);
        canvas.drawRect(mRect.left, textTop, mRect.left + textWidth + 10f,
                textTop + textHeight + 6f, mTextBgPaint);
        canvas.drawText(label, mRect.left + 5f, textTop + textHeight, mTextPaint);
    }

    private void drawHandles(Canvas canvas, float density) {
        float r = 5f * density;
        float[] xs = {mRect.left, mRect.centerX(), mRect.right};
        float[] ys = {mRect.top, mRect.centerY(), mRect.bottom};
        for (int iy = 0; iy < 3; iy++) {
            for (int ix = 0; ix < 3; ix++) {
                if (ix == 1 && iy == 1) {
                    continue; // centre is the crosshair, not a handle
                }
                canvas.drawCircle(xs[ix], ys[iy], r, mHandlePaint);
            }
        }
    }

    private void updateDisplayRect() {
        float viewW = getWidth();
        float viewH = getHeight();
        float scale = Math.min(viewW / mFrameW, viewH / mFrameH);
        float w = mFrameW * scale;
        float h = mFrameH * scale;
        mDisplay.set((viewW - w) / 2f, (viewH - h) / 2f, (viewW - w) / 2f + w,
                (viewH - h) / 2f + h);
    }

    private void toScreen(AimRect rect, RectF out) {
        out.set(mDisplay.left + rect.x * mDisplay.width(),
                mDisplay.top + rect.y * mDisplay.height(),
                mDisplay.left + (rect.x + rect.w) * mDisplay.width(),
                mDisplay.top + (rect.y + rect.h) * mDisplay.height());
    }

    @Override
    public boolean onTouchEvent(MotionEvent event) {
        if (!mEditable || mFrameW <= 0 || mFrameH <= 0) {
            return false;
        }
        updateDisplayRect();
        toScreen(mAimRect, mRect);
        switch (event.getActionMasked()) {
            case MotionEvent.ACTION_DOWN: {
                int mode = hitTest(event.getX(), event.getY());
                if (mode == NONE) {
                    return false;
                }
                mDragMode = mode;
                mLastX = event.getX();
                mLastY = event.getY();
                mDownX = event.getX();
                mDownY = event.getY();
                return true;
            }
            case MotionEvent.ACTION_MOVE: {
                if (mDragMode == NONE) {
                    return false;
                }
                float dx = (event.getX() - mLastX) / Math.max(1f, mDisplay.width());
                float dy = (event.getY() - mLastY) / Math.max(1f, mDisplay.height());
                mLastX = event.getX();
                mLastY = event.getY();
                applyDrag(dx, dy);
                return true;
            }
            case MotionEvent.ACTION_UP:
            case MotionEvent.ACTION_CANCEL: {
                if (mDragMode != NONE) {
                    mDragMode = NONE;
                    if (mListener != null) {
                        mListener.onAimRectChanged(mAimRect);
                    }
                    return true;
                }
                return false;
            }
            default:
                return super.onTouchEvent(event);
        }
    }

    private int hitTest(float x, float y) {
        float density = getResources().getDisplayMetrics().density;
        float grab = 22f * density;
        boolean nearLeft = Math.abs(x - mRect.left) < grab;
        boolean nearRight = Math.abs(x - mRect.right) < grab;
        boolean nearTop = Math.abs(y - mRect.top) < grab;
        boolean nearBottom = Math.abs(y - mRect.bottom) < grab;
        boolean insideX = x > mRect.left - grab && x < mRect.right + grab;
        boolean insideY = y > mRect.top - grab && y < mRect.bottom + grab;
        if (!insideX || !insideY) {
            return NONE;
        }
        if (nearLeft && nearTop) {
            return TOP_LEFT;
        }
        if (nearRight && nearTop) {
            return TOP_RIGHT;
        }
        if (nearLeft && nearBottom) {
            return BOTTOM_LEFT;
        }
        if (nearRight && nearBottom) {
            return BOTTOM_RIGHT;
        }
        if (nearLeft) {
            return LEFT;
        }
        if (nearRight) {
            return RIGHT;
        }
        if (nearTop) {
            return TOP;
        }
        if (nearBottom) {
            return BOTTOM;
        }
        if (x > mRect.left && x < mRect.right && y > mRect.top && y < mRect.bottom) {
            return MOVE;
        }
        return NONE;
    }

    private void applyDrag(float dx, float dy) {
        float minW = (float) MIN_SIZE_PX / Math.max(1, mFrameW);
        float minH = (float) MIN_SIZE_PX / Math.max(1, mFrameH);
        float x = mAimRect.x;
        float y = mAimRect.y;
        float w = mAimRect.w;
        float h = mAimRect.h;
        switch (mDragMode) {
            case MOVE:
                x += dx;
                y += dy;
                break;
            case LEFT:
                x += dx;
                w -= dx;
                break;
            case RIGHT:
                w += dx;
                break;
            case TOP:
                y += dy;
                h -= dy;
                break;
            case BOTTOM:
                h += dy;
                break;
            case TOP_LEFT:
                x += dx;
                y += dy;
                w -= dx;
                h -= dy;
                break;
            case TOP_RIGHT:
                y += dy;
                w += dx;
                h -= dy;
                break;
            case BOTTOM_LEFT:
                x += dx;
                w -= dx;
                h += dy;
                break;
            case BOTTOM_RIGHT:
                w += dx;
                h += dy;
                break;
            default:
                return;
        }
        if (w < minW) {
            w = minW;
        }
        if (h < minH) {
            h = minH;
        }
        AimRect next = new AimRect(x, y, w, h);
        if (!next.equals(mAimRect)) {
            mAimRect = next;
            invalidate();
        }
    }
}
