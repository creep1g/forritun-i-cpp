#include <iostream>

using namespace std;

int main(){
  int limit = 1;

  while(limit != 0){
    cout << "How high should I count? ";
    cin >> limit;

    for(int i = 0; i <= limit; i++){
      cout << "Now the number is " << i << endl;
    }
  }
};
