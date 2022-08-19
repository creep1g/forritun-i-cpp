#include "adder.h"

Adder::Adder(int a){
  this->a = a;
}

Adder::Adder(){
  this->a = 0;
}

int Adder::add(int b){
  return this->a + b;
}
