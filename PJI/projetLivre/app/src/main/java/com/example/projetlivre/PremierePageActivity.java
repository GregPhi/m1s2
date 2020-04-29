package com.example.projetlivre;

import android.content.Intent;
import android.os.Bundle;
import android.text.TextUtils;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Spinner;
import android.widget.Toast;

import androidx.appcompat.app.AppCompatActivity;

public class PremierePageActivity extends AppCompatActivity {

    private final static String[] users = {"user1","user2"};

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
                    Toast.makeText(getApplicationContext(), "Merci d'indiquer un nom d'utilisateur", Toast.LENGTH_LONG).show();
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
                            String user = numUser.getText().toString();
                            for(String u : users){
                                if(user.equals(u)){
                                    Intent intent = new Intent(PremierePageActivity.this, NewBookActivity.class);
                                    startActivity(intent);
                                }
                            }
                            break;
                    }
                }
            }
        });
    }
}
