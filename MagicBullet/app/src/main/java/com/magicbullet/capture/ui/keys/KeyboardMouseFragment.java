package com.magicbullet.capture.ui.keys;

import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.EditText;
import android.widget.ScrollView;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.fragment.app.Fragment;

import com.google.android.material.button.MaterialButton;
import com.google.android.material.materialswitch.MaterialSwitch;
import com.magicbullet.capture.R;
import com.magicbullet.capture.core.ControlPort;

import java.util.List;
import java.util.Locale;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

/**
 * 键鼠 tab: talks to the MagicBox control port with the binary protocol.
 *
 * <p>First milestone only sends {@code SUMV} (0x36) so the pointer moves like a hand would;
 * the box takes exclusive ownership of motion for the duration of the trajectory. Everything
 * here is fire-and-forget, so the only synchronous call is the PING that measures the link.
 */
public class KeyboardMouseFragment extends Fragment implements ControlPort.Listener {

    private static final int FLICK_COUNTS = 200;
    private static final int MODE_TREMOR_BIT = ControlPort.MODE_BIT_TREMOR;

    private ControlPort mPort;
    private TextView mStatus;
    private TextView mDetail;
    private TextView mLink;
    private TextView mMode;
    private TextView mLog;
    private ScrollView mLogScroll;
    private EditText mDx;
    private EditText mDy;
    private EditText mSpeed;
    private MaterialSwitch mTremor;
    private MaterialButton mModeAim;
    private MaterialButton mModeHuman;
    private MaterialButton mModeTurbo;
    private boolean mBinding;
    private final ExecutorService mIo = Executors.newSingleThreadExecutor();

    public static KeyboardMouseFragment newInstance() {
        return new KeyboardMouseFragment();
    }

    @Nullable
    @Override
    public View onCreateView(@NonNull LayoutInflater inflater, @Nullable ViewGroup container,
                             @Nullable Bundle savedInstanceState) {
        return inflater.inflate(R.layout.fragment_keys, container, false);
    }

    @Override
    public void onViewCreated(@NonNull View view, @Nullable Bundle savedInstanceState) {
        super.onViewCreated(view, savedInstanceState);
        mPort = ControlPort.get(requireContext());

        mStatus = view.findViewById(R.id.keys_status);
        mDetail = view.findViewById(R.id.keys_detail);
        mLink = view.findViewById(R.id.keys_link);
        mMode = view.findViewById(R.id.keys_mode);
        mLog = view.findViewById(R.id.keys_log);
        mLogScroll = view.findViewById(R.id.keys_log_scroll);
        mDx = view.findViewById(R.id.keys_dx);
        mDy = view.findViewById(R.id.keys_dy);
        mSpeed = view.findViewById(R.id.keys_speed);
        mTremor = view.findViewById(R.id.keys_tremor);

        view.findViewById(R.id.keys_connect).setOnClickListener(v -> mPort.connect());
        view.findViewById(R.id.keys_disconnect).setOnClickListener(v -> mPort.disconnect());
        view.findViewById(R.id.keys_ping).setOnClickListener(v -> mIo.execute(() -> {
            if (mPort.ping()) {
                requireActivity().runOnUiThread(this::renderLink);
            }
        }));
        view.findViewById(R.id.keys_send).setOnClickListener(v -> sendSumv());
        view.findViewById(R.id.keys_state).setOnClickListener(v -> mPort.querySumvState());
        view.findViewById(R.id.keys_btn_log).setOnClickListener(v -> {
            if (!mPort.isOpen()) {
                toast(getString(R.string.keys_not_connected));
                return;
            }
            mPort.btnLog(0);
            toast("已请求，按键轨迹看下方串口日志");
        });
        view.findViewById(R.id.keys_last_hid).setOnClickListener(v -> {
            if (!mPort.isOpen()) {
                toast(getString(R.string.keys_not_connected));
                return;
            }
            mPort.lastHid();
            toast("已请求，结果看下方串口日志");
        });
        view.findViewById(R.id.keys_left).setOnClickListener(v -> flick(-FLICK_COUNTS, 0));
        view.findViewById(R.id.keys_right).setOnClickListener(v -> flick(FLICK_COUNTS, 0));
        view.findViewById(R.id.keys_up).setOnClickListener(v -> flick(0, -FLICK_COUNTS));
        view.findViewById(R.id.keys_down).setOnClickListener(v -> flick(0, FLICK_COUNTS));

        mBinding = true;
        mTremor.setChecked((mPort.mode() & MODE_TREMOR_BIT) != 0);
        mBinding = false;
        renderMode();
        mTremor.setOnCheckedChangeListener((buttonView, checked) -> {
            if (mBinding) {
                return;
            }
            // 2026-11-11 firmware: tremor only exists inside the humanised profile (bit6),
            // so ticking the switch has to switch profiles as well - otherwise it is a no-op.
            mPort.setMode(checked
                    ? (mPort.mode() | ControlPort.MODE_BIT_HUMAN | MODE_TREMOR_BIT)
                    : (mPort.mode() & ~MODE_TREMOR_BIT));
            renderMode();
        });

        mModeAim = view.findViewById(R.id.keys_mode_aim);
        mModeHuman = view.findViewById(R.id.keys_mode_human);
        mModeTurbo = view.findViewById(R.id.keys_mode_turbo);
        mModeAim.setOnClickListener(v -> setModePreset(ControlPort.MODE_AIM));
        mModeHuman.setOnClickListener(v -> setModePreset(ControlPort.MODE_HUMAN));
        mModeTurbo.setOnClickListener(v -> setModePreset(ControlPort.MODE_TURBO));
        renderMode();

        renderLog(mPort.logLines());
        renderLink();
    }

