#include "Photo.h"

using namespace std; 


Photo::Photo(){
    photoTitle = "unknown";
    photoContent = "unknown";
    photoCategory = "unknown";
    photoDate = Date();
}

Photo::Photo(const string& title, const string& category, const Date& date, const string& content){
    photoTitle = title;
    photoDate = date;
    photoContent = content;
    photoCategory = category;
}

Photo::Photo(const Photo& photo1){
    photoTitle = photo1.photoTitle;
    photoDate = Date(photo1.photoDate);
    photoContent = photo1.photoContent;
}

bool Photo::equals(const string& title){
    if(title == photoTitle) return true;
    return false;
}

void Photo::print(ostream& ost) const{
    ost<< "Photo title: "<< photoTitle << "Category: " << photoCategory<<" Date: " << endl;
    ost<<photoDate;
}

void Photo::display(ostream& ost) const{
    ost<< "Photo title: "<< photoTitle << " Category: " << photoCategory<< " Date: " << endl;
    ost<<photoDate;
    ost<< endl << "Content: " << photoContent << endl; 
}

const string& Photo::getCategory() const{
    return photoCategory;
}

const Date& Photo::getDate() const{
    return photoDate;
}

ostream& operator<<(ostream& ost,const Photo& p){
    p.print(ost);
    return ost;
}




