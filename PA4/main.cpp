#include <iostream>
#include <stdexcept>
#include <string>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <utility>
#include <bits/stdc++.h>
#include <chrono>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
// H files 
#include "data/dataHandler/dataHandler.h"
#include "charachter/athlete/athlete.h"
#include "charachter/coach/coach.h"
#include "charachter/team/team.h"

using namespace std;

DataHandler dataHandler = DataHandler();
// Maps
map<int, Person*> athletes;
map<int, pair<string, string>> sports;
map<int, Person*> coaches;
map<int, Team*> teams;

void clearScreen(){
    cout << "\033[2J\033[1;1H";
}

void printSportMap(){
  for (auto iter = sports.begin(); iter != sports.end(); ++iter){
      cout << iter->first << ":    " << iter->second.first << endl;
  }
}

void printPersonMap(map<int, Person*> ppl){
  for (auto iter = ppl.begin(); iter != ppl.end(); ++iter){
    cout << iter->first << ":    " << iter->second->getName() << endl;
  }
}

void printTeamMap(){
  for (auto iter = teams.begin(); iter != teams.end(); ++iter){
    cout << iter->first << ":   " << iter->second->getName() << "  " << iter->second->getSport() << endl;
  }
}

void createTeam(){

  string name;
  string location;
  string statistic;
  string sport;
  string stat;
  string competitionName;
  char in; 
  cout << "Team creator" << endl;
  cout << "Type C to create a team or R to create a default: ";
  cin >> in;

  if(tolower(in) == 'r'){
    Team* team = new Team();
    teams.insert(make_pair(teams.end()->first, team));
    dataHandler.writeTeamToFile(team);
    team->printInfo();
    return;
  }

  clearScreen();
  cout << "Enter team name: ";
  cin.ignore();
  getline(cin, name);
  cin.clear();

  cout << "Enter team location: ";
  getline(cin, location);
  cin.clear();

  cout << "Enter sport type: ";
  getline(cin, sport);
  cin.clear();
  
  cout << "Enter statistic to keep: ";
  getline(cin, statistic);
  cin.clear();

  cout << "Enter a value in statistic: ";
  getline(cin, stat);
  cin.clear();

  cout << "What competition are they in: ";
  getline(cin, competitionName);
  cin.clear();
  
  Team* team = new Team(name, location, statistic, sport, stat, competitionName);
  teams.insert(make_pair(teams.end()->first +1, team));
  team->printInfo();
  dataHandler.writeTeamToFile(team);
  cout << "Press enter to continue....";
  cin.ignore();
  cin.get();

}

void createCoach(){
  int id = coaches.end()->first; 
  int age;
  string name;
  Role role = Role::Coach;
  string team;
  string sport;
  string startDate;
  char in;
  
  bool flag;
  int teamid;
  cout << "If you want to randomize an coach type R else type C: ";
  cin >> in;
  if (tolower(in) == 'r'){
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    srand(seed);
    name = dataHandler.getRandomName();
    age = rand() % ((90-20) + 1) + 20;
    Team* tempTeam = teams.at(rand()%teams.end()->first);
    team = tempTeam->getName();
    sport = tempTeam->getSport();
    startDate = "10.10.2010";
  }
  else{
    cout << "Enter coach name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter coach age:  ";
    cin >> age;
    cin.ignore();

    // Get teams
      printTeamMap();
      cout << "Enter id of team or C to create a new team:  ";
      cin >> teamid;
      /* try{ */
        if(tolower(teamid) == 'c'){
          createTeam();
          flag = false;
        }
      /* } */
      /* catch(invalid_argument){ */
        else{
        flag = true;
        cout << teamid << endl; 
        team = teams.at(teamid)->getName();
      }
    cout << "Enter start date (dd.mm.yyyy): ";
    cin >> startDate;

    printSportMap(); // Print all available sports with ID number

    cout << "Choose a sport or type C to create a custom sport:  ";
    string check;
    cin >> check;
    
    /* try{} */
    //TODO: Do same as with Athlete.
    if (check.compare("c") == 0|| check.compare("C") == 0){
      cout << "Enter sport name: " << endl;
      cin.ignore();
      getline(cin, sport);

      dataHandler.writeSportsToFile(sport, "none");
      sports.insert(make_pair(sports.end()->first+1, make_pair(sport, "none"))); // Insert new sport to map.
    }
    else{

      /* try{ */
        sport = sports.at(stoi(check)).first;
      /* } */
        
    }

  }
 
  Person *p = new Coach(id, age, name, role, team, startDate, sport);
  p->printInfo();
  if(flag){
    teams.at(teamid)->addPerson(p);
  }
  else{
    teams.end()->second->addPerson(p);
  }
  coaches.insert(make_pair(coaches.end()->first+1, p));
  dataHandler.writeCoachToFile(p);
  cout << "Press anykey to continue....";
  cin.ignore();
  cin.get();
}

