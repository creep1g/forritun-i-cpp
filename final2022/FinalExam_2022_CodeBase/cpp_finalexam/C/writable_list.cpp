#include "writable_list.h"
#include <fstream>

void WritableList::write_to_file(string filename){
  ofstream fil;
  fil.open(filename, ios::binary);
  fil.write(reinterpret_cast<char*>(this), sizeof(*this));
  fil.flush();
  fil.close();
}

void WritableList::read_from_file(string filename){
  ifstream fil;
  fil.open(filename, ios::binary);
  fil.read(reinterpret_cast<char*>(this), sizeof(*this));
  fil.close();

}
