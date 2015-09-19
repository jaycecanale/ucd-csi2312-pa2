#include <array>
#include "Point.h"

Point::Point(int initDim) {
  dim = initDim;
  array = new double[dim]();
}

/*Point::Point(int initDim) {
  dim = initDim;
}

Point::Point(int initDim, double *initArray) {
  dim = initDim;
  array = new double[dim]();
}*/

//Copy Constructor
Point::Point(const Point &point) {
  dim = point.dim;
  array = new double[point.dim];
}

//Overloaded Assignment Operator
Point &Point::operator=(const Point &point) {
  if (&point != this) {
    dim = point.dim;
    array = new double [point.dim];
  }
  return *this;
}

//Destructor
Point::~Point() {
  delete [] array;
  array = NULL;
}

// Mutator methods

void Point::setDim(int newDim) {
  dim = newDim;
}

void Point::setArray() {
  for (int i = 0; i < dim; i++) {
    cin >> array[i];
  }
}

//Accessors
//Return the current values of private member variables
int Point::getDim() const {
  return dim;
}

double Point::getArray(int) const {
  return * array;
}

//Functions
//This function calculates the distance between two points
double Point::distanceTo(const Point &point) const {
  double distance = 0;
  double something = 0;

  for (int i = 0; i < getDim(); i++) {
    something += pow((point.array[i] - array[i]), 2);
  }

  distance = sqrt(something);

  return distance;

}



