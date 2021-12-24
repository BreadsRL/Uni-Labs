#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;


int main(){

    float P,N,s,r,x;

    cout << "Enter loan amount: ";

    cin >> P;
    
    cout << "Enter load period (months): ";

    cin >> N;

    cout << "Enter annual interest rate (percentage): ";

    cin >> r;

    r *= 0.01/12;

    x = ((P*r*(pow(1+r,N)))/(pow(1+r,N)-1));

    cout << setprecision(2) << fixed;
    
    cout << "You owe $ " << x << " per month." << endl;


    return 0;
}
