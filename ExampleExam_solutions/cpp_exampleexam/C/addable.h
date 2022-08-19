#ifndef ADDABLE_H_4457345
#define ADDABLE_H_4457345

#include <iostream>
#include <vector>

using namespace std;

class Addable{
public:
    Addable();
    Addable(int i, double d);

    Addable operator+(const Addable &other);
    friend ostream &operator<<(ostream &out, const Addable &addable);

    static vector<Addable> add_and_return(int count);
    static void print_addables_to_terminal(vector<Addable> collection);
    static void write_addables_to_file(std::string filename, vector<Addable> collection);
    static vector<Addable> read_addables_from_file(std::string filename);
private:
    int integer;
    double realnumber;
};

#endif //ADDABLE_H_4457345