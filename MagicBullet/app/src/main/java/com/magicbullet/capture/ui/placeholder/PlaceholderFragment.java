package com.magicbullet.capture.ui.placeholder;

import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;
import android.widget.TextView;

import androidx.annotation.DrawableRes;
import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.annotation.StringRes;
import androidx.fragment.app.Fragment;

import com.magicbullet.capture.R;

/**
 * Shared "not implemented yet" page: icon + title + one line + a card describing what
 * the tab will hold. Keeps the three placeholder tabs from duplicating layouts.
 */
public class PlaceholderFragment extends Fragment {

    private static final String ARG_ICON = "icon";
    private static final String ARG_TITLE = "title";
    private static final String ARG_DESC = "desc";
    private static final String ARG_HINT = "hint";

    protected static Bundle args(@DrawableRes int icon, @StringRes int title,
                                 @StringRes int desc, @StringRes int hint) {
        Bundle bundle = new Bundle();
        bundle.putInt(ARG_ICON, icon);
        bundle.putInt(ARG_TITLE, title);
        bundle.putInt(ARG_DESC, desc);
        bundle.putInt(ARG_HINT, hint);
        return bundle;
    }

    public static PlaceholderFragment newInstance(@DrawableRes int icon, @StringRes int title,
                                                  @StringRes int desc, @StringRes int hint) {
        PlaceholderFragment fragment = new PlaceholderFragment();
        fragment.setArguments(args(icon, title, desc, hint));
        return fragment;
    }

    @Nullable
    @Override
    public View onCreateView(@NonNull LayoutInflater inflater, @Nullable ViewGroup container,
                             @Nullable Bundle savedInstanceState) {
        return inflater.inflate(R.layout.fragment_placeholder, container, false);
    }

    @Override
    public void onViewCreated(@NonNull View view, @Nullable Bundle savedInstanceState) {
        super.onViewCreated(view, savedInstanceState);
        Bundle arguments = getArguments();
        if (arguments == null) {
            return;
        }
        ImageView icon = view.findViewById(R.id.placeholder_icon);
        TextView title = view.findViewById(R.id.placeholder_title);
        TextView desc = view.findViewById(R.id.placeholder_desc);
        TextView hint = view.findViewById(R.id.placeholder_hint);

        icon.setImageResource(arguments.getInt(ARG_ICON, R.drawable.ic_tab_preview));
        title.setText(arguments.getInt(ARG_TITLE, R.string.app_name));
        desc.setText(arguments.getInt(ARG_DESC, R.string.keys_desc));
        hint.setText(arguments.getInt(ARG_HINT, R.string.keys_hint));
    }
}
