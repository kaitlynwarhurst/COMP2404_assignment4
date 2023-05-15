#ifndef CRITERIA_H
#define CRITERIA_H

#include "defs.h"
#include "Photo.h"


class Criteria{
    friend ostream& operator<<(ostream&, const Criteria&);
    public:
        virtual bool matches(const Photo&)const  =0;
        virtual void print(ostream&)const  =0; 
};

class Cat_Criteria:  virtual public Criteria{
    private:
        string category;

    public:
        Cat_Criteria(const string& category);
        virtual bool matches(const Photo&) const;
        virtual void print(ostream&) const;
};

class Date_Criteria: virtual public Criteria{
    private:
        Date start;
        Date end;
    public:
        Date_Criteria(const Date& startDate, const Date& endDate);
        virtual bool matches(const Photo&) const;
        virtual void print(ostream&) const;

};

class CandD_Criteria: public Cat_Criteria, public Date_Criteria{
    public:
        CandD_Criteria(const Date& startDate, const Date& endDate,const string& category);
        virtual bool matches(const Photo&) const;
        virtual void print(ostream&) const;
};



#endif