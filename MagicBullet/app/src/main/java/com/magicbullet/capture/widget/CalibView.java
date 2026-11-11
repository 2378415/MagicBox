package com.magicbullet.capture.widget;

import android.content.Context;
import android.graphics.Bitmap;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.DashPathEffect;
import android.graphics.Matrix;
import android.graphics.Paint;
import android.graphics.RectF;
import android.util.AttributeSet;
import android.view.MotionEvent;
import android.view.ScaleGestureDetector;
import android.view.View;

import com.magicbullet.capture.core.AimRect;

/**
 * Zoomable crosshair-calibration view.
 *
 * <p>Shows a frozen frame, lets the user pinch between 1× and 12× and drag the aim rectangle with
 * eight handles; the rectangle's centre <em>is</em> the crosshair, drawn as a small red dot. A 1-px
 * grid and a loupe make pixel-level alignment possible, which the portrait preview cannot offer.
 *
 * <p>The rectangle is kept in frame-normalised coordinates, so zooming and panning never change the
 * stored geometry - they only move the screen mapping.
 */
public class CalibView extends View {

    public interface Listener {
        void onAimRectChanged(AimRect rect);

        void onViewChanged(float zoom);
    }

    private static final int MODE_NONE = 0;
    private static final int MODE_MOVE = 1;
    private static final int MODE_HANDLE = 2;

    private final Paint mBitmapPaint = new Paint(Paint.FILTER_BITMAP_FLAG);
    private final Paint mDimPaint = new Paint(Paint.ANTI_ALIAS_FLAG);
    private final Paint mBorderPaint = new Paint(Paint.ANTI_ALIAS_FLAG);
    private final Paint mHandlePaint = new Paint(Paint.ANTI_ALIAS_FLAG);
    private final Paint mDotPaint = new Paint(Paint.ANTI_ALIAS_FLAG);
    private final Paint mGridPaint = new Paint();
    private final Paint mLoupeFramePaint = new Paint(Paint.ANTI_ALIAS_FLAG);

    private final Matrix mMatrix = new Matrix();
    private final RectF mScreen = new RectF();
    private final RectF mDest = new RectF();
    private final float[] mPoint = new float[2];
    private final ScaleGestureDetector mScaleDetector;

    private Bitmap mBitmap;
    private AimRect mRect = AimRect.DEFAULT;
    private float mZoom = 1f;
    private float mPanX;
    private float mPanY;
    private boolean mShowGrid = true;
    private boolean mShowLoupe = true;

    private int mMode = MODE_NONE;
    private int mHandle = -1;
    private float mLastX;
    private float mLastY;
    private float mDownX;
    private float mDownY;
    private Listener mListener;

    public CalibView(Context context) {
        this(context, null);
    }

    public CalibView(Context context, AttributeSet attrs) {
        super(context, attrs);
        float density = getResources().getDisplayMetrics().density;
        mDimPaint.setStyle(Paint.Style.FILL);
        mDimPaint.setColor(0x77000000);
        mBorderPaint.setStyle(Paint.Style.STROKE);
        mBorderPaint.setStrokeWidth(2f * density);
        mBorderPaint.setColor(0xFFFF9F0A);
        mBorderPaint.setPathEffect(new DashPathEffect(new float[]{10f * density, 6f * density}, 0));
        mHandlePaint.setStyle(Paint.Style.FILL);
        mHandlePaint.setColor(0xFFFFC64D);
        mDotPaint.setStyle(Paint.Style.FILL);
        mDotPaint.setColor(0xFFFF3B30);
        mGridPaint.setStyle(Paint.Style.STROKE);
        mGridPaint.setStrokeWidth(1f);
        mGridPaint.setColor(0x33FFFFFF);
        mLoupeFramePaint.setStyle(Paint.Style.STROKE);
        mLoupeFramePaint.setStrokeWidth(2f * density);
        mLoupeFramePaint.setColor(0xCCFFFFFF);
        mScaleDetector = new ScaleGestureDetector(context,
                new ScaleGestureDetector.SimpleOnScaleGestureListener() {
                    @Override
                    public boolean onScale(ScaleGestureDetector detector) {
                        zoomTo(mZoom * detector.getScaleFactor(), detector.getFocusX(),
                                detector.getFocusY());
                        return true;
                    }
                });
        setFocusable(true);
    }

