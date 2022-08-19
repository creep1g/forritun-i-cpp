#include "dataHandler.h"
#include <sstream>
#include <string>

DataHandler::DataHandler(){}

ofstream DataHandler::openOutFile(string fileName){
  ofstream outFile;
  outFile.open(fileName, ios::app);
  return outFile;
}


ifstream DataHandler::openInFile(string fileName){
  ifstream inFile;
  inFile.open(fileName);
  return inFile;
}


void DataHandler::writeAthleteToFile(Person *athlete){
  ofstream athleteFile;
  athleteFile = this->openOutFile(this->athletes);
  if(athleteFile.is_open()){
    athleteFile << athlete->getCsvString() + "\n";
    athleteFile.close();
  }
}


void DataHandler::writeCoachToFile(Person *coach){
  ofstream coachFile; 
  coachFile = this->openOutFile(this->coaches);
  if(coachFile.is_open()){
    coachFile << coach->getCsvString()+"\n";
    coachFile.close();
  }
} 


void DataHandler::writeSportsToFile(string sport, string defStat){
  ofstream sportFile;
  sportFile = this->openOutFile(this->sports);
  if(sportFile.is_open()){
    sportFile << sport+","+defStat;
    sportFile.close();
  }
}


void DataHandler::getListOfSports(map<int, pair<string, string>> &sports){
  ifstream sportFile;
  sportFile = this->openInFile(this->sports);
  string line;
  string sport;
  string defStat;
  if(sportFile.is_open()){
    int count = 0;
    /* while(sportFile.peek() != EOF){ */
    while(getline(sportFile, line)){
      /* sportFile >> line; */
      if(count > 0){
        sport = line.substr(0, line.find(','));
        defStat = line.substr(sport.length()+1, line.length()-1);
        sports.insert(make_pair(count, make_pair(sport, defStat))); 
      }
      count++;
    }
  }
  sportFile.close();
}

string DataHandler::getRandomName(){

    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    srand(seed);

    ifstream names;
    names.open("data/names.txt", ios::in);
    string name;
    int count = 0;
    vector<string> nameList;
    while(getline(names, name)){
      nameList.push_back(name); 
   }
  return nameList[rand()%nameList.size()];
}


void DataHandler::writeTeamToFile(Team *team){
  ofstream teamfile;
  teamfile = this->openOutFile(this->teams);
  string csv = team->getCsvString();
  if(teamfile.is_open()){
    teamfile << team->getCsvString()+"\n";
  }
}

void DataHandler::getAllTeams(map<int, Team*> &teams){
  ifstream teamFile;
  teamFile = this->openInFile(this->teams);

  string line;
  string name;
  string location;
  string statistic;
  string stat;
  string sport;
  string competitionName;

  int count = 0;

  while(getline(teamFile, line)){
    if(count > 0){
        istringstream s(line);
        string field;

        int inner = 0;

        while (getline(s, field, ',')){
          if(inner == 0){
            name = field;
          }
          else if(inner == 1){
            location = field;
          }
          else if(inner == 2){
            statistic = field;
          }
          else if(inner == 3){
            stat = field;
          }
          else if(inner == 4){
            sport = field;
          }
          else if(inner == 5){
            competitionName = field;
          }
          inner++;
        }
    Team* team = new Team(name, location, statistic, sport, stat, competitionName);
    teams.insert(make_pair(count, team));
    }
    count++;
  }
}

void DataHandler::getAllAthletes(map<int, Person*> &athletes){
  ifstream athleteFile;
  athleteFile = this->openInFile(this->athletes);

  string line;
  int id;
  int age;
  string name;
  Role role = Role::Athlete;
  int height;
  int weight;
  string type;
  string statName;
  string stat;
  string temp;

  if (athleteFile.is_open()){
    int count = 0;
    while(getline(athleteFile, line)){

      if (count > 0){
        istringstream s(line);
        string field;

        int inner = 0;

        while (getline(s, field, ',')){
          // There has to be a better way to do this....
          if(inner == 0){
            id = stoi(field);
          }
          else if(inner == 1){
            name = field;
          }
          else if(inner == 2){
            age = stoi(field);
          }
          else if(inner == 3){
            height = stoi(field);
          }
          else if(inner == 4){
            weight = stoi(field);
          }
          else if(inner == 5){
            type = field;
          }
          else if(inner == 6){
            statName = field;
          }
          else{
            stat = field;
          }
          inner++;
        }
        Person* p = new Athlete(id, age, name, role, height, weight, type, statName, stat);
        athletes.insert(make_pair(count, p));

      }
      count++;
    }
  }
  athleteFile.close();

}

void DataHandler::getAllCoaches(map<int, Person*> &coaches){
  ifstream coachFile;
  coachFile = this->openInFile(this->coaches);

  string line;
  int id;
  int age;
  string name;
  Role role = Role::Coach;
  int height;
  int weight;
  string team;
  string startDate;
  string sport;


  if (coachFile.is_open()){
    int count = 0;
    while(getline(coachFile, line)){

      if (count > 0){
        istringstream s(line);
        string field;

        int inner = 0;

        while (getline(s, field, ',')){
          if(inner == 0){
            id = stoi(field);
          }
          else if(inner == 1){
            name = field;
          }
          else if(inner == 2){
            age = stoi(field);
          }
          else if (inner == 3){
            team = field;
          }
          else if(inner == 4){
            startDate = field;
          }
          else if(inner == 5){
            sport = sport;
          }
          inner++;
        }
      Person* p = new Coach(id, age, name, role, team, startDate, sport);
      coaches.insert(make_pair(count, p));
      }
      count++;
    }
  }
  coachFile.close();
}

void DataHandler::loadToMap(string fileName, map <int, Person*> &roster){
  ifstream rosterFile;
  map <int, Person*> tempAthletes;
  map <int, Person*> tempCoaches;
  this->getAllAthletes(tempAthletes);
  this->getAllCoaches(tempCoaches);
  
  string line;
  int count = 0; 
  rosterFile.open("roster/"+fileName, ios::in);
  while(getline(rosterFile, line)){
      istringstream s(line);
      string field;

      map <int, Person*> search;
      string memberName;
    
      int inner = 0;

      while (getline(s, field, ',')){
        if(inner == 0){
          map <int, Person*> search;
          if (field.compare("Athlete") == 0){
            search = tempAthletes;
          } 
          else{
            search = tempCoaches;
          }
        }
        else if (inner == 1){
          memberName = field;
        }
       }

    for (auto iter = roster.begin(); iter != roster.end(); ++iter){
      if(memberName.compare(iter->second->getName())){
        roster.insert(make_pair(count, iter->second));
      }        
    }
  }

// Clean up
  for (int i = 0; i < tempAthletes.end()->first; i++){
    delete tempAthletes[i];
  }
  for (int i = 0; i < tempCoaches.end()->first; i++){
    delete tempCoaches[i];
  }
  rosterFile.close();
}

