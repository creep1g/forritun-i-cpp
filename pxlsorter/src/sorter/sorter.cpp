#include "sorter.h"
#include <png.h>

using namespace std;


void Sorter::Sort(char* file, int vert, int hori, int ftype, int thresh){
  /* cout << "IN SORT"; */
  /* cout << file; */
  switch (ftype){
    case 1:
      this->ReadBMP(file);
      break;
    case 2:
      //read jpg
      break;
    default:
      this->ReadPNG(file);
      this->processPNG(thresh);
      break;
  }
}

unsigned char* Sorter::ReadBMP(char* file){
  FILE* buffer = fopen(file, "rb");
  unsigned char info[54];
  fread(info, sizeof(unsigned char), 54, buffer);

  this->width = *(int*)&info[18];
  this->height = *(int*)&info[22];

  int heightSign = height < 0 ? -1 : 1;
  unsigned char* u = new unsigned char[28];
  return u;
}

