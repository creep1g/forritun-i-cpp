#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <sstream>
#include <map>

using namespace std;

const int sampleRate = 44100;
const int bitDepth = 16;
const int noChannels = 2;


float generateWave(float &angle, float &offset){

  float sample = 0.5 * sin(angle);
  angle += offset;
  return sample;
};


void writeBinToFile(ofstream &file, int value, int size){
  // Use byte packing to convert integer to little endian char array
  char buffer[4];
  buffer[0] = value & 0xff;
  buffer[1] = (value & 0x0000ff00) >> 8;
  buffer[2] = (value & 0x00ff0000) >> 16;
  buffer[3] = (value & 0xff00000000) >> 24;
  file.write(buffer, size);
}


void generateWavChunks(ofstream &wavFile){
  // Header chunk
  wavFile << "RIFF" << "----" << "WAVE"; // This is size, will be set with seekp later 
  // Format Chunk
  wavFile << "fmt ";
  writeBinToFile(wavFile, 16, 4); // Size
  writeBinToFile(wavFile, 1, 2); // Compression code
  writeBinToFile(wavFile, noChannels, 2); // Number of channels
  writeBinToFile(wavFile, sampleRate, 4); // Sample rate
  writeBinToFile(wavFile, (sampleRate*bitDepth)/8, 4); // Byterate
  writeBinToFile(wavFile, bitDepth/8, 2); // Blackalign
  writeBinToFile(wavFile, bitDepth, 2); // Betdepth
  // Data chunk
  wavFile << "data" << "----"; // This is size and will be set with seekp later

}
float calculateNoteLength(float length, float bpm){
  float base = 240.0f; // Length of a whole note is 240/bpm
  float divident = base * length;
  return divident/bpm;
}

void handleNotes(string &note, int tone, float &offset, float &angle, int &maxLoudness, ofstream &wavFile, float bpm, float &duration) {
  float length;
  int iterator;
  float denominator;
  float numerator;
  if (tone == 0){
    numerator = (char)note[1]-'0';
    iterator = 2; // This is where note length starts for S (silence)
  }
  else{
    numerator = (char)note[2]-'0';
    iterator = 3; // This in where note length starts for notes
  }
  // Generate note length as an integer
  for(int i = iterator; i <= note.length() - 1; i++){
    if (i == iterator){
      denominator = (char)note[i]-'0';
    }
    else {
      denominator = (denominator*10)+(char)note[i]-'0';
    }
  }
  length = numerator/denominator;
  if (tone != 0){
    int octave = (char)note[1] - '0';
    for(int i = 0; i < octave ; i++){
      tone = tone * 2;
    }
  }

  duration = calculateNoteLength(length, bpm);

  maxLoudness = pow(2, bitDepth - 1) - 1;
  offset = 2 * M_PI * tone / sampleRate;

  for(int i = 0; i < sampleRate * duration; i++){
    float sample = generateWave(angle, offset);
    int intSample = static_cast<int> (sample * maxLoudness);
    writeBinToFile(wavFile, intSample, 2);
  }
}

int main (int argc, char* argv[]){
  // Initialize some variables.
  float angle = 0.0f;
  float offset = 0.0f;
  float tone;
  float duration;
  int beforeAudio;
  int maxLoudness;
  float bpm;

  // Initialize a map of note frequencies starting at NOTE0
  // Notes are floats to better represent the real musical frequencies 
  map<char, float> notes;
  notes['a'] = 55.00;
  notes['A'] = 58.27;
  notes['b'] = 61.74;
  notes['B'] = 32.70;
  notes['c'] = 32.70;
  notes['C'] = 34.65;
  notes['d'] = 36.71;
  notes['D'] = 38.89;
  notes['e'] = 41.20;
  notes['E'] = 43.65;
  notes['f'] = 43.65;
  notes['F'] = 46.25;
  notes['g'] = 49.00;
  notes['G'] = 51.91;
  notes['s'] = 0;

  // initialize out file
  ofstream wavFile;
  
  // Open in file.
  ifstream textFile;
  textFile.open(argv[1]);

  // Initialize string variables
  string fileName;
  string token;
  string line;
  string note;

  int counter = 0;
  int data; 

  while(getline(textFile, token, '\n')){
    line = token;

    stringstream ss(line);

    if (counter == 0){
      ss >> fileName;
      // Open out file.
      wavFile.open(fileName + ".wav", ios::binary);
      generateWavChunks(wavFile);
      // We use tellp and seekp to get the size of the file.
      beforeAudio = wavFile.tellp(); 
    }  

    else if (counter == 1){
      ss >> bpm;  
    }
      else {
        // Handle unexpected whitespace and bad format
        if(line.length() > 1){
        
        note = ss.str();
        // For some reason files downloaded from had weird extra whitespaces
        // making the lines too long. this is to remove those whitespaces.
        for(int i = 0; i < note.length() +1 ; i++){
            if(isspace((int) note[i])){
            note.erase(i, 1); 
          }
        }
          tone = notes[(char)note[0]];
          handleNotes(note, tone, offset, angle, maxLoudness, wavFile, bpm, duration);
        }
    }
    counter++;
    ss.clear();

  }

  cout << "Writing audio to " << fileName << ".wav" <<  endl;

    
  int afterAudio = wavFile.tellp();

  wavFile.seekp(beforeAudio - 4);
  writeBinToFile(wavFile, beforeAudio-afterAudio, 4);

  wavFile.seekp(4, ios::beg);
  writeBinToFile(wavFile, beforeAudio, 4);

  wavFile.close();
  return 0;

}