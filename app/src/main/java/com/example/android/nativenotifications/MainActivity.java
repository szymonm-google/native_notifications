package com.example.android.nativenotifications;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;

import com.example.android.nativenotifications.databinding.ActivityMainBinding;

public class MainActivity extends AppCompatActivity {

    // Used to load the 'nativenotifications' library on application startup.
    static {
        System.loadLibrary("nativenotifications");
    }

    private ActivityMainBinding binding;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        binding = ActivityMainBinding.inflate(getLayoutInflater());
        setContentView(binding.getRoot());

        showNotification(R.mipmap.ic_launcher);
    }

    /**
     * A native method that is implemented by the 'nativenotifications' native library,
     * which is packaged with this application.
     */
    public native void showNotification(int icon_id);
}
