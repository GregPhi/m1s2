package com.example.projetlivre;

import android.content.Intent;
import android.os.Bundle;
import android.widget.Toast;

import androidx.appcompat.app.AppCompatActivity;

public class ChoicesActivity extends AppCompatActivity {
    @Override
    protected void onCreate(Bundle savedInstanceState){
        super.onCreate(savedInstanceState);
        setContentView(R.layout.choices);
        Intent intent = getIntent();
        if(intent != null){
            String content = "";
            if(intent.hasExtra("content")){
                content = intent.getStringExtra("content");
                Toast toast = Toast.makeText(getApplicationContext(),
                        content, Toast.LENGTH_SHORT);
                toast.show();
            }
        }
    }
}
