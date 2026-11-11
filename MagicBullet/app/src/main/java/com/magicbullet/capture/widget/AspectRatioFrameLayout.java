package com.magicbullet.capture.widget;

import android.content.Context;
import android.util.AttributeSet;
import android.widget.FrameLayout;

/**
 * FrameLayout locked to 16:9 so a SurfaceView and an overlay can share one box.
 *
 * <p>The capture card outputs 1920x1080; in portrait the preview therefore has to be
 * letterboxed instead of stretched to the phone's 20:9 panel.
 */
public class AspectRatioFrameLayout extends FrameLayout {

    private float mAspectRatio = 16f / 9f;

    public AspectRatioFrameLayout(Context context) {
        super(context);
    }

    public AspectRatioFrameLayout(Context context, AttributeSet attrs) {
        super(context, attrs);
    }

    public AspectRatioFrameLayout(Context context, AttributeSet attrs, int defStyleAttr) {
        super(context, attrs, defStyleAttr);
    }

    public void setAspectRatio(float aspectRatio) {
        if (aspectRatio > 0f) {
            mAspectRatio = aspectRatio;
            requestLayout();
        }
    }

    @Override
    protected void onMeasure(int widthMeasureSpec, int heightMeasureSpec) {
        int width = MeasureSpec.getSize(widthMeasureSpec);
        int height = MeasureSpec.getSize(heightMeasureSpec);

        if (MeasureSpec.getMode(widthMeasureSpec) == MeasureSpec.UNSPECIFIED
                && MeasureSpec.getMode(heightMeasureSpec) == MeasureSpec.UNSPECIFIED) {
            super.onMeasure(widthMeasureSpec, heightMeasureSpec);
            return;
        }

        int targetWidth = width;
        int targetHeight = (int) (width / mAspectRatio);

        if (targetHeight > height) {
            targetHeight = height;
            targetWidth = (int) (height * mAspectRatio);
        }

        int childWidth = MeasureSpec.makeMeasureSpec(targetWidth, MeasureSpec.EXACTLY);
        int childHeight = MeasureSpec.makeMeasureSpec(targetHeight, MeasureSpec.EXACTLY);
        super.onMeasure(childWidth, childHeight);
        setMeasuredDimension(targetWidth, targetHeight);
    }
}