    public void setListener(Listener listener) {
        mListener = listener;
    }

    public void setBitmap(Bitmap bitmap) {
        mBitmap = bitmap;
        mZoom = 1f;
        mPanX = 0f;
        mPanY = 0f;
        invalidate();
    }

    public void setRect(AimRect rect) {
        if (rect != null) {
            mRect = rect;
            invalidate();
        }
    }

    public AimRect getRect() {
        return mRect;
    }

    public float zoom() {
        return mZoom;
    }

    public void setShowGrid(boolean show) {
        mShowGrid = show;
        invalidate();
    }

    public void setShowLoupe(boolean show) {
        mShowLoupe = show;
        invalidate();
    }

    /** Sets the zoom (1..12) keeping the view centre fixed. */
    public void setZoom(float zoom) {
        zoomTo(zoom, getWidth() / 2f, getHeight() / 2f);
    }

    /** Moves the rectangle by whole frame pixels - the fine adjustment the phone could not do. */
    public void nudge(int dxPx, int dyPx) {
        if (mBitmap == null) {
            return;
        }
        float nx = (float) dxPx / mBitmap.getWidth();
        float ny = (float) dyPx / mBitmap.getHeight();
        mRect = new AimRect(mRect.x + nx, mRect.y + ny, mRect.w, mRect.h);
        notifyRect();
        invalidate();
    }

    /** Moves the rectangle so its centre sits on the frame centre. */
    public void centreRect() {
        if (mBitmap == null) {
            return;
        }
        mRect = mRect.centredAt(0.5f, 0.5f);
        notifyRect();
        invalidate();
    }

    @Override
    protected void onDraw(Canvas canvas) {
        super.onDraw(canvas);
        if (mBitmap == null || getWidth() == 0 || getHeight() == 0) {
            return;
        }
        buildMatrix();
        canvas.drawBitmap(mBitmap, mMatrix, mBitmapPaint);

        toScreen(mRect, mScreen);
        canvas.drawRect(0, 0, getWidth(), mScreen.top, mDimPaint);
        canvas.drawRect(0, mScreen.bottom, getWidth(), getHeight(), mDimPaint);
        canvas.drawRect(0, mScreen.top, mScreen.left, mScreen.bottom, mDimPaint);
        canvas.drawRect(mScreen.right, mScreen.top, getWidth(), mScreen.bottom, mDimPaint);
        canvas.drawRect(mScreen, mBorderPaint);

        float density = getResources().getDisplayMetrics().density;
        if (mShowGrid && mZoom >= 5f) {
            drawPixelGrid(canvas);
        }
        drawHandles(canvas, 12f * density);
        canvas.drawCircle(mScreen.centerX(), mScreen.centerY(), 1.5f * density, mDotPaint);
        if (mShowLoupe) {
            drawLoupe(canvas, density);
        }
    }

    private void drawPixelGrid(Canvas canvas) {
        // 1 frame-pixel grid, only when a pixel is at least 6 screen px wide.
        float scale = frameScale();
        if (scale < 6f) {
            return;
        }
        float left = mScreen.left;
        float top = mScreen.top;
        for (float x = left; x <= mScreen.right; x += scale) {
            canvas.drawLine(x, top, x, mScreen.bottom, mGridPaint);
        }
        for (float y = top; y <= mScreen.bottom; y += scale) {
            canvas.drawLine(left, y, mScreen.right, y, mGridPaint);
        }
    }

