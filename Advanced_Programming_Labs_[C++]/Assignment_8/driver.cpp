#include <iostream>
#include "stash.h"

using namespace std;

int main(){
    Stash s;
    Stash temp;
    temp.append(11);
    temp.append(12);

    s.append(5);
    s.append(7);
    s.append('A');
    s.append(temp);

    cout << temp << endl;
    cout << s << endl;
}
