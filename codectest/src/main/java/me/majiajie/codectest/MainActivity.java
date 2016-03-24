package me.majiajie.codectest;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;


public class MainActivity extends AppCompatActivity
{

    Button btn_base64_encode;
    TextView textView;
    EditText editText;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        btn_base64_encode = (Button) findViewById(R.id.btn_base64_encode);
        textView = (TextView) findViewById(R.id.textView);
        editText = (EditText) findViewById(R.id.editText);

        editText.setText(Decode.Base64("看什么看"));
        btn_base64_encode.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {

            }
        });
    }
}
