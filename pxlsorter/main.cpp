#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sstream>
#include <string.h>
#include <strings.h>
#include "src/sorter/sorter.h"
#include "src/BMP/bmp.h"
#include <fstream>
#include <vector>

using namespace std;

#define MAX_HORIZONTAL 100
#define MAX_VERTICAL 100

enum ftype{
  BMP = 1,
  JPG,
  PNG,
};

vector<char> buffer;
PBMPInfoHeader infoHeader;
PBMPFileHeader fileHeader;

int main(int argc, char *argv[]){
  /* ifstream file ("sampl.bmp", ios::binary); */
  /* if (file){ */
    /* file.seekg(0, ios::end); */
    /* streampos length = file.tellg(); */
    /* file.seekg(0, ios::beg); */

    /* cout << length << endl;; */

    /* buffer.resize(length); */
    /* file.read(&buffer[0], length); */
    /* fileHeader = (PBMPFileHeader)(&buffer[0]); */
    /* infoHeader = (PBMPInfoHeader)(&buffer[0] + sizeof(BMPFileHeader)); */
    
    /* PBMPImage im[infoHeader->biHeight][infoHeader->biWidth]; */
    /* file.seekg(fileHeader->bfOffBits); */

    /* int pxls = (int)length-(sizeof(BMPFileHeader) + sizeof(BMPInfoHeader)); */

    /* for(int i = infoHeader->biWidth-1; i >= 0; i--){ */
      /* for(int j = 0; j < infoHeader->biHeight; j++){ */
        /* file.read(&buffer[sizeof(BMPFileHeader)], pxls); */
        /* cout << im[i][j]->r << im[i][j]->g << im[i][j]->b << endl; */
        /* cout << buffer[fileHeader->bfOffBits]; */
      /* } */
    /* } */ 
  }

  /* cout << buffer[0] << buffer[1] << endl; */
  /* cout << fileHeader->bfSize << endl; */
  /* cout << infoHeader->biWidth << " " << infoHeader->biHeight << endl; */
  /* cout << "OffBits" << fileHeader->bfOffBits << endl; */
  /* cout << infoHeader->biCompression << endl; */

  /* int ch; */
  /* Sorter* sorter = new Sorter(); */
  /* string temp; */
  /* string fileName; */
  /* int vertical = 0; */
  /* int horizontal = 0; */
  /* int type; */

  /* while ((ch = getopt(argc, argv, "f:v:h:")) != -1){ */
  /*   switch (ch){ */
  /*     case 'f': */
  /*       fileName = optarg; */
  /*       break; */
  /*     case 'v': */
  /*       vertical = stoi(optarg); */
  /*       break; */
  /*     case 'h': */
  /*       horizontal = stoi(optarg); */
  /*       break; */
  /*       cout << endl << endl << "Usage: ./pxlsorter [-f] filename.bmp [-v] integer value vertical sort [-h] integer value horizontal sort" << endl; */ 
  /*   } */
  /*   if (vertical > MAX_VERTICAL || horizontal > MAX_HORIZONTAL){ */
  /*     cout << "Max vertical/horizontal value is 100" << endl; */
  /*     break; */
  /*   } */
  /*   string fEnd = fileName.substr(fileName.length() -4); */

  /*   if(fileName != "" && (fEnd != ".bmp") && (fEnd != ".jpg") && fEnd != ".png"){ */
  /*     cout << "Only BMP files are accepted." << endl; */
  /*     break; */
  /*   } */
  /*   else{ */
  /*     if (fEnd == ".bmp"){ */
  /*       type = ftype::BMP; */
  /*     } */
  /*     if (fEnd == ".jpg"){ */
  /*       type = ftype::BMP; */
  /*     } */
  /*     if (fEnd == ".png"){ */
  /*       type = ftype::BMP; */
  /*     } */

  /*   } */
  /* } */

  /* char* fileCharArr = new char[fileName.length()+1]; */

  /* strcpy(fileCharArr, fileName.c_str()); */

  /* sorter->Sort(fileCharArr, vertical, horizontal, type, 12); */

  return 0;
}
