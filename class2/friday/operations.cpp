#include <iostream>

#include "point3d.h"


using namespace std;

void printPoint(Point3D P){
  cout << "(" << P.getX() << ", " << P.getY() << ", " << P.getZ() << ")" << endl;
};

int main(){
  
  Point3D A;
  Point3D B(2, 3, 2);
  
  A.setValues(4, 4.5, 6.5);

  cout << A << endl;
  cout << B << endl;

  Point3D C = B;

  cout << C << endl;

  Point3D D = A * 2.0;
  
  cout << D << endl;

  Point3D E = 2 * B;

  cout << E << endl;
  return 0;

}
