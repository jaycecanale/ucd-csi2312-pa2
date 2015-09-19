// A 3-dimensional point class!
// Coordinates are double-precision floating point.
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

#ifndef __point_h
#define __point_h

class Point {

private:
   int dim;
   double* array;

public:
  Point(int);

  //Copy Constructor, Overloaded operator=, Destructor
  Point(const Point &point);
  Point &operator=(const Point &);
  ~Point();

  //Accessors and Mutators
  int getDim() const;
  double getArray(int) const;
  void setArray();

  //Functions
  double distanceTo(const Point&) const;

  void setDim(int newDim);

};

#endif // __point_h