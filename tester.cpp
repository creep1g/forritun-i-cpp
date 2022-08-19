#include <iostream>

using namespace std;


class ThisClass {
    virtual void do_stuff(int a) = 0;
};

class Name{
  public:
  Name(){
    a = 0;
  }

  int a;
};


void test(Name &inst){
  inst.a = inst.a+2;
}

void test2(Name inst){
  inst.a = inst.a+2;
}

int main(){
  Name b = Name();
  test(b);
  cout << b.a << endl;
  test2(b);
  cout << b.a << endl;
  int arr_one[10];
  arr_one[2] = 2;
  int *arr_two = new int[10];
  arr_two[2] = 2;
  cout << arr_one[2] << endl;
  cout << arr_two[2] << endl;
  ThisClass k;
}
