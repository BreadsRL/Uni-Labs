#ifndef DATE_H
#define DATE_H

#include <string>
#include <ostream>
#include <vector>
#include "duration.h"


struct Date{
    int year;
    int month;
    int day;

    Date(){
        year = 0000;
        month = 00;
        day = 00;
    }

    Date(int year, int month, int day){
        this->year = year;
        this->month = month;
        this->day = day;
    }

    Date(const Date& other){
        this->year = other.year;
        this->month = other.month;
        this->day = other.day;
    }

    Duration operator-(const Date d){
        int total_days = 0;
        int years = year-d.year;
        std::vector<int> days_every_month = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        for(int i = std::min(month, d.month)-1; i < std::max(month, d.month); i++){
            total_days += days_every_month[i];
        }

        if(std::min(month, d.month) == d.month){
            total_days -= d.day;
            total_days -= (days_every_month[month-1] - day);
        } else{
            total_days -= day;
            total_days -= (days_every_month[d.month-1] - d.day);
            total_days = 365-total_days;
            years -= 1;
        }
        
        return Duration(years, total_days);
    }


    bool operator==(const Date d){
        return (year == d.year && month == d.month && day == d.day);
    }

    ~Date(){

    }
};

std::ostream& operator<<(std::ostream& os, Date d){
    os << d.year << "-" << d.month << "-" << d.day;
    return os;
}


#endif
