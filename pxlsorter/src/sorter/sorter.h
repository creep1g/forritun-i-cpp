#include <iostream>
#include <functional>
#include <fstream>
#include <png.h>

using namespace std;

class Sorter{
  public:
    void Sort(char* file, int vert, int hori, int ftype, int thresh);

  private:
    unsigned char* ReadBMP(char* file);
    void WriteBMP(char* file);

    void ReadPNG(char* file);
    void processPNG(int threshold);
    void WritePNG(char* file);

    void ReadJPG(char* file);
    void WriteJPG(char* file);
    
    int convertGS(const png_bytep px);
    int comparePNGpxl(const png_bytep *parent, const png_bytep *child);
  private:
    int width;
    int height;

    png_byte color_type;
    png_byte bit_depth;
    png_bytep *row_pointers;



};
