#ifndef RESULT_H_11987234
#define RESULT_H_11987234
#include <string>
#include <iostream>
using namespace std;
class Result{
  public:
    //Constructors
    Result();
    Result(string,int, double, bool);
    Result(const Result &res);

  private: 
    // Data vars
    string analyst;
    int    count;
    double amount;
    bool   confirmed;

  public:
    // Operations
    string get_analyst();
    int    get_count();
    double get_amount();
    bool   get_confirmed();

    void   set_analyst(string);
    void   set_count(int);
    void   set_amount(double);
    void   set_confirmed(bool);

    friend ostream &operator<<(ostream &out, Result &R1);
}; 


#endif //RESULT_H_11987234
