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

public class InfoBookActivity extends AppCompatActivity {
    private static Book book;

    private EditText mEditCodeBarreView;
    private EditText mEditTitleView;
    private EditText mEditMatiereView;
    private EditText mEditDescriptionView;

    @Override
    public void onCreate(Bundle savedInstanceState){
        super.onCreate(savedInstanceState);
        setContentView(R.layout.info_book);

        Intent intent = getIntent();
        book = intent.getParcelableExtra("Book");

        mEditCodeBarreView = findViewById(R.id.infos_cd);
        mEditTitleView = findViewById(R.id.info_title);
        mEditMatiereView = findViewById(R.id.info_mat);
        mEditDescriptionView = findViewById(R.id.info_desc);

        mEditCodeBarreView.setText(book.getId());
        mEditTitleView.setText(book.getTitle());
        mEditMatiereView.setText(book.getMatiere());
        mEditDescriptionView.setText(book.getDescription());

        final Button button = findViewById(R.id.save);
        button.setOnClickListener(new View.OnClickListener(){
            public void onClick(View view){
                Intent reply = new Intent();
                if(TextUtils.isEmpty(mEditCodeBarreView.getText())){
                    setResult(Constantes.INFO_BOOK_FAIL);
                }else{
                    boolean changed = false;
                    Book updateBook = new Book();
                    if(!TextUtils.isEmpty(mEditCodeBarreView.getText()) && !book.getId().equals(mEditCodeBarreView.getText().toString())){
                        updateBook.setId(mEditCodeBarreView.getText().toString());
                        changed = true;
                    }else{
                        updateBook.setId(book.getId());
                    }
                    if(!TextUtils.isEmpty(mEditTitleView.getText()) && !book.getTitle().equals(mEditTitleView.getText().toString())){
                        updateBook.setTitle(mEditTitleView.getText().toString());
                        changed = true;
                    }else{
                        updateBook.setTitle(book.getTitle());
                    }
                    if(!TextUtils.isEmpty(mEditMatiereView.getText()) && !book.getMatiere().equals(mEditMatiereView.getText().toString())){
                        updateBook.setMatiere(mEditMatiereView.getText().toString());
                        changed = true;
                    }else{
                        updateBook.setMatiere(book.getMatiere());
                    }
                    if(!TextUtils.isEmpty(mEditDescriptionView.getText()) && !book.getDescription().equals(mEditDescriptionView.getText().toString())){
                        updateBook.setDescription(mEditDescriptionView.getText().toString());
                        changed = true;
                    }else{
                        updateBook.setDescription(book.getDescription());
                    }
                    reply.putExtra("Changed",changed);
                    reply.putExtra("Book", book);
                    setResult(Constantes.INFO_BOOK_OK,reply);
                }
                finish();
            }
        });
    }

    public void retourClick(View view){
        Intent intent = new Intent(InfoBookActivity.this, MainActivity.class);
        startActivity(intent);
    }
}
