#ifndef ADDABLE_H_4457345
#define ADDABLE_H_4457345
#include <iostream> 
using namespace std;
class Addable{
public:
  Addable();
  Addable(int, double);
  Addable operator+(const Addable &rhs);
  friend ostream &operator<<( ostream &out, Addable &a); 
private:
  double dbl;
  int intgr;
}; 
#endif //ADDABLE_H_4457345
