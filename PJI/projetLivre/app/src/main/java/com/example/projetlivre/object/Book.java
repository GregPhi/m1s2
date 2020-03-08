package com.example.projetlivre.object;

import androidx.annotation.NonNull;
import androidx.room.Entity;
import androidx.room.PrimaryKey;

@Entity(tableName = "book_table")
public class Book {
    @PrimaryKey
    private String id;
    @NonNull
    private String title;
    private String matiere;
    private String description;

    public Book(){
        this.id = "";
        this.title = "";
        this.matiere = "";
        this.description = "";
    }

    public Book(String i, String t, String m, String d){
        this.id = i;
        this.title = t;
        this.matiere = m;
        this.description = d;
    }

    public void setId(String i){
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

    public String getId(){
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
