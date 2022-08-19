#ifndef DATAHANDLER_222
#define DATAHANDLER_222
#include <vector>
#include <string>
#include <fstream>
#include <bits/stdc++.h>
#include <sstream>
#include "../../charachter/athlete/athlete.h"
#include "../../charachter/coach/coach.h"
#include "../../charachter/team/team.h"

using namespace std;


class DataHandler{
  
public:
  DataHandler();
  ofstream openOutFile(string fileName);
  ifstream openInFile(string fileName);

  void writeAthleteToFile(Person *athlete);
  void writeCoachToFile(Person *coach);
  void writeTeamToFile(Team *team);
  void writeSportsToFile(string sport, string defStat);
  void writePersonToTeam(string team, Person* p);

  string getRandomName();
  void getListOfSports(map<int, pair<string, string>> &sports);
  int getNextId(Role role);
  void getAllAthletes(map<int, Person*> &athletes);
  void getAllCoaches(map<int,Person*> &coaches);
  void getAllTeams(map<int, Team*> &teams);

  void loadToMap(string fileName, map <int, Person*> &roster);

private:
  string athletes = "data/athleteData/athletes.csv";
  string teams = "data/teamData/teams.csv";
  string coaches = "data/coachData/coaches.csv";
  string sports = "data/sportData/sports.csv";
};

#endif
