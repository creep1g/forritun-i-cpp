#include <iostream>
using namespace std;

class Point3D {
  public:
    Point3D();

    Point3D(double xx, double yy, double zz);
    Point3D(const Point3D& P); // Copy constructor
    virtual ~Point3D();

    void setValues(double xx, double yy, double zz);
    
    double getX();
    double getY();
    double getZ();

    Point3D operator+(const Point3D& P2);
    Point3D operator*(double s);

    friend Point3D operator*(double s, Point3D& P);
    friend ostream& operator<<(ostream& o, const Point3D& P);

  private:
    double x;
    double y;
    double z;


};
