#ifndef ATHLETE_121
#define ATHLETE_121
#include <iostream>
#include "../person/person.h"
class Person;
enum class Role;

using namespace std;
class Athlete : public Person{
  public:
  Athlete(int id = rand()%124+9999, int age = 0, string name = "John Doe", Role role = Role::None, int height = 0, int weight = 0, string type = 0, string statName = "", string stat = "", string team = "wolfs");
  virtual ~Athlete();
  void printInfo();
  string getCsvString();

  protected:
    int height;
    int weight;
    string team;
    string type;
    string statName;
    string stat;
};

#endif
