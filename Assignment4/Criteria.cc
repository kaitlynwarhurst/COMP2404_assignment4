#include "Criteria.h"

//Criteria Functions
ostream& operator<<(ostream& ost, const Criteria& c) {
    c.print(ost);
    return ost;
}

//Cat_Criteria Functions
Cat_Criteria::Cat_Criteria(const string& cat){
    category = cat;
}

bool Cat_Criteria::matches(const Photo& p) const{
    if(p.getCategory()== category) return true;
    return false;
}

void Cat_Criteria::print(ostream& ost) const{
    ost<< "Criteria matching mathces photo category. The current category is " <<category<<"." << endl;
}

//Date_Criteria Functions
Date_Criteria::Date_Criteria(const Date& startDate, const Date& endDate){
    start = startDate;
    end = endDate;
}

bool Date_Criteria::matches(const Photo& p) const{
    if(!(p.getDate()<start)){
        if(p.getDate() <= end) return true;
    } 
    return false;
}

void Date_Criteria::print(ostream& ost) const{
    ost<< "Checking if the photo date is between the date range. Start date: "<< start<< " End Date: "<< end <<endl;
}

//CandD_Criteria Functions

CandD_Criteria::CandD_Criteria(const Date& startDate, const Date& endDate,const string& category):Cat_Criteria(category), Date_Criteria(startDate, endDate){

}

bool CandD_Criteria::matches(const Photo& p) const{
    return Cat_Criteria::matches(p) && Date_Criteria::matches(p);
}

void CandD_Criteria::print(ostream& ost) const{
    Cat_Criteria::print(ost);
    Date_Criteria::print(ost);
}