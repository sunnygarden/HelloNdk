package com.test.ndk.hellondk;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.util.Log;
import android.widget.TextView;

import java.util.Arrays;

public class MainActivity extends AppCompatActivity {

    static{
        System.loadLibrary("hello");
    }
    public static native String getHelloStringFromC();
    public static native int[] updateIntArray(int[] data);
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        TextView tv = (TextView) findViewById(R.id.show);
        tv.setText(getHelloStringFromC());
        int[] data = {1,2,3,4,5};
        int[] result = updateIntArray(data);
        Log.i("myTag", "after c change:" + Arrays.toString(result));

    }
}
