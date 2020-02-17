package com.example.projetlivre.object;

import androidx.annotation.NonNull;
import androidx.room.Entity;
import androidx.room.PrimaryKey;

@Entity(tableName = "book_table")
public class Book {
    @PrimaryKey(autoGenerate = true)
    private int id;
    @NonNull
    private String title;
    private String matiere;
    private String description;

    Book(){
        title = "";
        matiere = "";
        description = "";
    }

    Book(String t, String m, String d){
        this.title = t;
        this.matiere = m;
        this.description = d;
    }

    public void setId(int i){
        this.id = i;
    }
    public void setTitle(String t){
        this.title = t;
    }
    public void setMatiere(String m){
        this.matiere = m;
    }
    public void setDescription(String d){
        this.description = d;
    }

    public int getId(){
        return this.id;
    }
    public String getTitle(){
        return this.title;
    }
    public String getMatiere(){
        return this.matiere;
    }
    public String getDescription(){
        return this.description;
    }
}
