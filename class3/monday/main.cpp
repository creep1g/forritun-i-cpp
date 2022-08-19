#include "charachters.h"
using namespace std;

int fall(int& r_r){
  r_r = 9;
  return 0;
}

int main(){
  Person *person = new Person(178, 3, 12);
  
  Item* tmp_item;

  tmp_item = new Item(292, 10);
  person->add_item(tmp_item);

  tmp_item = new Item(182, 29);
  person->add_item(tmp_item);

  tmp_item = new Item(01, 100);
  person->add_item(tmp_item);

  
  cout << person << endl;
  delete person;
  return 0;
}
  /* int *array; */
  /* array = NULL; */
  /* array = new int[8]; */

  /* if (array != NULL){ */
  /*   for(int i = 0; i < 8; i++){ */
  /*     array[i] = i * 2 + 1; */
  /*     cout << "Array["<< i << "]:  " << array[i] << endl; */
  /*   } */
  /* } */
  
  
  /* cout << "array:    " << array << endl; */
  /* cout << "*array:   " << *array << endl; */

  /* delete[] array; */
  /* return 0; */
  /* int a = 4; */
  /* int b = 3; */
  /* int& r_a = a; // Reference a; */

  /* int *p0 = NULL; // Null pointer */
  /* int *p; // set pointer */
  /* p = &b; */



  /* cout << "a:    " << a << endl; */
  /* cout << "b:    " << b << endl; */
  /* cout << "&b:   " << &b << endl; // these are the same */
  /* cout << "p:    " << p << endl; */
  /* cout << "*p:   " << *p << endl; */
  /* cout << "r_a:  " << r_a << endl; */

  /* a = b; */
  /* b = 23; */

  /* cout << "a:    " << a << endl; */
  /* cout << "b:    " << b << endl; */
  /* cout << "&b:   " << &b << endl; // these are the same */
  /* cout << "p:    " << p << endl; */
  /* cout << "*p:   " << *p << endl; */
  /* cout << "r_a:  " << r_a << endl; */

/* } */ 
