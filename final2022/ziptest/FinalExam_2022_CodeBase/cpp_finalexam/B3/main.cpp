#include <iostream>
#include "result.h"
#include <vector>
#include <fstream>

using namespace std;

vector<Result> read_results_from_file(string filename){

  vector<Result> results;
  ifstream resfile;
  resfile.open(filename, ios::in);
  
  // Reading everything into strings and than converting to 
  // propper instances.
  string analyst;
  string count;
  string amount;
  string confirmed;
  
  string line; // line buffer

  string::size_type sz;

  while(getline(resfile, line, '\n')){
    
    analyst = line.substr(0, line.find(" "));
    line.erase(0, analyst.length() + 1);
    count = line.substr(0, line.find(" "));
    line.erase(0, count.length() + 1);
    amount = line.substr(0, line.find(" "));
    line.erase(0, amount.length() + 1);
    confirmed = line.substr(0, line.find("\n"));
    results.push_back(Result(
          analyst,
          stoi(count.c_str()),
          stod(amount.c_str(), &sz),
          stoi(confirmed.c_str())));
  }
  
  return results;
}

int main(){
    auto results = read_results_from_file("result_test_file.txt");
    for(auto result : results){
        cout << result << endl;
    }
    return 0;
}
