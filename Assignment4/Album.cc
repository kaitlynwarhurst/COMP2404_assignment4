#include "Album.h"

Album::Album(const string& title, const string& description){
    albumTitle = title;
    albumDescription = description;
    albumPhotos = new Array<Photo*>();
}

/*Album::Album(const Album& album){
    albumTitle = album.albumTitle;
    albumDescription = album.albumDescription;
    //PhotoArray temp = *album.albumPhotos;
    albumPhotos = new Array<Photo*>();
}*/

Album::~Album(){
    int albumSize = albumPhotos->size();
    albumPhotos->clear();
    delete [] albumPhotos;
}

string Album::titleGetter() const{
    return albumTitle;
}

bool Album::equals(const string& title) const{
    if(albumTitle == title) return true;
    return false;
}

bool Album::lessThan(const Album& alb) const{
    if(albumTitle< alb.albumTitle) return true;
    return false;
}

void Album::addPhoto(Photo* ptr){
    albumPhotos->add(ptr);
}

/*bool Album::addPhoto(int index, Photo* ptr){
    return albumPhotos->add(index, ptr);
}*/

/*Photo* Album::getPhoto(const string& title) const{
    return albumPhotos->get(title);
}*/

Photo* Album::getPhoto(int index) const{
    Photo* p= (*albumPhotos)[index];
    return p;
}

/*Photo* Album::removePhoto(const string& title) {
    return albumPhotos->remove(title);
}

Photo* Album::removePhoto(int index){
    return albumPhotos->remove(index);
}*/

void Album::print(ostream& ost) const{
    ost<< "Album Title: " << albumTitle << " Description: " << albumDescription << endl;
}

void Album::display(ostream& ost) const{
    print(ost);
    int numPhotos= albumPhotos->size();
    for(int i=0;i<numPhotos;++i){
        (*albumPhotos)[i]->display(ost);
    }
}

int Album::size() const{
    return albumPhotos->size();
}

string Album::getTitle() const{
    return albumTitle;
}

ostream& operator<<(ostream& ost, const Album& a){
    a.print(ost);
    return ost;
}