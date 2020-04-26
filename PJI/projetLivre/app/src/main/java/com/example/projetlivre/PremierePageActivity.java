package com.example.projetlivre;

import android.os.Bundle;
import android.text.TextUtils;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Spinner;

import androidx.appcompat.app.AppCompatActivity;

public class PremierePageActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.main_layout);
        final EditText numUser = findViewById(R.id.numUser);
        final Spinner choix = findViewById(R.id.choix);
        final Button button = findViewById(R.id.validateMain);
        button.setOnClickListener(new View.OnClickListener(){
            public void onClick(View view){
                if (TextUtils.isEmpty(numUser.getText())){

                }else{
                    String c = choix.getSelectedItem().toString();
                    switch(c) {
                        case "Prêt de livre(s)":
                            break;
                        case "Rendu de livre(s)":
                            break;
                        case "MAJ livres":
                            break;
                        default:

                            break;
                    }
                }
            }
        });
    }
}
