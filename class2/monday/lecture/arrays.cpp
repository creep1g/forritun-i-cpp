
#include <iostream>

#define ARRAY_SIZE 4

using namespace std;

void write_text(){
  cout << "Let's do arrays!" << endl;
}

int main(){
  write_text();
 
  int array_of_ints[8] = {};

  int my_int = 34;

  double my_double = 34.234;
  double array_of_doubles[ARRAY_SIZE] = {};
  double tmp_double;

  for (int i = 0; i < ARRAY_SIZE; i++){
    cout << "Value number " << i << ": ";
    cin >> tmp_double;
    array_of_doubles[i] = tmp_double;
  }

  cout << "How big is any int: " << sizeof(int) << endl;
  cout << "How big is any double: " << sizeof(double) << endl;
  cout << "How big is my integer: " << sizeof(my_int) << endl;
  cout << "How big is my double: " << sizeof(my_double) << endl;
  cout << "How big is my integer array: " << sizeof(array_of_ints) << endl;
  cout << "How big is my integer array: " << sizeof(array_of_doubles) << endl;
  cout << "How many values? : " << sizeof(array_of_doubles)/sizeof(double) << endl;

  cout << "Here are the memory address: " << array_of_doubles << endl;


  for(int i = 0; i < ARRAY_SIZE; i++){
    cout << "Value number " << i << " is " << array_of_doubles[i] << endl;
  }

  int tmp_int; 
  while(true) {
    cout << "Which value to show? ";
    cin >> tmp_int;
    cout << "This is the value: " << array_of_doubles[tmp_int] << endl;
    }
}

