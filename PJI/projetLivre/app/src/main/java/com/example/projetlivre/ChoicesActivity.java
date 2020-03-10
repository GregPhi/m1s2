package com.example.projetlivre;

import android.content.Intent;
import android.os.Bundle;
import android.text.TextUtils;
import android.view.View;
import android.widget.EditText;
import android.widget.Toast;

import com.example.projetlivre.dataB.BookViewModel;
import com.example.projetlivre.object.Book;
import com.example.projetlivre.object.Constantes;
import com.example.projetlivre.scan.codebarre.ScanCodeBarre;

import androidx.appcompat.app.AppCompatActivity;
import androidx.lifecycle.ViewModelProviders;

public class ChoicesActivity extends AppCompatActivity {
    public static BookViewModel mBookViewModel;

    @Override
    protected void onCreate(Bundle savedInstanceState){
        super.onCreate(savedInstanceState);
        setContentView(R.layout.choices);

        mBookViewModel = ViewModelProviders.of(this).get(BookViewModel.class);
    }

    public void scanCodeBarre(View view){
        Intent intent = new Intent(ChoicesActivity.this, ScanCodeBarre.class);
        startActivity(intent);
        //startActivityForResult(intent, );
    }

    public void recognizeText(View view){

    }

    public void inputInfos(View view){
        Intent intent = new Intent(ChoicesActivity.this, NewBookActivity.class);
        startActivityForResult(intent, Constantes.NEW_BOOK_ACTIVITY);
    }

    public void inputCodeBarre(View view){
        EditText inpuCD = findViewById(R.id.codbarre_in);
        if(TextUtils.isEmpty(inpuCD.getText())){
            Toast.makeText(
                    getApplicationContext(),
                    R.string.cd_in,
                    Toast.LENGTH_LONG).show();
        }else{

        }
    }

    @Override
    public void onActivityResult(int requestCode, int resultCode, Intent data) {
        super.onActivityResult(requestCode, resultCode, data);
        if(requestCode == Constantes.NEW_BOOK_ACTIVITY && resultCode == Constantes.NEW_BOOK_FAIL){
            Toast.makeText(
                    getApplicationContext(),
                    R.string.add_book_fail,
                    Toast.LENGTH_LONG).show();
        }
        if(requestCode == Constantes.NEW_BOOK_ACTIVITY && resultCode == Constantes.NEW_BOOK_OK){
            Toast.makeText(
                    getApplicationContext(),
                    R.string.add_book_ok,
                    Toast.LENGTH_LONG).show();
            newBook(data);
        }
    }

    public void newBook(Intent data){
        Book book = data.getParcelableExtra("Book");
        if(book != null){
            mBookViewModel.insert(book);
        }
    }
}
