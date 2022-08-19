#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

/* change return value and/or add parameters*/
void do_operation_on_entire_list(vector<int> &list1, vector<int> &list2, vector<int> &results, int(*func)(int, int), char op){
  
  // Get length of shorter list, to avoid addr out of bounds
  int iter = list1.size() < list2.size() ? list1.size() : list2.size();
      int temp;
      for(int i = 0; i < iter; i++){
        temp = func(list1[i], list2[i]);
        cout << list1[i] << " " <<  op << " " << list2[i] << " = " << temp << endl;
        results.push_back(temp);
    }
}

int add_numbers(int number1, int number2){
    return number1 + number2;
}

int multiply_numbers(int num1, int num2){
  return num1*num2;
}

int subtract_numbers(int num1, int num2){
  return num1-num2;
}

int select_lower(int num1, int num2){
  return num1 < num2 ? num1 : num2;
}

int select_higher(int num1, int num2){
  return num1 > num2 ? num1 : num2;
}

vector<int> read_list(string filename){
    vector<int> vect;
    ifstream fil;
    fil.open(filename, ios::in);
    string line;
    while(getline(fil, line, '\n')){
      vect.push_back(stoi(line));
    }
    fil.close();
    return vect;
}

void print_results(vector<int> &results){
  for(int i = 0; i < results.size(); i++){
    cout << i+1 << ". " << results[i] << endl;
  }
}

int main(){
    
    vector<int> v1 = read_list("numbers01.txt");
    vector<int> v2 = read_list("numbers02.txt");
    vector<int> results;

    int(*holder)(int, int);
    cout << "Available operations: "<< endl;
    cout << "1. Sum " << endl;
    cout << "2. Subtract " << endl;
    cout << "3. Multiply " << endl;
    cout << "4. Get Lower " << endl;
    cout << "5. Get Higher " << endl;
    cout << "Choice (integer value): ";
    
    int choice;
    cin >> choice;
    
    char op;

    switch(choice){
      case 1:
        holder = add_numbers;
        op = '+';
        break;
      case 2:
        holder = subtract_numbers;
        op = '-';
        break;
      case 3:
        holder = multiply_numbers;
        op = '*';
        break;
      case 4:
        holder = select_lower;
        op = '<';
        break;
      case 5:
        holder = select_higher;
        op = '>';
        break;
      default:
        holder = add_numbers;
        op = '+';
        break;
    }

    do_operation_on_entire_list(v1, v2, results, holder, op);

    char p;
    cout << "Print result list?(y/N) ";
    cin >> p;
    if (p == 'y'){
      print_results(results);
    }
}
