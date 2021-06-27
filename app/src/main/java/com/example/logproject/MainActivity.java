package com.example.logproject;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.os.Environment;
import android.widget.TextView;

import java.io.File;

public class MainActivity extends AppCompatActivity {

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // Example of a call to a native method
        TextView tv = findViewById(R.id.sample_text);
        tv.setText(stringFromJNI());


        File file =new File(Environment.getExternalStorageDirectory(),"test.log");
        FileLogger  fileLogger  = new FileLogger(file,4*1024*1024);
        fileLogger.write("xxxx0 ->");
        fileLogger.write("xxxx1 ->");
        fileLogger.write("xxxx2 ->");

    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();
}
