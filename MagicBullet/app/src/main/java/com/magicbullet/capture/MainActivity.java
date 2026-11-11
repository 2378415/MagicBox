package com.magicbullet.capture;

import android.os.Bundle;
import android.view.KeyEvent;
import android.view.View;

import androidx.activity.OnBackPressedCallback;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.graphics.Insets;
import androidx.core.view.ViewCompat;
import androidx.core.view.WindowCompat;
import androidx.core.view.WindowInsetsCompat;
import androidx.fragment.app.Fragment;
import androidx.fragment.app.FragmentTransaction;

import com.google.android.material.bottomnavigation.BottomNavigationView;
import com.magicbullet.capture.core.AimConfig;
import com.magicbullet.capture.core.AimController;
import com.magicbullet.capture.core.UvcSession;
import com.magicbullet.capture.core.UvcSessionHost;
import com.magicbullet.capture.ui.aim.AimFragment;
import com.magicbullet.capture.ui.keys.KeyboardMouseFragment;
import com.magicbullet.capture.ui.preview.PreviewFragment;
import com.magicbullet.capture.ui.yolo.YoloFragment;

/**
 * Single-activity shell: bottom navigation + four fragments, portrait only.
 *
 * <p>The USB/UVC session lives here, not in a fragment, so switching tabs never
 * re-opens the camera and never re-asks for USB permission.
 */
public class MainActivity extends AppCompatActivity implements UvcSessionHost,
        AimFragment.RectEditorHost {

    private static final String KEY_TAB = "current_tab";

    private static final String[] TAGS = {"tab_preview", "tab_yolo", "tab_keys", "tab_aim"};
    private static final int[] MENU_IDS = {
            R.id.tab_preview, R.id.tab_yolo, R.id.tab_keys, R.id.tab_aim
    };

    private UvcSession mSession;
    private BottomNavigationView mNav;
    private int mCurrentTab;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        WindowCompat.setDecorFitsSystemWindows(getWindow(), false);
        setContentView(R.layout.activity_main);

        applyWindowInsets();

        mSession = new UvcSession(this);
        mNav = findViewById(R.id.bottom_nav);
        mNav.setOnItemSelectedListener(item -> {
            int index = indexOfMenu(item.getItemId());
            if (index >= 0) {
                showTab(index);
                return true;
            }
            return false;
        });

        mCurrentTab = savedInstanceState != null ? savedInstanceState.getInt(KEY_TAB, 0) : 0;
        if (savedInstanceState == null) {
            createFragments();
        }
        showTab(mCurrentTab);
        mNav.setSelectedItemId(MENU_IDS[mCurrentTab]);

        getOnBackPressedDispatcher().addCallback(this, new OnBackPressedCallback(true) {
            @Override
            public void handleOnBackPressed() {
                if (mCurrentTab != 0) {
                    mNav.setSelectedItemId(MENU_IDS[0]);
                } else {
                    setEnabled(false);
                    getOnBackPressedDispatcher().onBackPressed();
                }
            }
        });
    }

    @Override
    protected void onStart() {
        super.onStart();
        mSession.start();
    }

    @Override
    protected void onStop() {
        mSession.stop();
        super.onStop();
    }

    @Override
    protected void onDestroy() {
        mSession.destroy();
        // Never leave the box eating the hotkey after the app is gone (it would also recover on
        // its own after 10 s without a heartbeat, but be explicit).
        AimController.get(this).setArmed(false);
        super.onDestroy();
    }

    @Override
    protected void onSaveInstanceState(Bundle outState) {
        super.onSaveInstanceState(outState);
        outState.putInt(KEY_TAB, mCurrentTab);
    }

    @Override
    public UvcSession session() {
        return mSession;
    }

    @Override
    public void onRequestPermissionsResult(int requestCode, String[] permissions,
                                           int[] grantResults) {
        super.onRequestPermissionsResult(requestCode, permissions, grantResults);
        mSession.onRequestPermissionsResult(requestCode, grantResults);
    }

    // ------------------------------------------------------------------ aim hotkey / rect editing

    /** Volume keys are the phone-side fallback trigger for aiming (the box hotkey needs the port). */
    @Override
    public boolean onKeyDown(int keyCode, KeyEvent event) {
        if (isAimSideKey(keyCode) && AimConfig.load(this).volumeKeyEnabled()) {
            if (event.getRepeatCount() == 0) {
                AimController.get(this).onExternalTrigger(true);
            }
            return true;
        }
        return super.onKeyDown(keyCode, event);
    }

    @Override
    public boolean onKeyUp(int keyCode, KeyEvent event) {
        if (isAimSideKey(keyCode) && AimConfig.load(this).volumeKeyEnabled()) {
            AimController.get(this).onExternalTrigger(false);
            return true;
        }
        return super.onKeyUp(keyCode, event);
    }

    private static boolean isAimSideKey(int keyCode) {
        return keyCode == KeyEvent.KEYCODE_VOLUME_DOWN || keyCode == KeyEvent.KEYCODE_VOLUME_UP;
    }

    /** The aim tab asks for the rectangle editor, which only makes sense on the live preview. */
    @Override
    public void editAimRect() {
        mNav.setSelectedItemId(MENU_IDS[0]);
        Fragment fragment = getSupportFragmentManager().findFragmentByTag(TAGS[0]);
        if (fragment instanceof PreviewFragment) {
            ((PreviewFragment) fragment).beginEditAimRect();
        }
    }

    // ------------------------------------------------------------------ tabs

    private void createFragments() {
        FragmentTransaction transaction = getSupportFragmentManager().beginTransaction();
        transaction.add(R.id.nav_host, PreviewFragment.newInstance(), TAGS[0]);
        transaction.add(R.id.nav_host, YoloFragment.newInstance(), TAGS[1]);
        transaction.add(R.id.nav_host, KeyboardMouseFragment.newInstance(), TAGS[2]);
        transaction.add(R.id.nav_host, AimFragment.newInstance(), TAGS[3]);
        for (int i = 1; i < TAGS.length; i++) {
            Fragment fragment = getSupportFragmentManager().findFragmentByTag(TAGS[i]);
            if (fragment != null) {
                transaction.hide(fragment);
            }
        }
        transaction.commitNow();
    }

    private void showTab(int index) {
        if (index < 0 || index >= TAGS.length) {
            return;
        }
        FragmentTransaction transaction = getSupportFragmentManager().beginTransaction();
        for (int i = 0; i < TAGS.length; i++) {
            Fragment fragment = getSupportFragmentManager().findFragmentByTag(TAGS[i]);
            if (fragment == null) {
                continue;
            }
            if (i == index) {
                transaction.show(fragment);
            } else {
                transaction.hide(fragment);
            }
        }
        transaction.commit();
        mCurrentTab = index;
    }

    private static int indexOfMenu(int itemId) {
        for (int i = 0; i < MENU_IDS.length; i++) {
            if (MENU_IDS[i] == itemId) {
                return i;
            }
        }
        return -1;
    }

    // ------------------------------------------------------------------ insets

    private void applyWindowInsets() {
        final View root = findViewById(R.id.root);
        final View nav = findViewById(R.id.bottom_nav);
        ViewCompat.setOnApplyWindowInsetsListener(root, (view, windowInsets) -> {
            Insets bars = windowInsets.getInsets(WindowInsetsCompat.Type.systemBars());
            view.setPadding(bars.left, bars.top, bars.right, 0);
            nav.setPadding(nav.getPaddingLeft(), nav.getPaddingTop(),
                    nav.getPaddingRight(), bars.bottom);
            return windowInsets;
        });
    }
}
