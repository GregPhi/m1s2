package com.example.myapplication.dao;

import com.example.myapplication.object.Book;

import java.util.List;

import androidx.lifecycle.LiveData;
import androidx.room.Dao;
import androidx.room.Delete;
import androidx.room.Insert;
import androidx.room.OnConflictStrategy;
import androidx.room.Query;
import androidx.room.Update;

@Dao
public interface BookDao {
    @Insert(onConflict = OnConflictStrategy.REPLACE)
    void insert(Book book);

    @Update
    void updateBook(Book... books);

    @Delete
    void delete(Book book);

    @Query("DELETE FROM book_table")
    void deleteAll();

    @Query("SELECT * FROM book_table ORDER BY title ASC")
    LiveData<List<Book>> getmAllBooks();

    @Query("SELECT * FROM book_table WHERE matiere =:m")
    LiveData<List<Book>> getAllBookForAMatiere(String m);
    }
