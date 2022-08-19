#include <iostream>
#include <string.h>

//TODO: Implement compare_strings
using namespace std;
bool compare_strings(char* frst, char* scnd){
  
  if(strcmp(frst, scnd) == 0){
    return true;
  }
  else {
    int a = strlen(frst);
    int b = strlen(scnd);
    int c = a <= b ? a : b;
    cout << "There strings are not identical" << endl;
    cout << "The following indecies differ: ";

    for (int i = 0; i < c; i++){
      if(frst[i] != scnd[i]){
        cout << i << " "; 
      } 
    }

    if(a != b){
      int out = a > b ? (a-b) : (b-a);
      int summnd = a > b ? b : a;
      if(summnd > 0){
      for(int i = 0; i < out; i++){
        cout << i+a << " ";
        }
      }
      cout << endl;
      cout << "Difference in length: ";
      cout << out << endl;;
    }
    return false;
  }
}

int main(){
    char str1[1024];
    char str2[1024];
    cout << "Enter a string: ";
    cin >> str1;
    cout << "Enter a string: ";
    cin >> str2;
    if(compare_strings(str1, str2)){
        cout << "The strings are identical" << endl;
    }
    return 0;
}
