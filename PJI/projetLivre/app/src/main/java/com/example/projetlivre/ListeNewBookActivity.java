package com.example.projetlivre;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Toast;

import com.example.projetlivre.dataB.BookViewModel;
import com.example.projetlivre.object.Book;
import com.example.projetlivre.unsued.listAdapter.BookListAdapter;
import com.google.android.material.floatingactionbutton.FloatingActionButton;

import java.util.List;

import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;
import androidx.lifecycle.Observer;
import androidx.lifecycle.ViewModelProviders;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

public class ListeNewBookActivity extends AppCompatActivity {

    public static BookViewModel mBookViewModel;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.newliste_livres);

        RecyclerView recyclerView = findViewById(R.id.recyclerview);
        final BookListAdapter adapter = new BookListAdapter(this);
        recyclerView.setAdapter(adapter);
        recyclerView.setLayoutManager(new LinearLayoutManager(this));

        FloatingActionButton fab = findViewById(R.id.fab);
        fab.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Toast up = Toast.makeText(getApplicationContext(), "UPLOAD !", Toast.LENGTH_SHORT);
                up.show();
            }
        });

        mBookViewModel = ViewModelProviders.of(this).get(BookViewModel.class);
        mBookViewModel.getmAllBooks().observe(this, new Observer<List<Book>>() {
            @Override
            public void onChanged(@Nullable final List<Book> book) {
                // Update the cached copy of the words in the adapter.
                adapter.setBooks(book);
            }
        });
    }
}
