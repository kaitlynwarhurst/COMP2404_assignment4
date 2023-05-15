
#ifndef PHOTO_H
#define PHOTO_H

#include <iostream>
#include <string.h>
#include <stdio.h>
#include "Date.h"
#include <iomanip>

using namespace std;

class Photo{
    friend ostream& operator<<(ostream&,const Photo&);
    private:
        string photoContent;
        string photoTitle;
        string photoCategory;
        Date photoDate;
    public:
        //constructors
        Photo(const string& titile, const string& category, const Date& date, const string& content);
        Photo();
        Photo(const Photo& photo1);

        void print(ostream&) const;
        void display(ostream&) const;
        bool equals(const string& title);

        //getters
        const string& getCategory() const;
        const Date& getDate() const;


};

#endif