void createAthlete(){
  int id = 123; // Get id from athlete file;
  int age;
  string name;
  Role role = Role::Athlete;
  int height;
  int weight;
  string sport; // Get list of sports with default stat from file
                // else create a new one.
  string team;
  string statName;
  string stat;
  char in;
  int teamid;
  bool flag;
  cout << "If you want to randomize an athlete type R else type C: ";
  cin >> in;
  if (tolower(in) == 'r'){
    //TODO: randomize.
  }
  else{
    cout << "Enter athletes name: ";

    cin.ignore();
    getline(cin, name);

    cout << "Enter athletes age:  ";
    cin >> age;
    cout << "Enter athletes height:  ";
    cin >> height;
    cout << "Enter athletes weight:  ";
    cin >> weight;
    
    while(true){
      printSportMap(); //Print Available sports with id. 
      cout << "Choose a sport or type C to create a custom sport:  ";
      string check;
      cin >> check;
      try{
        // Check if chosen sport is actially in map
        if(stoi(check) <= sports.end()->first){
          sport = sports.at(stoi(check)).first;
          statName = sports.at(stoi(check)).second;
          cout << "Statistic:  " << statName << endl;
          break;
        }
      }
      catch (invalid_argument) {

        if (check.compare("c") == 0 || check.compare("C") == 0){
          cout << "Enter sport name: " << endl;
          cin.ignore();
          getline(cin, sport);
          cin.clear();
          cout << "Enter a custom stat for this athlete: ";
          getline(cin, statName);
          cin.clear();
          dataHandler.writeSportsToFile(sport, statName);
          sports.insert(make_pair(sports.end()->first+1, make_pair(sport, statName))); // Insert new sport to map.
          break;
        }
        else{
          cout << "Something went wrong try again...." << endl;
          cout << "Press enter to continue...";
          cin.ignore();
          cin.get();
        }
      }
    }
    cout << "Enter stat value:  ";
    cin.ignore();
    getline(cin, stat);
    cin.clear();

    // Get teams
      printTeamMap();
      cout << "Enter id of team or C to create a new team:  ";
      cin >> teamid;
      try{
        if(tolower(teamid) == 'c'){
          createTeam();
          flag = false;
        }
      }
      catch(invalid_argument){
        flag = true;
        team = teams.at(teamid)->getName();
      }
  }

  Person *p = new Athlete(id, age, name, role, height, weight, sport, statName, stat);
  dataHandler.writeAthleteToFile(p);
  athletes.insert(make_pair(athletes.end()->first+1, p));
  p->printInfo();

  if(flag){
    teams.at(teamid)->addPerson(p);
  }
  else{
    teams.end()->second->addPerson(p);
  }
  cout << "Press enter to continue...";
  cin.ignore();
  cin.get();
  
}


int main(){
  // Main loop
  
  dataHandler.getAllCoaches(coaches);
  dataHandler.getAllAthletes(athletes);
  dataHandler.getListOfSports(sports);
  dataHandler.getAllTeams(teams);

  char in;
  string strIn;
  while(1){
    clearScreen();
    cout << "Welcome to **enter program name**" << endl;
    cout << "Type A to look at all athletes" << endl;
    cout << "Type C to look at all coaches" << endl;
    cout << "Type T to look at all teams" << endl;
    cout << "Type S to search" << endl;
    cout << "Type Q to quit" << endl;
    cout << "Input: ";
    cin >> in;

    if(tolower(in) == 's'){
      cout << "Search: ";
    }
    else if (tolower(in) == 'q'){
      break;
    }
    else if (tolower(in) == 'a'){

      clearScreen();

      cout << "Athletes" << endl;
      printPersonMap(athletes);
      cout << "Enter athlete ID to view info or C to create a new athlete: ";
      cin >> strIn;
      if(strIn.compare("c") == 0 || strIn.compare("C") == 0){
        cout << "\033[2J\033[1;1H";
        createAthlete();
      }
      else if(stoi(strIn) > 0 && stoi(strIn) <= athletes.end()->first){
        clearScreen();
        athletes.at(stoi(strIn))->printInfo();
        cout << "Press enter to continue.";
        cin.ignore();
        cin.get();
      }
    }
    else if (tolower(in) == 't'){
      /* clearScreen(); */
      printTeamMap();
      char in;
      cout << "Enter team id to view team or C to create a new team: ";
      cin >> in;
      try {
        if(tolower(in) == 'c'){
          createTeam();
        }
      }
      catch(invalid_argument){
        teams.at(in-'0')->printInfo();  
        teams.at(in-'0')->printRoster();  
      }
      cout << "Press enter to continue...";
      cin.ignore();
      cin.get();
    }
    else if (tolower(in) == 'c'){

      clearScreen();
      cout << "Coaches" << endl;
      printPersonMap(coaches);

      cout << "Enter coach ID to view info or C to create a new coach: ";
      cin >> strIn;
      if(strIn.compare("c") == 0 || strIn.compare("C") == 0){
        createCoach();
      }

      else if(stoi(strIn) > 0 && stoi(strIn) <= coaches.end()->first){
        clearScreen();
        coaches.at(stoi(strIn))->printInfo();
        cout << "Press enter to continue.";
        cin.ignore();
        cin.get();
      }
    }
    else {
      cout << "Input does not match any of the options." << endl;
      cout << "Please try again." << endl;
      cout << "Press enter to continue.";
      cin.ignore();
      cin.get();
    }
  }
}
