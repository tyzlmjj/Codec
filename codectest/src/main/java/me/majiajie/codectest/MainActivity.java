package me.majiajie.codectest;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;

import me.majiajie.codec.Decode;
import me.majiajie.codec.Encode;


public class MainActivity extends AppCompatActivity
{

    Button btn_base64_encode;
    Button btn_base64_decode;
    TextView textView;
    TextView textView2;
    EditText editText;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        btn_base64_encode = (Button) findViewById(R.id.btn_base64_encode);
        btn_base64_decode = (Button) findViewById(R.id.btn_base64_decode);
        textView = (TextView) findViewById(R.id.textView);
        textView2 = (TextView) findViewById(R.id.textView2);
        editText = (EditText) findViewById(R.id.editText);

        String encode = Encode.Custom_Base64("0123456789-0123456789-0123456789")
                .setMaxCharLine(5)
                .doit();
        Log.i("asd", "Encode: " +encode);
//        Log.i("asd", "Decode: " +Decode.Base64(encode));


        editText.setText("输入需要加密的字符串");
        btn_base64_encode.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                textView.setText(Encode.Base64(editText.getText().toString()));
            }
        });

        btn_base64_decode.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                textView2.setText(Decode.Base64(textView.getText().toString()));
            }
        });


    }
}
