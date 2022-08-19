#include "athlete.h"

using namespace std;

Athlete::Athlete(int id, int age, string name, Role role, int height, int weight, string type, string statName, string stat, string team) : Person(id, age, name, role){
  this->height = height;
  this->weight = weight;
  this->type = type;
  this->statName = statName;
  this->stat = stat;
  this->team = team;
} 

string Athlete::getCsvString(){
  string csvString = Person::getCsvString();
  csvString += "," + to_string(this->height);
  csvString += "," + to_string(this->weight);
  csvString += "," + this->type;
  csvString += "," + this->statName;
  csvString += "," + this->stat;
  csvString += "," + this->team;
  return csvString;
}

void Athlete::printInfo(){ 
  Person::printInfo();
  cout << "Height:  " << this->height << " cm"<< endl;
  cout << "Weight:  " << this->weight << " kg" <<endl;
  cout << "Sport :  " << this->type << endl;
  cout << "Team:    " << this->team << endl;
  cout << this->statName << ":  " << this->stat << endl;
}
Athlete::~Athlete(){
  this->height = 0;
  this->weight = 0;
  this->type = "";
  this->stat = "";
  this->statName = "";
  this->team = "";
}
