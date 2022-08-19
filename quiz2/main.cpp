#include <iostream>
using namespace std;

int* operation (){
  int array_1[10];
  int *array_2 = new int[10];
  array_2[2] = 10;

  return array_2;
}

int main(){

  cout << "First Go:" << endl;
  int *ip = operation();

  cout << ip[2] << endl;


}
