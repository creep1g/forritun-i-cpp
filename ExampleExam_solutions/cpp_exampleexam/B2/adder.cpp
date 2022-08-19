#include "adder.h"

Adder::Adder(int number){
    this->number = number;
}

int Adder::add(int added){
    return this->number + added;
}