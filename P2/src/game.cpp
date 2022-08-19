#include "game.h"
#include "wordHolder.h"
#include "fileManager.h"
#include <chrono>
#include <unistd.h>

using namespace std;
char filename[32] = "data/top10.txt";
char temp[32] = "data/temptop10.txt";

Game::Game(){
  this->_wh = {0};
  this->currentHint = 0;
  this->userName;
  this->score = 0;
  this->hintCount = 0;
  this->guesses = 0;
  this->totalLength =0;
}



Game::Game(WordHolder *words, int lineCount){ 
  this->_wh = words;
  this->lineCount = lineCount; // Used for random
  this->userName;
  this->currentHint = 0;
  this->score = 10;
  this->hintCount = 0;
  this->totalLength = 0;
  this->roundTime = 0;
  this->guesses = 0;
}

Game::~Game(){
  delete[] currentWord;
  delete[] currentScrambled;
  delete[] display;
  delete[] _wh;
}

void Game::_getWord(){
  srand(time(NULL));
  int randInt = rand() % this->lineCount - 1;
  // Make sure users get non played words.
  if (this->_wh[randInt].isPlayed()){
    for(int i = 0; i < this->lineCount; i++){
      randInt = rand() % this->lineCount;
      if(!this->_wh[randInt].isPlayed()){
        i = this->lineCount;
      }
    }
  }

  this->currentWord = this->_wh[randInt].getWord();
  this->currentScrambled = this->_wh[randInt].getScrambled();
  this->currentLength = this->_wh[randInt].length;
  this->display = new char[this->currentLength+1];
  this->_wh[randInt].playWord();
  
  
  char temp[this->currentLength];
  memset(this->display, '_', this->currentLength);
  this->display[this->currentLength] = '\0';

  int randint = rand() % this->currentLength-1;
  this->display[randint] = this->currentWord[randint];
}

void Game::displayArray(){
  cout << this->display << endl;
  cout << endl;
}

void Game::displayScrambled(){
  cout << "The word jumble is: ";
  cout << this->currentScrambled << endl;
}

bool Game::checkGuess(char* input){

  if(strcmp(input, this->currentWord) == 0){
    return true;
  }
  else{
    return false;
  }
}

void Game::printHeader(){
  cout << "\x1B[2J\x1B[H";
  cout << "" << endl;
  cout << "" << endl;
  cout << "__________________________________________________________________" << endl;
  cout << "| _______ _______  ______ _______ _______ ______         _______ |" << endl;
  cout << "| |______ |       |_____/ |_____| |  |  | |_____] |      |______ |" << endl; 
  cout << "| ______| |_____  |    \\_ |     | |  |  | |_____] |_____ |______ |" << endl;
  cout << "------------------------------------------------------------------" << endl;
  cout << "" << endl;
  cout << "                     Guess the correct word" << endl;
  cout << "" << endl;
}

void Game::restart(){
  this->score = 0;
  this->hintCount = 0;
  this->totalLength = 0;
  this->roundTime = 0;
  this->currentHint = 0;
  this->guesses = 0;
}

int Game::calculateScore(){
  
  this->score = (((200+this->totalLength - this->roundTime) - this->guesses) - this->hintCount);
  if(this->score < 1){
    this->score = 0;
  }
  return this->score;
}

void Game::addToTime(int roundTime){
  this->roundTime = roundTime;
}

void Game::updateScoreBoard(int place){
  writeToFile(filename, temp, place, this->userName, this->score);

}

