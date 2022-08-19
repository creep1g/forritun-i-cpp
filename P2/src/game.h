#ifndef GAME_1
#define GAME_1
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string.h>
#include <time.h>
#include "fileManager.h"
/* #include "wordHolder.h" */
class WordHolder;
class Game{
  public:
    // Functions
    Game();
    Game(WordHolder *words, int lineCount);
    virtual ~Game();
    void restart();
    char round();
    void printHeader();
    void addToTime(int roundTime);
    int calculateScore();
    int checkIfHighScore();
    void saveScore(int place);
    void printScoreBoard();
  private:
    // Functions
    void getHint();
    void _getWord();
    void updateScoreBoard(int place);
    void displayScrambled();
    void displayArray();
    bool checkGuess(char* guess);
  private:
    // Variables
    WordHolder *_wh;
    int hintCount;
    int currentHint;
    int lineCount;
    char* currentWord;
    char* currentScrambled;
    int currentLength;
    char* display;
    char userName[3];
    int score;
    int guesses;
    int totalLength;
    int roundTime;
};


#endif
