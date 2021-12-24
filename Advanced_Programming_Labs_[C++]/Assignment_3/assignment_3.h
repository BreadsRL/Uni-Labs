#ifndef ASSIGNMENT_3_H
#define ASSIGNMENT_3_H

#include <string>


float wages(int hours, float rate){

    if (hours > 40){

        int x = hours - 40;

        float y = (x * rate * 1.5)+(40 * rate);
        return y;
    }

       float z = hours * rate;
        return z;

}

bool canDonateBlood(std::string donor, std::string recipient){

    if (donor == "A" && (recipient == "A" || recipient == "AB")){

        return true;
    }
    else if (donor == "B" && (recipient == "B" || recipient == "AB" )){

        return true;
    }
    else if (donor == "AB" && (recipient == "AB")){

        return true;
    }
    else if (donor == "O" && (recipient == "A" || recipient == "B" || recipient == "AB" || recipient == "O")){

        return true;
    }

    return false;
}

bool leap(int year){

    if (year % 400 == 0){

        return true;
    }

    else if (year % 4 == 0 && year % 100 != 0){

        return true;
    }
    
    return false;
}

int daysInMonth(int month, int year){

    if (month == 4 || month == 6 || month == 9 || month == 11){

        return 30;
    }

    if (month == 2){

        return 28 + int(leap(year));
    }

    return 31;
}

bool pointInRect(float x, float y, float rx, float ry, float rw, float rh){

    if (x >= rx && x <= (rx+rw) && y <= ry && y >= (ry-rh)){

        return true;
    }

    return false;
 
}

bool rectInRect(float x1, float y1, float w1, float h1, float x2, float y2, float w2, float h2){

    if (pointInRect(x1,y1,x2,y2,w2,h2) == true && pointInRect((x1+w1),(y1-h1),x2,y2,w2,h2) == true){

        return true;
    }

    return false;
}

bool overlap(float x1, float y1, float w1, float h1, float x2, float y2, float w2, float h2){

    if (x2+w2 < x1 || x1+w1 < x2 || y2-h2 > y1 || y1-h1 > y2 ){
        
        return false;
    }

    return true;
    
}


#endif

