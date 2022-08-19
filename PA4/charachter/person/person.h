#ifndef PERSON_121
#define PERSON_121
#include <iostream>
#include <stdlib.h>

using namespace std;

  enum class Role{
    None = 0,
    Athlete,
    Coach,
};

class Person{
public:
  Person();
  Person(int id = rand()%124+9999, int age=0, string name="John Doe", Role role = Role::None);
  virtual ~Person();
  virtual void printInfo();
  virtual string getCsvString();
  virtual string getRole();
  string getName();
protected:
  Role role;
  int id;
  int age;
  string name;
};

#endif
