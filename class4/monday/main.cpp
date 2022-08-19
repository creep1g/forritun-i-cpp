#include <iostream>

#include <string.h>
//strcmp
//strcpy
//strcat

using namespace std;

struct LinkedListNode{
  LinkedListNode(int data, LinkedListNode *next = NULL){
    
  }
  int data;
  LinkedListNode *next;
};

class WordHolder {
  public:

    WordHolder(){
      length = 0;
      word = NULL;
    }


    WordHolder(char* string){
      build(string);
    }

    void build(char* string){
      length = strlen(string);
      word = new char[length+1];
      strcpy(word, string);
    }

    void print_me(){
      cout << "length: " << length << endl;
      cout << word << endl;
    }

    virtual ~WordHolder(){
      cout << "Destructor"<< endl;
      delete[] word;
      word = NULL;
    }

    int length;
    char* word;
};

int main(int argc, char *argv[]){
  bool verbose = false;
  /* for(int i = 1; i < argc; i++){ */
  /*   if (strcmp(argv[i], "-v") == 0){ */
  /*     verbose = true; */
  /*   } */
  /* } */
  
  WordHolder *words;
  
  char strengur[128];

  int word_count;

  cout << "How many words? ";
  cin >> word_count;
  
  words = new WordHolder[word_count];

  for (int i = 0; i < word_count; i++){
    cin >> strengur;
    words[i].build(strengur); // = WordHolder(strengur);
  }

  for(int i = 0; i < word_count; i++){
    cout << "word #" << i+1 << ": ";
    words[i].print_me();
  }

  /* char strengur[128]; */
 
  /* do { */
  /*   cin.getline(strengur, 12, ' '); */
  /*   cout << strengur << endl; */
  /* } while(!cin.eof()); */


  /* if(verbose){ */
  /*   cout << "This is long text" << endl; */
  /* } */
  /* else { */
  /*   cout << "ok" << endl; */
  /* } */
}
/* int main(){ */



  /* char * char_p; */
  /* char_p = new char[128]; */

  /* char *strengur; */
  /* strengur = new char[128]; */

  /* strcpy(strengur, "strengurinn er svona"); */
  
  /* delete[] char_p; */
  /* strcpy(char_p, strengur); */

  /* cout << "Compare: " << strcmp(char_p, strengur) << endl; */
  
  /* strengur[4] = 'A'; */
  
  /* cout << "Compare: " << strcmp(strengur, char_p) << endl; */
  /* cout << "Compare: " << strcmp(char_p, strengur) << endl; */
  /* cout << char_p << endl; */
  /* delete[] strengur; */
/* } */
