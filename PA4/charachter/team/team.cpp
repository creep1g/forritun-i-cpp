#include "team.h"

Team::Team(string name, string location, string statistic, string sport, string stat, string competitionName){
  this->name = name;
  this->location = location;
  this->statistic = statistic;
  this->stat = stat;
  this->competitionName = competitionName;
  this->sport = sport;
}

string Team::getSport(){
  return this->sport;
}

void Team::addPerson(Person *p){
  if(roster.empty()){
    roster.insert(make_pair(1, p));
  }
  else{
    roster.insert(make_pair(roster.end()->first, p));
  }

  //updateTeam
}

void Team::printRoster(){
  for (auto iter = roster.begin(); iter != roster.end(); ++iter){
      cout << iter->first << ":    " << iter->second->getName() << "  "  << iter->second->getRole() << endl;
  }
}

void Team::printInfo(){
  cout << "Name:  " << this->name << endl;
  cout << "Location:  " << this->location << endl;
  cout << "Sport:  " << this->sport << endl;
  cout << "Statistic:  " << this->statistic << endl;
  cout << "Stat. value:  " << this->stat << endl;
}

string Team::getCsvString(){
  string out = "";
  out += this->name + ",";
  out += this->location + ",";
  out += this->statistic + ",";
  out += this->stat + ",";
  out += this->sport + ",";
  out += this->competitionName + ",";
  return out;
}


string Team::getName(){
  return this->name;
}
