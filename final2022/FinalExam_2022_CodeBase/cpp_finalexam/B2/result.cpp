#include "result.h"

Result::Result(){
  this->analyst = "";
  this->count = 0;
  this->amount = 0;
  this->confirmed = false;
}

Result::Result(string analyst, int count, double amount, bool confirmed){
  this->analyst = analyst;
  this->count = count;
  this->amount = amount;
  this->confirmed = confirmed;
}


Result::Result(const Result &R1){
  this->analyst = R1.analyst;
  this->count = R1.count;
  this->amount = R1.amount;
  this->confirmed = R1.confirmed;
}

void Result::set_analyst(string analyst){
  this->analyst = analyst;
}

void Result::set_count(int count){
  this->count = count;
}

void Result::set_amount(double amount){
  this->amount = amount;
}

void Result::set_confirmed(bool confirmed){
  this->confirmed = confirmed;
}

string Result::get_analyst(){
  return this->analyst;
}

int Result::get_count(){
  return this->count;
}

double Result::get_amount(){
  return this->amount;
}

bool Result::get_confirmed(){
  return this->confirmed;
}



ostream &operator<<(ostream &out, Result &R1){
  string conf;
  if(R1.confirmed){
    conf = "confirmed";
  }
  else{
    conf = "not confirmed";
  }
  out << "Analyst: " << R1.get_analyst() << endl << "Count: " << R1.get_count() << endl << "Amount: " << R1.get_amount() << endl << "Confirmed: " << conf << endl;
  return out;
}
