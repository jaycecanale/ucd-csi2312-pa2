// A 3-dimensional point class!
// Coordinates are double-precision floating point.
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;


#ifndef PA2_Point_H
#define PA2_Point_H

class Point {

private:
    int dim;
    double *array;

public:
    Point(int);

    //Copy Constructor, Overloaded operator=, Destructor
    Point(const Point &point);

    Point &operator=(const Point &);

    ~Point();

    //Accessors and Mutators
    int getDim() const;

    double getValue(int) const;

    void setValue(int, double);

    //Functions
    double distanceTo(const Point &) const;

    void setDim(int newDim);

    //Overloaded Operators

    //Members


    //Friends
    friend Point &operator+=(Point &, const Point &);

    friend Point &operator-=(Point &, const Point &);

    friend Point operator+(const Point &, const Point &); //Adds two point's dimensions together
    friend const Point operator-(const Point &, const Point &); //Subtracts two point's dimensions from each other

    friend bool operator==(const Point &, const Point &);

    friend bool operator!=(const Point &, const Point &);

    friend bool operator<(const Point &, const Point &);

    friend bool operator>(const Point &, const Point &);

    friend bool operator<=(const Point &, const Point &);

    friend bool operator>=(const Point &, const Point &);
};

#endif // __point_h
