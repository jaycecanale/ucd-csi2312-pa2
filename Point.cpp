#include <array>
#include "Point.h"

Point::Point(int initDim) {
  dim = initDim;
  array = new double[dim]();
}

//Copy Constructor
Point::Point(const Point &point) {
  dim = point.dim;

  array = new double[point.dim];

  for (int i = 0; i < dim; i++){
    array[i] = point.array[i];
  }
}

//Overloaded Assignment Operator
Point &Point::operator=(const Point &point) {
  if (&point != this) {
    dim = point.dim;
    array = new double[point.dim];
    for (int i = 0; i < dim; i++) {
      array[i] = point.array[i];
    }
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

void Point::setValue(int index, double value) {
  array[index] = value;

}

//Accessors
//Return the current values of private member variables
int Point::getDim() const {
  return dim;
}

double Point::getValue(int value) const {
  return array[value];
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

//Members

//Friends

// Adds one point's dimensions to a particular point
Point &operator+=(Point &point, const Point &point1) {
  for (int i = 0; i < point.dim; i++) {
    point.array[i] += point1.array[i];
  }
  return point;
}

// Subtracts one point's dimensions from a particular point
Point &operator-=(Point &point, const Point &point1) {

  for (int i = 0; i < point.dim; i++) {
    point.array[i] -= point1.array[i];
  }
  return point;
}

//Adds two points dimensions together
Point operator+(const Point &point, const Point &point1) {

  Point sum(point.dim);

  for (int i = 0; i < point.dim; i++){
    sum.array[i] = point.array[i] + point1.array[i];
  }

  return sum;
}

//Subtracts two points dimensions from each other
const Point operator-(const Point &point, const Point &point1) {

  Point diff(point.dim);

  for (int i = 0; i < point.dim; i++ ) {
    diff.array[i] = point.array[i] - point1.array[i];
  }

  return diff;
}

// Determines whether two points are equal
bool operator==(const Point &point, const Point &point1) {
  bool equal = true;
  int index = 0;

  while (index < point.dim)
    if (point.array[index] == point1.array[index]){
      equal = true;
      index++;
    }
    else {
      equal = false;
      break;
    }
    return equal;
  }

// Determines whether two points are unequal
bool operator!=(const Point &point, const Point &point1) {
  bool equal = false;
  int index = 0;

  while (index < point.dim)
    if (point.array[index] == point1.array[index]) {
      equal = false;
      index++;
    }
  else {
      equal = true;
      break;
    }
  return equal;
}

// Determines if a point is less than another point
bool operator<(const Point &point, const Point &point1) {
  bool lessThan = true;

  for (int i = 0; i < point.dim; i++) {
    if (point.array[i] > point1.array[i]) {
      lessThan = false;
      break;
    }
  }
  return lessThan;
}

//Determines if a point is greater than another point
bool operator>(const Point &point, const Point &point1) {
  bool greaterThan = true;

  for (int i = 0; i < point.dim; i++) {
    if (point.array[i] < point1.array[i]) {
      greaterThan = false;
      break;
    }
  }
  return greaterThan;
}

bool operator<=(const Point &point, const Point &point1) {
  bool lessOrEqual = true;

  for (int i = 0; i < point.dim; i++) {
    if (point.array[i] >= point1.array[i]) {
      lessOrEqual = false;
      break;
    }
  }
  return lessOrEqual;
}


bool operator>=(const Point &point, const Point &point1) {
  bool greaterOrEqual = true;

  for (int i = 0; i < point.dim; i++) {
    if (point.array[i] <= point1.array[i]) {
      greaterOrEqual = false;
      break;
    }
  }
  return greaterOrEqual;
}



