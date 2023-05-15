#include "PhotoGram.h"

PhotoGram::PhotoGram(){
    albumArr = new Array<Album*>();
    masterlist = new Array<Photo*>();
}

PhotoGram::~PhotoGram(){
    int numPhotos = masterlist->size();
    delete albumArr;
    for(int i =0; i<numPhotos; ++i){
       delete (*masterlist)[i];
    }
    delete masterlist; 
}

void PhotoGram::addAlbum(const string& title, const string& description){
    Album* a = mFactory.createAlbum(title,description);
    albumArr->add(a);
}

void PhotoGram::addToAlbum(int index, const Array<Photo*>& photos){
    int numPhotos = photos.size();
    Album* a = (*albumArr)[index];
    for(int i =0; i< numPhotos; ++i ){
        cout<< *(photos[i])<<endl;
        a->addPhoto(photos[i]);
    }
}

void PhotoGram::uploadPhoto(const string& title){
    //Photo* p = mFactory.uploadPhoto(title);
    masterlist->add(mFactory.uploadPhoto(title));
}

void PhotoGram::deleteAlbum(int index){
    int numAlbums = albumArr->size();
    if(index >= numAlbums || index <0){
        cerr<< "Error: Bad Index!"<<endl;
        return;
    }
    albumArr->remove((*albumArr)[index]);
}

void PhotoGram::getPhotos(const Criteria& c, Array<Photo*>& photos) {
    int numPhotos = masterlist->size();
    for(int i=0; i <numPhotos;++i){
        if(c.matches(*((*masterlist)[i]))){
            photos.add((*masterlist)[i]);
        }
    }
}

void PhotoGram::displayAlbum(int index, View& v){
    Album* a = (*albumArr)[index];
    v.displayAlbum(*a);
}

int PhotoGram::printAlbums(View& v){
    v.printAlbums(*albumArr);
    return albumArr->size();
}

void PhotoGram::displayPhoto(int index, View& v){
    v.displayPhoto(*((*masterlist)[index]));
}

int PhotoGram::printPhotos(View& v){
    v.printPhotos(*masterlist);
    return masterlist->size();
}