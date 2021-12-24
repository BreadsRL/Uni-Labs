#include <iostream>

using namespace std;

int main(){

    int x,s;

    cout << "Enter your age: ";
    
    cin >> x;

    s = x*(365.25*24*60*60);

    cout << "You are " << s << " seconds old." << endl;


    return 0;
}
