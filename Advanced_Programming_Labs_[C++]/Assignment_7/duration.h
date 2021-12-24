#ifndef DURATION_H
#define DURATION_H

#include <ostream>

struct Duration{
    int years;
    int days;
    Duration(){
        years = 0;
        days = 0;
    }
    Duration(int years, int days){
        int negative;
        days += years * 365;
        years = 0;
        if(days!=0){
            negative = days/days;
        } else{
            negative = 1;
        }

        this->years = days / 365;
        this->days = (days % 365) * (negative);
    }
    Duration(const Duration& other){
        years = other.years;
        days = other.days;
    }
    Duration operator+(const Duration& d){
        int total_years = years + d.years;
        int total_days = days + d.days;
        return Duration(total_years, total_days);
    }
    Duration operator/(const int n){
        int total_years = years / n;
        int total_days = days / n;
        return Duration(total_years, total_days);
    }
    ~Duration(){
    }
};
std::ostream& operator<<(std::ostream& os, Duration d){
    os << d.years << " years, " << d.days << " days";
    return os;
}




#endif
