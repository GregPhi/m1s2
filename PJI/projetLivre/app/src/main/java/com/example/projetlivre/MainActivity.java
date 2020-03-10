package com.example.projetlivre;

import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;
import androidx.lifecycle.Observer;
import androidx.lifecycle.ViewModelProviders;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Toast;

import com.example.projetlivre.dataB.BookViewModel;
import com.example.projetlivre.listAdapter.BookListAdapter;
import com.example.projetlivre.object.Book;
import com.example.projetlivre.object.Constantes;
import com.google.android.material.floatingactionbutton.FloatingActionButton;

import java.util.List;

public class MainActivity extends AppCompatActivity {
    public static BookViewModel mBookViewModel;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        FloatingActionButton cd = findViewById(R.id.actionScan);
        cd.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Intent intent = new Intent(MainActivity.this, ChoicesActivity.class);
                startActivity(intent);
            }
        });

        FloatingActionButton add = findViewById(R.id.actionAdd);
        add.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Intent intent = new Intent(MainActivity.this, NewBookActivity.class);
                startActivityForResult(intent,Constantes.NEW_BOOK_ACTIVITY);
            }
        });

        RecyclerView recyclerView = findViewById(R.id.recyclerview);
        final BookListAdapter adapter = new BookListAdapter(this);
        recyclerView.setAdapter(adapter);
        recyclerView.setLayoutManager(new LinearLayoutManager(this));

        mBookViewModel = ViewModelProviders.of(this).get(BookViewModel.class);
        mBookViewModel.getmAllBooks().observe(this, new Observer<List<Book>>() {
            @Override
            public void onChanged(@Nullable final List<Book> book) {
                // Update the cached copy of the words in the adapter.
                adapter.setBooks(book);
            }
        });
    }

    @Override
    public void onActivityResult(int requestCode, int resultCode, Intent data) {
        super.onActivityResult(requestCode, resultCode, data);
        if(requestCode == Constantes.NEW_BOOK_ACTIVITY){
            if(resultCode == Constantes.NEW_BOOK_OK) {
                Book book = data.getParcelableExtra("Book");
                addBook(book);
            }
        }
        if(requestCode == Constantes.INFO_BOOK_ACTIVITY){
            if(resultCode == Constantes.INFO_BOOK_FAIL){
                Toast.makeText(
                        getApplicationContext(),
                        R.string.info_book_fail,
                        Toast.LENGTH_LONG).show();
            }
            if(resultCode == Constantes.INFO_BOOK_OK){
                boolean changed = data.getBooleanExtra("Changed",false);
                if(changed){
                    Book book = data.getParcelableExtra("Book");
                    mBookViewModel.updateBook(book);
                }
            }
        }
    }

    public void addBook(Book book){
        mBookViewModel.insert(book);
    }

    public void removeBook(Book book){
        mBookViewModel.delete(book);
    }

    public void infosBook(Book book){
        Intent intent = new Intent(MainActivity.this, InfoBookActivity.class);
        intent.putExtra("Book",book);
        startActivityForResult(intent, Constantes.INFO_BOOK_ACTIVITY);
    }
}
