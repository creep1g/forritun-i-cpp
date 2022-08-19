#include <iostream>
#include <fstream>

using namespace std;

void read_file_and_add();

int main(){
    read_file_and_add();
    return 0;
}

void read_file_and_add(){ 
  
  string filename;
  while(1){
    cout << "Enter name of file: ";
    cin >> filename;
    if (filename.substr(filename.size() - 4) == ".txt"){
      break;
    }
    cout << "Only accepts .txt files" << endl;
  }
  ifstream file(filename);
  string line;
  string tkn;
  int fst;
  int scnd;
  int count;
  while(getline(file, line, ' ')){
    if(count == 1){
      scnd = stoi(line);
      cout << "The sum of " << fst << " and " << scnd << " is " << fst+scnd << endl; 
      count = 0;
    } else{
      fst = stoi(line);
    }
    count++;
  }

}
