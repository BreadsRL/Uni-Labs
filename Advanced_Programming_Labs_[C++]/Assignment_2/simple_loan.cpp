#include <iostream>
#include <iomanip>

using namespace std;

int main(){

    float x,y,z;

    cout << "Enter loan amount: ";

    cin >> x;

    cout << "Enter load period (months): ";

    cin >> y;

    z = x/y;

    cout << setprecision(2) << fixed;

    cout << "You owe $" << z << " per month." << endl;




    return 0;
}
