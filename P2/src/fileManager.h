#ifndef FILEMANAGER_2121
#define FILEMANAGER_2121

#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;
 

ifstream openReadFile(char* filename);

void closeFile(ifstream &words);

int countFileLines(ifstream &words);

ofstream opneWriteFile(char* filename);

void writeToFile(char* filename, char* temp, int line, char* buffer, int score);


#endif
