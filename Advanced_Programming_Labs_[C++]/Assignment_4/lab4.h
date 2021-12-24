#ifndef LAB4_H
#define LAB4_H

#include <iostream>
#include <cmath>
#include <vector>
 
int simple_lock(int x1, int x2, int x3, int y1, int y2, int y3){

    int counter = 0;
    int combo[3] = {x1,x2,x3};
    int setting[3] = {y1,y2,y3};

    for(int x = 0; x<3; x++){

        if (abs(combo[x]-setting[x])<=5){
            counter += abs(combo[x]-setting[x]);
        }
        else{
            counter += 9-abs(combo[x]-setting[x]);
        }

    }

    return counter;
}

int combo_lock(int current, int unlock){

    int counter = 0;
    int i = current;
    int h = unlock;
    std::vector<int> combo_v;
    std::vector<int> unlock_v;

    while(i){

        combo_v.push_back(i % 10);
        unlock_v.push_back(h % 10);

        i /= 10;
        h /= 10;

    }

    for (int x = 0; x < combo_v.size(); x++){

        if (abs(combo_v.at(x)-unlock_v.at(x))<=5){
            counter += abs(combo_v.at(x)-unlock_v.at(x));
        }
        else{
            counter += 9-abs(combo_v.at(x)-unlock_v.at(x));
        }
    }

    return counter;
}

bool is_perfect(int n){

    int counter = n-1;
    int y = 0;

    while (counter > 0){

        if (n % counter == 0) {
            y += counter;
        }

        counter --;
    }

    return n == y;
}

int next_perfect(int n){

    int next_p = n;

    while (is_perfect(next_p) == false){

        next_p++;
    }

    return next_p;

}

bool is_prime(int x){

    int checker = x-1;

    if (x == 1){
        
        return false;

    }

    while (checker > 1){

        if (x % checker == 0){

            return false;

        }

        checker--;

    }

    return true;

}

int next_prime(int n){

    int next_p = n;

    while (is_prime(next_p) == false){

        next_p++;
    }

    return next_p;
}

bool is_power(int number, int base){

    int power = 1;

    while (pow(base,power) < number){

        power++;

    }

    return pow(base,power) == number;

}

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

bool coprime(int x, int y){

    if (gcd(x,y) == 1){

        return true;
    }

    return false;
}

int phi(int n){

    int counter = 0;
    int checker = n-1;

    while (checker>0){

        counter += int(coprime(checker,n));

        checker--;
    }

    return counter;
}

double sqrt(double a, double x, double epsilon){

    double xy = x;

    while ((xy - (a/xy)) > epsilon || ((a/xy) - xy) > epsilon){

        xy = ((xy) + (a/xy)) / 2;

    }

    return xy;

}


#endif
