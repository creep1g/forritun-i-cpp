#include "fileManager.h"

using namespace std;

ifstream openReadFile(char* filename){
  ifstream fileStream;
  fileStream.open(filename);
  return fileStream;
}

ofstream openWriteFile(char* filename){
  ofstream fileStream;
  fileStream.open(filename);
  return fileStream;
}

void writeToFile(char* filename,char* temp, int line, char* buffer, int score){
  ofstream writer = openWriteFile(temp);
  ifstream reader = openReadFile(filename);

  writer = openWriteFile(temp);
  reader = openReadFile(filename);
  
  int count = 0;
  char* readerLine;
  readerLine = new char[12];
  // Write everything into a temp file
  // replacing the line wich our user should be in 
  while(reader.peek() != EOF){
    reader.getline(readerLine, 120);
    if(count == line){
      writer << buffer << " " << score << '\n';
    }
    writer << readerLine << '\n';
    count++;
    if (count == 10){
      break;
    }
  }
  // If files are empty we need to be able to add the first line.
  if(count == 0){
    writer << buffer << " " << score << '\n';
  }
  
  reader.close();
  writer.close();
  // Moving information from temp file to main file.
  reader = openReadFile(temp);
  writer = openWriteFile(filename);
  while(reader.peek() != EOF){
    reader.getline(readerLine, 120);
    writer << readerLine << '\n';
  }
  reader.close();
  writer.close();
  delete[] readerLine;
}

void closeFile(ifstream &words){
  words.close();
}

int countFileLines(ifstream &words){
  // Use getline to count number of lines in the given in file.
  // Return an integer value.
  int count = 0;
  char* line;
  line = new char[128];
  if (words.is_open()){
    while(words.peek() != EOF){
      words.getline(line, 120);
      count++;
    }
    delete[] line;
    words.clear();
    words.seekg(0);
  }
  return count;
}
