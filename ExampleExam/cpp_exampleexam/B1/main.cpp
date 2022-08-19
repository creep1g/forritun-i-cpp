#include <iostream>
#include "add.h"

using namespace std;

int main(){
    int a, b;
    cout << "Enter an integer: ";
    cin >> a;
    cout << "Enter an integer: ";
    cin >> b;
    cout << "The sum of the integers is " << add(a, b) << endl;
    return 0;
}
