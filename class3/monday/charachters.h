#ifndef CHARACTERS_98aeo7guOUEO
#define CHARACTERS_98aeo7guOUEO

#include <iostream>
using namespace std;

class Item{
  public:
    Item();
    Item(int id, double bonus);

    int id;
    double bonus;
};

class Person {
  public:
    Person(int height, int stamina, int strength);

    virtual ~Person();
    
    /* void add_item(char *name, double bonus); */
    void add_item(Item* item);

    friend ostream& operator<<(ostream& out, Person *person);
      
    friend ostream& operator<<(ostream& out, Person& person);

  private:
    int height;
    int stamina;
    int strength;
    int item_count;    
    Item **items;
};


#endif
