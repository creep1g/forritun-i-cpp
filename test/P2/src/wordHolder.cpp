#include "wordHolder.h"
#include <time.h>
WordHolder::WordHolder(){
  this->length = 0;
  this->word = NULL;
  this->scrambled = NULL;
  this->played = false;
}

void WordHolder::playWord(){
  this->played = true;
}

bool WordHolder::isPlayed(){
  return this->played;
}

WordHolder::WordHolder(char* string){
  this->build(string);
}

void WordHolder::scramble(){
  this->scrambled = new char[this->length];
  
  srand(time(NULL));
  
  char temp_origin[this->length];
  strcpy(temp_origin, this->word);
  
  int randint;

  for(int i = 0; i < this->length; i++){
    randint = rand() % this->length;
    char hold = temp_origin[i];
    char hold2 = temp_origin[randint];
    temp_origin[i] = hold2;
    temp_origin[randint] = hold;
  }

  // Check if word is scrambled
  // Call this function recursively if not
  int sameCount = 0;
  for (int i = 0; i < this->length; i++){
    if (temp_origin[i] == this->word[i]){
      sameCount++;
    }
  }

  if (sameCount == this->length){
    // Just a simple fix to scramble a word that came out the same.
    char hold = temp_origin[0];
    char hold2 = temp_origin[this->length-1];
    temp_origin[0] = hold2;
    temp_origin[this->length-1] = hold;
  }
  temp_origin[this->length] = '\0';
    strcpy(this->scrambled, temp_origin);
}

void WordHolder::build(char* string){
  this->length = strlen(string);
  this->word = new char[this->length+1];
  strcpy(this->word, string);
  this->scramble();
}

/* int getLength(){ */
/*   return this->length; */
/* } */

char* WordHolder::getWord(){
  return this->word;
}

char* WordHolder::getScrambled(){
  return this->scrambled;
}

WordHolder::~WordHolder(){
  cout << "DESTRUCTION!" << endl;
  delete[] word;
  delete[] scrambled;
  this->word = NULL;
  this->scrambled = NULL;
} 
