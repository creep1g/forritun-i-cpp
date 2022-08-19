#include "addable.h"

Addable::Addable() {
  this->dbl = 0;
  this->intgr = 0;
}

Addable::Addable(int a, double d) {
  this->dbl = d;
  this->intgr = a;
}

Addable Addable::operator+(const Addable &rhs){
  return Addable(this->intgr + rhs.intgr, this->dbl + rhs.dbl);
}

ostream &operator<<(ostream &out, Addable &a){
  out << "Integer: " << a.intgr << " Real number: " << a.dbl << endl;
  return out;
}


