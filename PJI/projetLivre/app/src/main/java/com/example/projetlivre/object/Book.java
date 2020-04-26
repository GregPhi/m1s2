package com.example.projetlivre.object;

import android.os.Parcel;
import android.os.Parcelable;

import androidx.annotation.NonNull;
import androidx.room.Entity;
import androidx.room.PrimaryKey;

@Entity(tableName = "book_table")
public class Book implements Parcelable {
    // ATTRIBUST
    /**/
    @PrimaryKey
    @NonNull
    private String id;
    /**/
    @NonNull
    private String code_barre;
    /**/
    @NonNull
    private String title;
    /**/
    private String matiere;
    /**/
    private String description;
    /**/
    private String commenataires;
    /**/
    private Annee annee;
    /**/
    private String classe;
    /**/
    private Etats etats;

    // CONSTRUCTOR

    /**
     *
     */
    public Book(){
        this.id = "";
        this.code_barre = "";
        this.title = "";
        this.matiere = "";
        this.commenataires = "";
    }

    /**
     *
     * @param i
     * @param c
     * @param t
     * @param m
     * @param d
     */
    public Book(String i, String c, String t, String m, String d){
        this.id = i;
        this.code_barre = c;
        this.title = t;
        this.matiere = m;
        this.commenataires = d;
    }

    // GETTER AND SETTER

    /**
     *
     * @param i
     */
    public void setId(String i){
        this.id = i;
    }

    /**
     *
     * @param c
     */
    public void setCode_barre(String c){
        this.code_barre = c;
    }

    /**
     *
     * @param t
     */
    public void setTitle(String t){
        this.title = t;
    }

    /**
     *
     * @param m
     */
    public void setMatiere(String m){
        this.matiere = m;
    }

    /**
     *
     * @param d
     */
    public void setCommenataires(String d){
        this.commenataires = d;
    }

    /**
     *
     * @param a
     */
    public void setAnnee(Annee a){
        this.annee = a;
    }

    /**
     *
     * @param c
     */
    public void setClasse(String c){
        this.classe = c;
    }

    /**
     *
     * @param e
     */
    public void setEtats(Etats e){
        this.etats = e;
    }

    /**
     *
     * @return
     */
    public String getId(){
        return this.id;
    }

    /**
     *
     * @return
     */
    public String getCode_barre(){
        return this.code_barre;
    }

    /**
     *
     * @return
     */
    public String getTitle(){
        return this.title;
    }

    /**
     *
     * @return
     */
    public String getMatiere(){
        return this.matiere;
    }

    /**
     *
     * @return
     */
    public String getCommenataires(){
        return this.commenataires;
    }

    /**
     *
     * @return
     */
    public Annee getAnnee(){
        return this.annee;
    }

    /**
     *
     * @return
     */
    public String getClasse(){
        return this.classe;
    }

    /**
     *
     * @return
     */
    public Etats getEtats(){
        return this.etats;
    }

    // PARCELABLE
    public static final Parcelable.Creator CREATOR = new Parcelable.Creator() {
        public Book createFromParcel(Parcel in) {
            return new Book(in);
        }

        public Book[] newArray(int size) {
            return new Book[size];
        }
    };

    public Book(Parcel in) {
        this.id = in.readString();
        this.code_barre = in.readString();
        this.title = in.readString();
        this.matiere = in.readString();
        this.commenataires = in.readString();
        this.annee = Annee.values()[in.readInt()];
        this.classe = in.readString();
        this.etats = Etats.values()[in.readInt()];
    }

    @Override
    public int describeContents() {
        return 0;
    }

    @Override
    public void writeToParcel(Parcel dest, int flags) {
        dest.writeString(this.id);
        dest.writeString(this.code_barre);
        dest.writeString(this.title);
        dest.writeString(this.matiere);
        dest.writeString(this.commenataires);
        dest.writeParcelable(this.annee,0);
        dest.writeString(this.classe);
        dest.writeParcelable(this.etats,1);
    }
}
