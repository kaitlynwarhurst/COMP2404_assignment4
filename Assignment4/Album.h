#ifndef ALBUM_H
#define ALBUM_H

#include "Array.h"
#include "Photo.h"

class Album{
    friend ostream& operator<<(ostream&, const Album&);
    public:
        //constructors
        Album(const string& title, const string& description);
        //Album(const Album& album);
        //destructors
        ~Album();
        //methods
        string titleGetter() const;
        bool equals(const string& title) const;
        bool lessThan(const Album& alb) const;
        void addPhoto(Photo* ptr );
        //bool addPhoto(int index, Photo* ptr);
        Photo* getPhoto(const string& title) const;
        Photo* getPhoto(int index) const;
        Photo* removePhoto(const string& title);
        Photo* removePhoto(int index);
        void print(ostream&) const;
        void display(ostream&) const;
        int size() const;
        string getTitle() const;

    private:
        string albumTitle;
        string albumDescription;
        Array<Photo*>* albumPhotos;

};

#endif