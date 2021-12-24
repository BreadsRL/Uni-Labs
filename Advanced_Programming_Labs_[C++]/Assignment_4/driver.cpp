#include <iostream>
#include "lab4.h"

using namespace std;

int main(){

    cout << "simple_lock(1, 3, 1, 1, 1, 1): " << simple_lock(1, 3, 1, 1, 1, 1) << endl;

    cout << "combo_lock(171, 111):          " << combo_lock(171, 111) << endl;

    cout << "is_perfect(28):                " << is_perfect(28) << endl;

    cout << "next_perfect(76):              " << next_perfect(76) << endl;

    cout << "is_prime(17):                  " << is_prime(17) << endl;

    cout << "next_prime(34):                " << next_prime(34) << endl;

    cout << "is_power(1024, 2):             " << is_power(1024, 2) << endl;

    cout << "gcd(12, 8):                    " << gcd(12, 8) << endl;

    cout << "coprime(125, 20):              " << coprime(125, 20) << endl;

    cout << "phi(17):                       " << phi(17) << endl;

    cout << "sqrt(2, 1, 0.0000001):         " << sqrt(2, 1, 0.0000001) << endl;

}
