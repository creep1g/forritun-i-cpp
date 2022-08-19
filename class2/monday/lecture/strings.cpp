#include <iostream> 
#include <string.h>

using namespace std;

#define ARRAY_SIZE 8

void write_text(){
  cout << "Let's do strings!" << endl;
}

int main(){
  write_text();

  char my_string[16];
  cout << "Enter a string: ";
  cin >> my_string;

  cout << "My string: " << my_string << endl;

  if (strcmp(my_string, "Penis") == 0){
    cout << "out" << endl;
  }
}

