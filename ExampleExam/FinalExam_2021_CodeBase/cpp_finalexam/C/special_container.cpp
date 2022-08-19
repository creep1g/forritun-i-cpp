#include "special_container.h"

using namespace std;

void SpecialContainer::write_to_file(string filename){
  ofstream fil;
  fil.open(filename, ios::binary);
  fil.write((char*)this, sizeof(SpecialContainer));
  fil.close();
}

void SpecialContainer::read_from_file(string filename){
  ifstream fil;
  fil.open(filename, ios::binary);
  fil.read((char*)this, sizeof(SpecialContainer));
  fil.close();
}

SpecialContainer::~SpecialContainer(){

}