void Game::saveScore(int place){
  if(place == 0){
    cout << "NEW HIGH SCORE!" << endl;
    cout << "    " << this->score << endl;
  }
  else if(place == -1){
    cout << endl;
    cout << "Well Done!" << endl;
    cout << "Your score is: " << this->score << endl;
    cout << endl;
    cout << "Unfortunately you did note make it to our Top 10" << endl;
    cout << "Please try again." << endl;
    return;
  }
  else{
    char ending[2];
    cout << "Well Done!" << endl;
    cout << "Your score is: " << this->score << endl;
    cout << "You got " << place+1 << " place!" << endl;
  }

  char check;
  while(check != 'n' && check != 'y'){
    cout << "Would you like to save your score? [y/n]: ";
    cin >> check;
  }
  this->printHeader();
  if (check == 'y'){
    cout << "Enter your initials[max 3 letters]: ";
    cin >> this->userName;
    this->updateScoreBoard(place);
  }
}

void Game::getHint(){
  this->hintCount++;
  srand(time(NULL));
  int randint;
  for(int i = 0; i < this->currentLength*2; i++){
    randint = rand() % this->currentLength;
    if(this->display[randint] == '_'){
      this->display[randint] = this->currentWord[randint];
      break;
    }
  }
}

void Game::printScoreBoard(){
  ifstream scoreBoard;
  scoreBoard = openReadFile(filename);
  char* line;
  line = new char[12];
  char* score;
  score = new char[3];
  char* name;
  name = new char[3];
  cout << "***********************************" << endl;
  cout << "**************TOP 10***************" << endl;
  cout << "***********************************" << endl;

  if(scoreBoard.peek() == EOF){
    cout << "*******Score Board is empty********" << endl;
  }

  while(scoreBoard.peek() != EOF){
    scoreBoard.getline(line, 120);
    memcpy(score, line + 4, 4);
    memcpy(name, line + 0, 3);
    name[3] = '\0'; // adding null terminator to the end of our name.

    cout << "***         " << name << "   " << score << "           ***" << endl; 
  }
  cout << "***********************************" << endl;
  cout << "***********************************" << endl;
  cout << "***********************************" << endl;
  delete[] score;
  delete[] name;
  delete[] line;


}

int Game::checkIfHighScore(){
  /* char file[10] = "top10.txt"; */
  ifstream reader = openReadFile(temp);

  char* line;
  char* scoreString;

  if (reader.is_open()){
    int count = 0;
    while(reader.peek() != EOF){
      int scoreInt;
      line = new char[32];
      scoreString = new char[4];
      reader.getline(line, ' ');

      // Get score out of score board
      // Convert it to an integer
    
      memcpy(scoreString, line + 4, 4);
      sscanf(scoreString, "%d", &scoreInt);
      if (this->score > scoreInt){
        return count;
      }

      delete[] scoreString;
      delete[] line;
      count++;
    }
    // IF FILE IS EMPTY THEN RETURN HIGHEST PLACE.
    if(count == 0){
      return count;
    }
    reader.close();
  }
  return -1;
}

char Game::round(){
  bool correct = 0;
  char* guess;
  int cont = 1;
  this->currentHint = 0;
  this->_getWord();
  guess = new char[this->currentLength];
  // For testing
  cout << this->currentWord << endl;

  
  this->totalLength = this->totalLength + this->currentLength;
    while (!correct && cont != 0 ){
      this->displayScrambled();
      this->displayArray();
      cout << "Guess: ";
      cin >> guess;
      // User input other than a full guess goes here
      this->printHeader();
      if((strcmp(guess, "h") == 0) && this->currentHint < this->currentLength-2){
        this->currentHint++;
        this->getHint();
      }

      else if((strcmp(guess, "h") == 0) && this->currentHint >= this->currentLength-2){
        cout << "No more hints for you my friend!" << endl;
        cout << endl;
      }

      else{
        correct = this->checkGuess(guess);
        this->guesses++; 
        if(cont == 0){
          return 'q';
        }
        if(!correct){
          cout << "That was not correct try again!" << endl;
        }
        else{
          cout << this->currentWord << " Is correct!" << endl;
        }
        cont = strcmp(guess, "q");

      }
    }
  delete[] currentWord;
  delete[] currentScrambled;
  delete[] display;
  delete[] guess;


  if(cont == 0){
    return 'q';
  }
  else{
    return 'p';
  }
}

