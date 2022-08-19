#include <iostream>

using namespace std;

class Car{
public:
    Car(){
        my_string = "I am a car. ";
    }
    void who_am_i(){ cout << my_string; }
protected:
    string my_string;
};

class Toyota : public Car{
public:
    Toyota() : Car(){
        my_string += "My name is Toyota";
    }
};

class Corolla : public Toyota{
public:
    Corolla() : Toyota(){
        my_string += " Corolla";
    }
};

int main(){
    Car *car = new Corolla();
    car->who_am_i();
}