    @Override
    public void onStart() {
        super.onStart();
        mPort.setListener(this);
        renderLog(mPort.logLines());
        renderLink();
    }

    @Override
    public void onStop() {
        mPort.setListener(null);
        super.onStop();
    }

    @Override
    public void onDestroyView() {
        super.onDestroyView();
        mIo.shutdown();
    }

    // ------------------------------------------------------------------ actions

    private void sendSumv() {
        int dx = parseInt(mDx, 0);
        int dy = parseInt(mDy, 0);
        int speed = parseInt(mSpeed, ControlPort.DEFAULT_SPEED);
        if (dx == 0 && dy == 0) {
            toast(getString(R.string.keys_need_delta));
            return;
        }
        if (!mPort.isOpen()) {
            toast(getString(R.string.keys_not_connected));
            return;
        }
        mPort.sumv(dx, dy, speed);
    }

    private void flick(int dx, int dy) {
        if (!mPort.isOpen()) {
            toast(getString(R.string.keys_not_connected));
            return;
        }
        mPort.flick(dx, dy);
    }

    private static int parseInt(EditText field, int fallback) {
        String text = field.getText() == null ? "" : field.getText().toString().trim();
        if (text.isEmpty() || "-".equals(text) || "+".equals(text)) {
            return fallback;
        }
        try {
            return Integer.parseInt(text);
        } catch (NumberFormatException e) {
            return fallback;
        }
    }

    private void toast(CharSequence text) {
        if (getContext() != null) {
            android.widget.Toast.makeText(getContext(), text, android.widget.Toast.LENGTH_SHORT)
                    .show();
        }
    }

    // ------------------------------------------------------------------ ControlPort.Listener

    @Override
    public void onState(String status, String detail) {
        if (!isAdded() || mStatus == null) {
            return;
        }
        mStatus.setText(status);
        mDetail.setText(detail);
        renderLink();
    }

    @Override
    public void onLog(String line) {
        if (!isAdded()) {
            return;
        }
        renderLog(mPort.logLines());
    }

    // ------------------------------------------------------------------ render

    private void renderLink() {
        if (mLink == null) {
            return;
        }
        if (!mPort.isOpen()) {
            mLink.setText(R.string.keys_link_idle);
            return;
        }
        double rtt = mPort.lastRttMs();
        mLink.setText(String.format(Locale.US, "%s · %d 8N1 · PING %s",
                mPort.deviceLabel(), mPort.baud(),
                rtt >= 0 ? String.format(Locale.US, "%.2f ms", rtt) : "—"));
    }

    private void renderMode() {
        if (mMode == null) {
            return;
        }
        int mode = mPort.mode();
        String profile;
        if ((mode & ControlPort.MODE_BIT_HUMAN) != 0) {
            profile = getString(R.string.keys_profile_human);
        } else if ((mode & ControlPort.MODE_TURBO) != 0) {
            profile = getString(R.string.keys_profile_turbo);
        } else {
            profile = getString(R.string.keys_profile_aim);
        }
        mMode.setText(String.format(Locale.US, "mode 0x%02X · %s · 手颤%s · 子运动%s",
                mode, profile, bitLabel(mode & 0x02), bitLabel(mode & 0x04)));
        if (mModeAim != null) {
            highlight(mModeAim, mode == ControlPort.MODE_AIM);
            highlight(mModeHuman, mode == ControlPort.MODE_HUMAN);
            highlight(mModeTurbo, mode == ControlPort.MODE_TURBO);
        }
    }

    private void highlight(MaterialButton button, boolean selected) {
        button.setAlpha(selected ? 1f : 0.5f);
        button.setStrokeWidth(selected
                ? (int) (2 * getResources().getDisplayMetrics().density) : 0);
    }

    /** Preset buttons: the 2026-11-11 firmware only has three profiles worth exposing. */
    private void setModePreset(int mode) {
        mPort.setMode(mode);
        mBinding = true;
        mTremor.setChecked((mode & MODE_TREMOR_BIT) != 0);
        mBinding = false;
        renderMode();
    }

    private String bitLabel(int value) {
        return getString(value != 0 ? R.string.keys_on : R.string.keys_off);
    }

    private void renderLog(List<String> lines) {
        if (mLog == null) {
            return;
        }
        StringBuilder sb = new StringBuilder();
        int from = Math.max(0, lines.size() - 60);
        for (int i = from; i < lines.size(); i++) {
            sb.append(lines.get(i)).append('\n');
        }
        mLog.setText(sb);
        if (mLogScroll != null) {
            mLogScroll.post(() -> mLogScroll.fullScroll(View.FOCUS_DOWN));
        }
    }
}
