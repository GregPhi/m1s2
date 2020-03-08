package com.example.projetlivre;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.EditText;
import android.widget.Toast;

import com.example.projetlivre.scan.codebarre.ScanCodeBarre;

import androidx.appcompat.app.AppCompatActivity;

public class ChoicesActivity extends AppCompatActivity {
    @Override
    protected void onCreate(Bundle savedInstanceState){
        super.onCreate(savedInstanceState);
        setContentView(R.layout.choices);
    }

    public void scanCodeBarre(View view){
        Intent intent = new Intent(ChoicesActivity.this, ScanCodeBarre.class);
        startActivity(intent);
        //startActivityForResult(intent, );
    }

    public void recognizeText(View view){

    }

    public void inputInfos(View view){

    }

    public void inputCodeBarre(View view){
        EditText inpuCD = findViewById(R.id.codbarre_in);
        if(inpuCD.getText() == null){
            Toast.makeText(
                    getApplicationContext(),
                    R.string.cd_in,
                    Toast.LENGTH_LONG).show();
        }else{

        }
    }
}
