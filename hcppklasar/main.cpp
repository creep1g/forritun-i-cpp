#include <iostream> 
#include "my_max.h"

using namespace std;

int main() { 
  cout << "Kennslustund, vika 3" << endl;

  int x, y;

  cout << "type an integer: ";
  cin >> x;
  cout << "Type another integer: ";
  cin >> y;

  int bigger_of_two = my_max(x, y);

  cout << "The larger integer is : " << bigger_of_two << endl;
  cout << x << " and " << y << endl;
  make_both_max(x, y);
  cout << x << " and " << y << endl;

  return 0;
}
