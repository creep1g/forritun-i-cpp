#include "point3d.h"
#include <iostream>
 
using namespace std;

Point3D::Point3D(){
  cout << "Default Constructor" << endl;
  x = 0;
  y = 0;
  z = 0;
}


Point3D::Point3D(double xx, double yy, double zz){
  cout << "Parameter constructor" << endl;
  setValues(xx, yy, zz);

}
Point3D::Point3D(const Point3D& P){
  cout << "Copy Constructor" << endl;
  x = P.x;
  y = P.y;
  z = P.z;
} // Copy constructor

Point3D::~Point3D(){
  cout << "Destructor!!!!" << endl;
}

void Point3D::setValues(double xx, double yy, double zz){
  this->x = xx;
  this->y = yy;
  this->z = zz;
}

double Point3D::getX(){
  return this->x;
}

double Point3D::getY(){
  return this->x;
}

double Point3D::getZ(){
  return this->y;
}

Point3D Point3D::operator+(const Point3D& P2){
  return Point3D(x+P2.x, y+P2.y, z+P2.z);
};

Point3D Point3D::operator*(double s){
  return Point3D(x*s, y*s, z*s);
  
};

ostream& operator<<(ostream& o, const Point3D& P){
  o << "(" << P.x << ", " << P.y << ", " << P.z << ")"; 
  return o;
}

Point3D operator*(double s, Point3D& P){
  return P * s;
}
