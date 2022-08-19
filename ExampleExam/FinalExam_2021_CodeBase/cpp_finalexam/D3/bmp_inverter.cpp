//This is an empty file where you can make your program
//You can also delete or rename this file and make your program in other files
//Just make sure to update the Makefile

#include <iostream>
#include <fstream>

using namespace std;

struct BMPFile{
  uint16_t file_type{0x4d42};
  uint32_t file_size{0};
  uint16_t reserved1{0};
  uint16_t reserved2{0};
  uint32_t offset_data{0};
};

struct BMPInfo{
  uint32_t size{ 0 };
  int32_t width{0};
  int32_t height{0};

  uint16_t planes{1};
  uint16_t bit_count{0};
  uint32_t compression{0};
  uint32_t size_image{0};
  int32_t x_pixels_per_meter{0};
  int32_t y_pixels_per_meter{0};
  uint32_t colors_used{0};
  uint32_t colors_important{0};
};

struct BMPColor{
  uint32_t red_mask{0x00ff0000};
  uint32_t green_mask{0x0000ff00};
  uint32_t blue_mask{0x000000ff};
  uint32_t alpha_mask{0xff000000};
  uint32_t color_space_type{0x7354742};
  uint32_t unused[16]{0};
};

struct BMP{
  BMPFile file_header;
  BMPInfo info_header;
  BMPColor color_header;

  BMP (const string fname){
    read(fname);
  }

  void read(const string fname){
    ifstream inFile;
    inFile.open(fname, ios::binary);
  }
};


int main(int argc, char *argv[]){
  // Arg check!

  if (argc > 3 || argc < 3){
    cout << "Usage: ./d3 <in_filename.bmp> <out_filename.bmp>" << endl;
    return 0;
  } 
  for(int i = 1; i < argc; i++){
    string arg = argv[i];
    if(arg.substr(arg.length() - 4) != ".bmp"){
      cout << "Files must end with .bmp" << endl;
      return 0;
    }
    cout << arg << endl;
  }
  BMP bmp(argv[1]);
  

  ofstream outFile;
  outFile.open(argv[2], ios::binary);
  
}
