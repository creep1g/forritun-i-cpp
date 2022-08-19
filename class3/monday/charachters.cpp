#include "charachters.h"
/* #include <iostream> */

using namespace std;


    
/* void Person::add_item(char *name, double bonus){ */

/* } */

Item::Item(){
  this-> id = 0;
  this-> bonus = 0;
}

Item::Item(int id, double bonus){
  this->id = id;
  this->bonus = bonus;
}


Person::~Person(){
  if(items != NULL){
    for(int i = 0; i < item_count; i++){
    delete items[i];
    }
  }
}

void Person::add_item(Item *item){
  Item **tmp_items = new Item*[item_count + 1];

  if(items != NULL){
    for(int i = 0; i < item_count; i++){
      tmp_items[i] = items[i];
    }
    delete[] items;
  }

  items = tmp_items;
  items[item_count] = item;
  item_count++;
}

Person::Person(int height, int stamina, int strength){
  this->height = height;
  this->stamina = stamina;
  this->strength = strength;
  this->items = NULL;
  int item_count;
}



ostream& operator<<(ostream& out, Person& person) {
  out << "Stats: " << person.height << " " << person.stamina << " " << person.strength << endl;
  out << "Items: " << endl;
  for (int i = 0; i < person.item_count; i++){
    out << person.items[i]->id << " " << person.items[i]->bonus << endl;
  }

  return out;
}
ostream& operator<<(ostream& out, Person *person) {
  out << *person;
  return out;
}
