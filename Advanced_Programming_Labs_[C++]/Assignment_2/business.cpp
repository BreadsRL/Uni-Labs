#include <iostream>
#include <cmath>



using namespace std;

int main(){

    int a,b,c,x,y;

    cout << "Enter your current bank balance: ";

    cin >> a;

    cout << "Projected monthly operational expenses: ";

    cin >> b;

    cout << "Projected monthly income from operations: ";

    cin >> c;

    cout << "Gross burn rate: $" << b << endl;

    x = b - c;

    cout << "Net burn rate: $" << x << endl;

    y = a/x;

    cout << "Projected runway: " << y << " months" << endl;



    return 0;
}
