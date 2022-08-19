#ifndef COACH_121
#define COACH_121
#include <iostream>
#include <stdlib.h>
#include "../person/person.h"
using namespace std;

class Coach : public Person{
public:
  Coach(int id = rand()%124+9999, int age = 0, string name = "Coach. John Doe", Role role = Role::Coach, string team = "", string startDate = "01.01.1970", string sport = "Boccia");
  void printInfo();
  string getCsvString();
  
protected:
  string team;
  string startDate;
  string sport;
};
#endif