    private void drawLoupe(Canvas canvas, float density) {
        float radius = 90f * density;
        float cx = getWidth() - radius - 16f * density;
        float cy = radius + 16f * density;
        int srcSize = 64;
        float fx = mRect.anchorX(mBitmap.getWidth());
        float fy = mRect.anchorY(mBitmap.getHeight());
        android.graphics.Rect src = new android.graphics.Rect(
                Math.round(fx - srcSize / 2f), Math.round(fy - srcSize / 2f),
                Math.round(fx + srcSize / 2f), Math.round(fy + srcSize / 2f));
        RectF dest = new RectF(cx - radius, cy - radius, cx + radius, cy + radius);
        canvas.save();
        android.graphics.Path clip = new android.graphics.Path();
        clip.addCircle(cx, cy, radius, android.graphics.Path.Direction.CW);
        canvas.clipPath(clip);
        canvas.drawBitmap(mBitmap, src, dest, mBitmapPaint);
        canvas.restore();
        canvas.drawCircle(cx, cy, radius, mLoupeFramePaint);
        canvas.drawCircle(cx, cy, 1.5f * density, mDotPaint);
    }

    private float frameScale() {
        if (mBitmap == null) {
            return 1f;
        }
        float base = Math.min(getWidth() / (float) mBitmap.getWidth(),
                getHeight() / (float) mBitmap.getHeight());
        return base * mZoom;
    }

    private void buildMatrix() {
        float base = Math.min(getWidth() / (float) mBitmap.getWidth(),
                getHeight() / (float) mBitmap.getHeight());
        float scale = base * mZoom;
        mMatrix.reset();
        mMatrix.postTranslate(-mBitmap.getWidth() / 2f, -mBitmap.getHeight() / 2f);
        mMatrix.postScale(scale, scale);
        mMatrix.postTranslate(getWidth() / 2f + mPanX, getHeight() / 2f + mPanY);
    }

    private void toScreen(AimRect rect, RectF out) {
        if (mBitmap == null) {
            out.setEmpty();
            return;
        }
        mPoint[0] = rect.x * mBitmap.getWidth();
        mPoint[1] = rect.y * mBitmap.getHeight();
        mMatrix.mapPoints(mPoint);
        float left = mPoint[0];
        float top = mPoint[1];
        mPoint[0] = (rect.x + rect.w) * mBitmap.getWidth();
        mPoint[1] = (rect.y + rect.h) * mBitmap.getHeight();
        mMatrix.mapPoints(mPoint);
        out.set(left, top, mPoint[0], mPoint[1]);
    }

    private void zoomTo(float zoom, float focusX, float focusY) {
        float clamped = Math.max(1f, Math.min(12f, zoom));
        if (Math.abs(clamped - mZoom) < 0.001f) {
            return;
        }
        // Keep the focus point under the finger: shift the pan by the position change.
        float ratio = clamped / mZoom;
        mPanX = (mPanX + focusX - getWidth() / 2f) * ratio - (focusX - getWidth() / 2f);
        mPanY = (mPanY + focusY - getHeight() / 2f) * ratio - (focusY - getHeight() / 2f);
        mZoom = clamped;
        clampPan();
        if (mListener != null) {
            mListener.onViewChanged(mZoom);
        }
        invalidate();
    }

    private void clampPan() {
        if (mBitmap == null) {
            return;
        }
        float scale = frameScale();
        float maxX = Math.max(0f, (mBitmap.getWidth() * scale - getWidth()) / 2f);
        float maxY = Math.max(0f, (mBitmap.getHeight() * scale - getHeight()) / 2f);
        mPanX = Math.max(-maxX, Math.min(maxX, mPanX));
        mPanY = Math.max(-maxY, Math.min(maxY, mPanY));
    }

