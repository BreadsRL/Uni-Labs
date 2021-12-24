#include <iostream>
#include <iomanip>


using namespace std;

int main(){

    float x,s;

    cout << "Enter your age: ";

    cin >> x;


    s = x/1.88090349076;

    cout << setprecision(2) << fixed;

    cout << "On Mars, you would be about " << s << endl;




    return 0;
}
