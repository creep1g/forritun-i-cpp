#ifndef SPECIALCONTAINER_H_4457345
#define SPECIALCONTAINER_H_4457345

#include "keyed_container.h"
#include <fstream>
#include <string>
using namespace std;
struct NumericData{
    int id;
    int place;
    double amount;
};

//TODO: Implement SpecialContainer

class SpecialContainer :  public KeyedContainer <int, NumericData> {
  public:
  void write_to_file(string filename);
  void read_from_file(string filename);
  virtual ~SpecialContainer();
};
#endif //SPECIALCONTAINER_H_4457345
