#ifndef LABELLEDLIST_H_77447345
#define LABELLEDLIST_H_77447345
#include <map>
#include <string>

using namespace std;

struct NumericData{
    int id;
    int place;
    double amount;
};


class LabelledList{
  public:
    void add(string, NumericData);
    void print_list();
    std::map<string, NumericData> label_list;

};



#endif //LABELLEDLIST_H_77447345
