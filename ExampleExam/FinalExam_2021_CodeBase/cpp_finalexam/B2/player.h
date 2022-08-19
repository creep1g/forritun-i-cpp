#ifndef PLAYER_H_987234
#define PLAYER_H_987234
#include <string>
#include <ostream>

using namespace std;
class Player{
  private:
    //Data
    string name;
    int number;
    double result;
  public:
    Player();
    Player(string name, int, double);
    Player(Player &p1);
    string get_name();
    void set_name(string);
    int get_number();
    void set_number(int);
    double get_result();
    void set_result(double);

    friend ostream &operator<<(ostream &out, Player &p1);

};
#endif //PLAYER_H_987234