    @Override
    public boolean onTouchEvent(MotionEvent event) {
        if (mBitmap == null) {
            return false;
        }
        mScaleDetector.onTouchEvent(event);
        if (mScaleDetector.isInProgress()) {
            mMode = MODE_NONE;
            return true;
        }
        switch (event.getActionMasked()) {
            case MotionEvent.ACTION_DOWN: {
                buildMatrix();
                toScreen(mRect, mScreen);
                mLastX = event.getX();
                mLastY = event.getY();
                mDownX = event.getX();
                mDownY = event.getY();
                mHandle = hitHandle(event.getX(), event.getY());
                float density = getResources().getDisplayMetrics().density;
                if (mHandle >= 0) {
                    mMode = MODE_HANDLE;
                } else if (mScreen.contains(event.getX(), event.getY())) {
                    mMode = MODE_MOVE;
                } else {
                    mMode = MODE_NONE; // panning the picture
                }
                return true;
            }
            case MotionEvent.ACTION_MOVE: {
                float dx = event.getX() - mLastX;
                float dy = event.getY() - mLastY;
                mLastX = event.getX();
                mLastY = event.getY();
                if (mMode == MODE_NONE) {
                    mPanX += dx;
                    mPanY += dy;
                    clampPan();
                    invalidate();
                } else if (mMode == MODE_MOVE) {
                    dragRect(dx, dy);
                } else if (mMode == MODE_HANDLE) {
                    dragHandle(dx, dy);
                }
                return true;
            }
            case MotionEvent.ACTION_UP:
            case MotionEvent.ACTION_CANCEL: {
                if (mMode != MODE_NONE) {
                    notifyRect();
                } else if (Math.hypot(event.getX() - mDownX, event.getY() - mDownY) < 8f) {
                    // A tap outside the box re-centres nothing - keep the picture where it is.
                }
                mMode = MODE_NONE;
                mHandle = -1;
                return true;
            }
            default:
                return super.onTouchEvent(event);
        }
    }


    private void dragRect(float dxScreen, float dyScreen) {
        float nx = dxScreen / Math.max(1f, mScreen.width()) * mRect.w;
        float ny = dyScreen / Math.max(1f, mScreen.height()) * mRect.h;
        mRect = new AimRect(mRect.x + nx, mRect.y + ny, mRect.w, mRect.h);
        invalidate();
    }

    private void dragHandle(float dxScreen, float dyScreen) {
        float dnx = dxScreen / Math.max(1f, mScreen.width()) * mRect.w;
        float dny = dyScreen / Math.max(1f, mScreen.height()) * mRect.h;
        float x = mRect.x;
        float y = mRect.y;
        float w = mRect.w;
        float h = mRect.h;
        switch (mHandle) {
            case 0: x += dnx; y += dny; w -= dnx; h -= dny; break; // top-left
            case 1: y += dny; h -= dny; break;                     // top
            case 2: w += dnx; y += dny; h -= dny; break;           // top-right
            case 3: w += dnx; break;                                // right
            case 4: w += dnx; h += dny; break;                      // bottom-right
            case 5: h += dny; break;                                // bottom
            case 6: x += dnx; w -= dnx; h += dny; break;           // bottom-left
            case 7: x += dnx; w -= dnx; break;                      // left
            default: break;
        }
        mRect = new AimRect(x, y, Math.max(0.02f, w), Math.max(0.02f, h));
        invalidate();
    }

    private int hitHandle(float sx, float sy) {
        float density = getResources().getDisplayMetrics().density;
        float r = 18f * density;
        float[] xs = {mScreen.left, mScreen.centerX(), mScreen.right, mScreen.right,
                mScreen.right, mScreen.centerX(), mScreen.left, mScreen.left};
        float[] ys = {mScreen.top, mScreen.top, mScreen.top, mScreen.centerY(),
                mScreen.bottom, mScreen.bottom, mScreen.bottom, mScreen.centerY()};
        for (int i = 0; i < xs.length; i++) {
            if (Math.hypot(sx - xs[i], sy - ys[i]) <= r) {
                return i;
            }
        }
        return -1;
    }

    private void drawHandles(Canvas canvas, float radius) {
        float[] xs = {mScreen.left, mScreen.centerX(), mScreen.right, mScreen.right,
                mScreen.right, mScreen.centerX(), mScreen.left, mScreen.left};
        float[] ys = {mScreen.top, mScreen.top, mScreen.top, mScreen.centerY(),
                mScreen.bottom, mScreen.bottom, mScreen.bottom, mScreen.centerY()};
        for (int i = 0; i < xs.length; i++) {
            canvas.drawCircle(xs[i], ys[i], radius * 0.45f, mHandlePaint);
        }
    }

    private void notifyRect() {
        if (mListener != null) {
            mListener.onAimRectChanged(mRect);
        }
    }
}
