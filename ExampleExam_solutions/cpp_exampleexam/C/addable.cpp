#include "addable.h"

#include <fstream>
#include <chrono>

Addable::Addable(){
    integer = 0;
    realnumber = 0.0;
}

Addable::Addable(int i, double d){
    integer = i;
    realnumber = d;
}


Addable Addable::operator+(const Addable &other){
    return Addable(this->integer + other.integer, this->realnumber + other.realnumber);
}

ostream &operator<<(ostream &out, const Addable &addable){
    out << "integer: " << addable.integer << ", real number: " << addable.realnumber;
    return out;
}

vector<Addable> Addable::add_and_return(int count){
    srand(std::chrono::system_clock::to_time_t(std::chrono::system_clock::now()));
    vector<Addable> collection;
    for(int i = 0; i < count; i++){
        Addable add1(rand() % 100, (double)(rand() % 10000) / 10000);
        Addable add2(rand() % 100, (double)(rand() % 10000) / 10000);
        Addable add3 = add1 + add2;
        collection.push_back(add1);
        collection.push_back(add2);
        collection.push_back(add3);
    }
    return collection;
}

void Addable::print_addables_to_terminal(vector<Addable> collection){
    for(Addable add : collection){
        cout << add << endl;
    }
}

void Addable::write_addables_to_file(std::string filename, vector<Addable> collection){
    ofstream fout(filename, ios::binary);
    int collection_size = collection.size();
    fout.write((char *)(&collection_size), sizeof(int));
    fout.write((char *)(&collection[0]), sizeof(Addable) * collection_size);
    // THIS IS TRICK - &collection[0]
    // The memory address to the first item in the vector is also the beginning of the underlying array
    // It works because Addable only has instance variables on the stack
    // If there were variables pointing to dynamically allocated memory on the heap
    // the program would need to serialize all of that individually
}

vector<Addable> Addable::read_addables_from_file(std::string filename){
    ifstream fin(filename, ios::binary);
    int collection_size;
    fin.read((char *)(&collection_size), sizeof(int));
    vector<Addable> collection(collection_size);
    fin.read((char *)(&collection[0]), sizeof(Addable) * collection_size);
    return collection;
}
