#include "person.h"

Person::Person(){
  this->name = "John Doe";
  this->age = 0;
}

string Person::getName(){
  return this->name;
}

string Person::getRole(){
  if(this->role == Role::Athlete){
    return "Athlete";
  }
  else{
    return "Coach";
  }
}

string Person::getCsvString(){
  string csvString = "";
  csvString += to_string(this->id);
  csvString += "," + this->name;
  csvString += "," + to_string(this->age); 
  return csvString;

}

Person::Person(int id, int age, string name, Role role){
  this->name = name;
  this->age = age;
  this->role = role;
  this->id = id;
}

Person::~Person(){
  this->age = 0;
  this->name = "";
  this->role = Role::None;
}

void Person::printInfo(){
  cout << "Name  :  " << this->name << endl;
  cout << "Age   :  " << this->age << endl;
  if (this->role != Role::None){
    string out;
    switch(this->role){
      case Role::Athlete:
        out = "Athlete";
        break;
      case Role::Coach:
        out = "Coach";
        break;
      default:
        out = "";
        break;
    }
    cout << "Role  :  " << out << endl;
  }
}

