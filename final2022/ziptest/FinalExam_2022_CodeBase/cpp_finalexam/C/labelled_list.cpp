#include "labelled_list.h"

/***** USE THIS AS A HELPER IF NEEDED OR COPY CODE OR WHATEVER *****/
#include <iostream>
void print_data(NumericData nd){
    std::cout << "id:" << nd.id << ", place:" << nd.place << ", amount:" << nd.amount;
}

/***** IMPLEMENT YOUR OPERATIONS HERE *****/


void LabelledList::add(string label, NumericData data){
  this->label_list[label] = data;
}

void LabelledList::print_list(){
  for(auto iter = this->label_list.begin(); iter != this->label_list.end(); ++iter){
  cout << iter->first << ": ";
  print_data(iter->second); 
  cout << endl;
  }
}

