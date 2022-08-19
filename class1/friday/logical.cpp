#include <iostream>
using namespace std;

int main(){
  char c1;
  char c2;
  cout << "Enter character: ";
  cin >> c1;
  cout << "Enter next character: ";
  cin >> c2;

  if (c1 == 'g' && c2 == 'g'){
    cout << "Both characters are 'g' or 'k' " << endl;
  }

  else if (c1 == 'g' || c2 == 'g')  {
    cout << "one of the characters is 'g'" << endl;
  }

  else {
    cout << "Neither character is 'g'" << endl;
  }
}
