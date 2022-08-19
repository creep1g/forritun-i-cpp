#include "coach.h"

Coach::Coach(int id, int age, string name, Role role, string team, string startDate, string sport) : Person(id, age, name, role){
  this->team = team;
  this->startDate = startDate;
  this->sport = sport;
}

void Coach::printInfo(){
  Person::printInfo();
  cout << "Team  :  " << this->team << endl;
  cout << "Sport :" << this->sport << endl; 
  cout << "Since : " << this->startDate << endl;
}

string Coach::getCsvString(){
  string csvString = Person::getCsvString();
  csvString += ",", this->team + "," + "this->startDate" + "," + this->sport;
  return csvString;
}
