package com.example.projetlivre;

import android.content.Intent;
import android.os.Bundle;
import android.text.TextUtils;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;

import com.example.projetlivre.object.Book;
import com.example.projetlivre.object.Constantes;

import androidx.appcompat.app.AppCompatActivity;

public class NewBookActivity extends AppCompatActivity {
    private Book newBook = null;

    private EditText mEditCodeBarreView;
    private EditText mEditTitleView;
    private EditText mEditMatiereView;
    private EditText mEditDescriptionView;

    @Override
    public void onCreate(Bundle savedInstanceState){
        super.onCreate(savedInstanceState);
        setContentView(R.layout.new_book);

        mEditCodeBarreView = findViewById(R.id.edit_cd);
        mEditTitleView = findViewById(R.id.edit_titre);
        mEditMatiereView = findViewById(R.id.edit_matiere);
        mEditDescriptionView = findViewById(R.id.edit_descrip);

        final Button button = findViewById(R.id.button_ok);
        button.setOnClickListener(new View.OnClickListener(){
            public void onClick(View view){
                newBook = new Book();
                Intent reply = new Intent();
                if(TextUtils.isEmpty(mEditCodeBarreView.getText())){
                    setResult(Constantes.NEW_BOOK_FAIL);
                }else{
                    newBook.setId(mEditCodeBarreView.getText().toString());
                    if(!TextUtils.isEmpty(mEditTitleView.getText())){
                        newBook.setTitle(mEditTitleView.getText().toString());
                    }
                    if(!TextUtils.isEmpty(mEditMatiereView.getText())){
                        newBook.setMatiere(mEditMatiereView.getText().toString());
                    }
                    if(!TextUtils.isEmpty(mEditDescriptionView.getText())){
                        newBook.setDescription(mEditDescriptionView.getText().toString());
                    }
                    reply.putExtra("Book", newBook);
                    setResult(Constantes.NEW_BOOK_OK,reply);
                }
                finish();
            }
        });
    }
}
