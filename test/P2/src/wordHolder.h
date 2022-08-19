#ifndef WORDHOLDER_22
#define WORDHALDER_22

#include <stdlib.h>
#include <iostream>
#include <string.h>

using namespace std;

class WordHolder {
  public:

    WordHolder();

    WordHolder(char* string);

    void build(char* string);

    void scramble();

    char* getWord();
    
    char* getScrambled();

    /* int getLength(); */

    virtual ~WordHolder();

    bool isPlayed();

    void playWord();

    int length;

  private:
    char* scrambled;
    bool played;
    char* word;
};


#endif
