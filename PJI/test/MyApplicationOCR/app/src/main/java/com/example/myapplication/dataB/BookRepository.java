package com.example.myapplication.dataB;

import com.example.myapplication.ProjectRoomDatabase;
import com.example.myapplication.dao.BookDao;
import com.example.myapplication.object.Book;

import android.app.Application;
import android.os.AsyncTask;

import java.util.List;

import androidx.lifecycle.LiveData;

public class BookRepository{

    private BookDao mBookDao;
    private LiveData<List<Book>> mAllBooks;

    BookRepository(Application application) {
        ProjectRoomDatabase db = ProjectRoomDatabase.getDatabase(application);
        mBookDao = db.bookDao();
        mAllBooks = mBookDao.getmAllBooks();
    }

    LiveData<List<Book>> getmAllBooks() {
        return mAllBooks;
    }


    public void insert (Book book) {
        new insertAsyncTask(mBookDao).execute(book);
    }

    public void delete (Book book) {
        new deleteAsyncTask(mBookDao).execute(book);
    }

    private static class insertAsyncTask extends AsyncTask<Book, Void, Void> {

        private BookDao mAsyncTaskDao;

        insertAsyncTask(BookDao dao) {
            mAsyncTaskDao = dao;
        }

        @Override
        protected Void doInBackground(final Book... params) {
            mAsyncTaskDao.insert(params[0]);
            return null;
        }
    }

    private static class deleteAsyncTask extends AsyncTask<Book, Void, Void> {

        private BookDao mAsyncTaskDao;

        deleteAsyncTask(BookDao dao) {
            mAsyncTaskDao = dao;
        }

        @Override
        protected Void doInBackground(final Book... params) {
            mAsyncTaskDao.delete(params[0]);
            return null;
        }
    }
}
