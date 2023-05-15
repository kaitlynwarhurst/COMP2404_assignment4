#ifndef PHOTOGRAM_H
#define PHOTOGRAM_H

#include "MediaFactory.h"
#include "View.h"

class PhotoGram{
    private: 
        Array<Album*>* albumArr;
        Array<Photo*>* masterlist;
        MediaFactory mFactory;

    public:
        //Constructors
        PhotoGram();
        ~PhotoGram();

        //Member Functions
        void addAlbum(const string& title, const string& description);
        void addToAlbum(int index, const Array<Photo*>& photos);
        void uploadPhoto(const string& title);
        void deleteAlbum(int index);
        void getPhotos(const Criteria&, Array<Photo*>&);

        //Functions using the View Class
        void displayAlbum(int index, View&);
        int printAlbums(View&);
        void displayPhoto(int index, View&);
        int printPhotos(View&);



};

#endif