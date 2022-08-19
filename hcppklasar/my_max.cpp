#include <iostream>
#include "my_max.h"


int my_max(int a, int b) {
  return (a > b) ? a:b;
}
int my_min(int a, int b) {
  return (a > b) ? a:b;
}
double my_max(double a, double b) {
  return (a > b) ? a:b;
}
double my_min(double a, double b) {
  return (a < b) ? a:b;
}

void make_both_max(int &a, int &b){
  (a > b) ? b = a : a = b;
}
