package com.magicbullet.capture.core;

import android.app.Notification;
import android.app.NotificationChannel;
import android.app.NotificationManager;
import android.app.PendingIntent;
import android.app.Service;
import android.content.Context;
import android.content.Intent;
import android.content.pm.ServiceInfo;
import android.os.Build;
import android.os.IBinder;
import android.os.PowerManager;
import android.util.Log;

import androidx.annotation.Nullable;
import androidx.core.app.NotificationCompat;

import com.magicbullet.capture.MainActivity;
import com.magicbullet.capture.R;

/**
 * 前台服务 + PARTIAL_WAKE_LOCK：把进程提到前台优先级（系统基本不杀），并让 CPU 在屏幕变暗后
 * 继续运行，保证「采集 → 推理 → 串口」闭环不被 Doze 冻结。
 *
 * <p>生命周期跟随 MainActivity：onStart 开启、onStop 停止。屏幕常亮由 MainActivity 的
 * {@code FLAG_KEEP_SCREEN_ON} 负责（窗口可见时有效，无需权限、不会泄漏）；本服务负责的是
 * 进程保活与 CPU 唤醒，两者互补。
 */
public class KeepAliveService extends Service {

    private static final String TAG = "KeepAlive";
    private static final String CHANNEL_ID = "magicbullet_keepalive";
    private static final int NOTIF_ID = 1001;

    private PowerManager.WakeLock mWakeLock;

    /** 供 Activity 调用；用 applicationContext 启动，避免拿到即将销毁的 Activity。 */
    public static void start(Context context) {
        Intent i = new Intent(context.getApplicationContext(), KeepAliveService.class);
        try {
            if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.O) {
                context.getApplicationContext().startForegroundService(i);
            } else {
                context.getApplicationContext().startService(i);
            }
        } catch (Throwable e) {
            // 部分定制 ROM 会拒绝后台启动前台服务：不让它拖垮 Activity 启动。
            Log.w(TAG, "start failed: " + e);
        }
    }

    public static void stop(Context context) {
        try {
            context.getApplicationContext().stopService(
                    new Intent(context.getApplicationContext(), KeepAliveService.class));
        } catch (Throwable e) {
            Log.w(TAG, "stop failed: " + e);
        }
    }

    @Override
    public void onCreate() {
        super.onCreate();
        PowerManager pm = (PowerManager) getSystemService(POWER_SERVICE);
        if (pm != null) {
            mWakeLock = pm.newWakeLock(PowerManager.PARTIAL_WAKE_LOCK, "MagicBullet:KeepAlive");
            // 不引用计数：onStartCommand 重复进来不会叠加，release 一次即释放。
            mWakeLock.setReferenceCounted(false);
            // 30 min 超时兜底：万一服务异常滞留，系统也会自动释放，避免永久唤醒。
            mWakeLock.acquire(30 * 60 * 1000L);
        }
        createChannel();
        Notification notification = buildNotification();
        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.Q) {
            startForeground(NOTIF_ID, notification,
                    ServiceInfo.FOREGROUND_SERVICE_TYPE_SPECIAL_USE);
        } else {
            startForeground(NOTIF_ID, notification);
        }
        Log.i(TAG, "foreground service started, wakelock=" + (mWakeLock != null && mWakeLock.isHeld()));
    }

    @Override
    public int onStartCommand(Intent intent, int flags, int startId) {
        if (mWakeLock != null && !mWakeLock.isHeld()) {
            mWakeLock.acquire(30 * 60 * 1000L);
        }
        // 被系统杀掉后自动重建；服务状态由 Activity 的 onStart/onStop 决定。
        return START_STICKY;
    }

    @Override
    public void onDestroy() {
        if (mWakeLock != null && mWakeLock.isHeld()) {
            mWakeLock.release();
        }
        Log.i(TAG, "foreground service stopped");
        super.onDestroy();
    }

    @Nullable
    @Override
    public IBinder onBind(Intent intent) {
        return null;
    }

    private void createChannel() {
        if (Build.VERSION.SDK_INT < Build.VERSION_CODES.O) {
            return;
        }
        NotificationManager nm = (NotificationManager) getSystemService(NOTIFICATION_SERVICE);
        if (nm == null) {
            return;
        }
        NotificationChannel channel = new NotificationChannel(CHANNEL_ID,
                getString(R.string.keepalive_channel_name), NotificationManager.IMPORTANCE_LOW);
        channel.setDescription(getString(R.string.keepalive_channel_desc));
        channel.setShowBadge(false);
        nm.createNotificationChannel(channel);
    }

    private Notification buildNotification() {
        Intent open = new Intent(this, MainActivity.class);
        int flags = PendingIntent.FLAG_UPDATE_CURRENT;
        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.M) {
            flags |= PendingIntent.FLAG_IMMUTABLE;
        }
        PendingIntent pi = PendingIntent.getActivity(this, 0, open, flags);
        return new NotificationCompat.Builder(this, CHANNEL_ID)
                .setSmallIcon(R.drawable.ic_stat_keepalive)
                .setContentTitle(getString(R.string.keepalive_notif_title))
                .setContentText(getString(R.string.keepalive_notif_text))
                .setContentIntent(pi)
                .setOngoing(true)
                .setPriority(NotificationCompat.PRIORITY_LOW)
                .build();
    }
}
