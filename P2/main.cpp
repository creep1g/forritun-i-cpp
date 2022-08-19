#include <sstream>
#include <string.h>
#include <chrono>
#include <time.h>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include "src/fileManager.h"
#include "src/wordHolder.h"
#include "src/game.h"

using namespace std;

ifstream wordFile;
// Initialize a global variable for our wordFile


int main(){
  // Initialize game
  WordHolder *wordList;
  // Initialise variables for file reading
  int lineCount;
  char temp;
  char* line;
  int score;
  line = new char[128];

  // Get file stream
  char* filename;
  filename = new char[32];
  strcpy(filename, "data/words.txt");  

  wordFile = openReadFile(filename);
  delete[] filename;
  
  // Get number of lines in the file
  if (wordFile.is_open()){
    lineCount = countFileLines(wordFile);
    wordList = new WordHolder[lineCount];

    // Add all lines into an array of char arrays.
    for(int i = 0; i < lineCount-1; i++){
      char word[128];
      wordFile.getline(word, 120);
      wordList[i].build(word);
    }
    closeFile(wordFile);

    // Start Game
    Game game = Game(wordList, lineCount);  
    game.printHeader();

    game.checkIfHighScore();
    char option;
    // Main game loop starts here.
    cout << "Welcome to Word Scramble" << endl;
    cout << "You will be shown a scrambled word" << endl;
    cout << "Try to guess 10 words in the shortest amount of time possible" << endl;
    cout << "If you ever want to quit type 'q'." << endl;
    cout << "If you want to get a hint type 'h'." << endl;
    cout << "To see the Top10 guessers type 's'." << endl;

    while(option != 'p' && option != 'q'){
      cout << endl << "Type 'p' to start playng: ";
      cin >> option;
      if(option == 's'){
        game.printScoreBoard();
      }
    }
    int elapsed;
    while (option != 'q' && option != 'n'){

      for(int i = 3; i > 0; i--){
        game.printHeader();
        cout << "                          Starting in: " << i << endl;
        sleep(1);
      }

      cout << "Go!" << endl;

      auto start = chrono::steady_clock::now();
      for(int i = 0; i < 10; i++){
        cout << "Word: " << i+1 << endl;
        option = game.round();
        if(option == 'q'){
          break;
        }
      }
      auto end = chrono::steady_clock::now();
      elapsed = chrono::duration_cast<chrono::seconds>(end - start).count();

    if(option == 's'){
        game.printScoreBoard();
        cout << "Press any key to continue";
        cin.get();
      }

    if(option != 'q'){
          cout << "You guessed 10 words in: " << elapsed << " seconds. Good Job!" << endl;
        cout << endl;

          /// Add time to game, calculate score, display score
          //
          game.addToTime(elapsed);
          score = game.calculateScore();
          int top = game.checkIfHighScore();
        //  If score fits in top 10, allow user to save score
          game.saveScore(top);

        //  ask player if he wants to play again.
        cout << "If you want to view the top 10 score board type 's'" << endl;
        while(option != 'y' && option != 'n' && option != 's'){
          cout << "Do you want to play again? [y/n]: ";
          cin >> option;
          if (option == 's'){
            game.printScoreBoard();
          }

        }
      }
      else{
        cout << "Thank you for playing! " << endl;
      }
    }
  } 

  else{
    cout << "Something went wrong with our files. Please try again later. " << endl;
  }

}
