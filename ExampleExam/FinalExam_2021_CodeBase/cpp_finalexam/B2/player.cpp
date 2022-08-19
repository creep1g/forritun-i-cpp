#include "player.h"

Player::Player(){
  this->name = "";
  this->result = 0;
  this->number = 0;
}

Player::Player(string name, int number, double result){
  this->name = name;
  this->number = number; 
  this->result = result;
}

Player::Player(Player &p1){
  this->name = p1.get_name();
  this->number = p1.get_number();
  this->result = p1.get_result();
}

string Player::get_name(){
  return this->name;
}

void Player::set_name(string name){
  this->name = name;
}

int Player::get_number(){
  return this->number;
}

void Player::set_number(int number){
  this->number = number;
}

double Player::get_result(){
  return this->result;
}

void Player::set_result(double result){
  this->result = result;
}

ostream &operator<<(ostream &out, Player &p1){
  out << "Name: " << p1.get_name() << endl << "Number: " << p1.get_number() << endl << "Result: " << p1.get_result();
  return out;
}

