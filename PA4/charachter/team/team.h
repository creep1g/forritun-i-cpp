#ifndef TEAM_121
#define TEAM_121
#include <iostream>
#include <bits/stdc++.h>
#include "../athlete/athlete.h"
#include "../coach/coach.h"

using namespace std;

class Team{
public:
  Team(string name="team", string location="Reykjavik", string statistic="wins", string sport = "boccia", string stat="21 wins", string competitionName="PL");
  void addPerson(Person *p);
  void printRoster();
  void printInfo();
  string getCsvString();
  string getName();
  string getSport();
private:
  string name;
  string location;
  string sport;
  string statistic;
  string stat;
  string competitionName;
  map <int, Person*> roster;
};


#endif
