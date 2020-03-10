package com.example.projetlivre.scan.codebarre;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.Toast;

import androidx.appcompat.app.AppCompatActivity;

import com.example.projetlivre.ChoicesActivity;
import com.example.projetlivre.R;
import com.google.zxing.integration.android.IntentIntegrator;
import com.google.zxing.integration.android.IntentResult;

public class ScanCodeBarre extends AppCompatActivity implements View.OnClickListener {

    private Button scanButton;

    @Override
    protected void onCreate(Bundle savedInstanceState){
        super.onCreate(savedInstanceState);
        setContentView(R.layout.scan_book);
        scanButton = findViewById(R.id.scan_cd);
    }

    @Override
    public void onClick(View v){
        if(v.getId() == R.id.scan_cd){
            IntentIntegrator scanIntegrator = new IntentIntegrator(this);
            scanIntegrator.initiateScan();
        }
    }

    @Override
    public void onActivityResult(int requestCode, int resultCode, Intent intent){
        super.onActivityResult(requestCode,resultCode,intent);
        IntentResult scanningResult = IntentIntegrator.parseActivityResult(requestCode, resultCode, intent);
        String scanContent = "";
        if (scanningResult != null) {
            scanContent = scanningResult.getContents();
        }else {
            Intent choices = new Intent(this, ChoicesActivity.class);
            scanContent = "No scan data received!";
            choices.putExtra("content", scanContent);
            startActivity(choices);
        }
    }

    public void touse(){
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
