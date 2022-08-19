#include <iostream>
#include "player.h"
#include <string>
#include <fstream>
#include <iostream>
#include <string.h>
#include <vector>
using namespace std;


vector<Player> read_players_from_file(string filename){

  vector<Player> playerlist;
  ifstream plyrfile;
  plyrfile.open(filename, ios::in);

  string name;
  string number;
  string result;
  string line;
  string::size_type sz; 
  while(getline(plyrfile, line, '\n')){
    
    name = line.substr(0, line.find(" "));
    line.erase(0, name.length() + 1);
    number = line.substr(0, line.find(" "));
    line.erase(0, number.length() + 1 );
    result = line.substr(0, line.find(" "));

    playerlist.push_back(Player(name, stoi(number.c_str()), stod(result.c_str(), &sz)));
  }
  return playerlist;  
}


int main(){
    auto players = read_players_from_file("player_test_file.txt");
    for(auto player : players){
        cout << player << endl;
    }
    return 0;
}
