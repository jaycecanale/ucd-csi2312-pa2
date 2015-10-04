// A 3-dimensional point class!
// Coordinates are double-precision floating point.
#ifndef PA2_Point_H
#define PA2_Point_H

#include <iostream>
#include <iomanip>
#include <cmath>

namespace Clustering {

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
        Point &operator*=(double); // Multiply a Point by a given number

        Point &operator/=(double); // Divide a Point by a given number



        //Friends
        friend Point &operator+=(Point &, const Point &); //Compounded addition operator

        friend Point &operator-=(Point &, const Point &); //Compounded subtraction operator

        friend Point operator+(const Point &, const Point &); //Adds two point's dimensions together
        friend const Point operator-(const Point &, const Point &); //Subtracts two point's dimensions from each other

        friend bool operator==(const Point &, const Point &); //Equivalent operator

        friend bool operator!=(const Point &, const Point &); //Nonequivalent operator

        friend bool operator<(const Point &, const Point &); //Less than operator

        friend bool operator>(const Point &, const Point &); //Greater than operator

        friend bool operator<=(const Point &, const Point &); //Less than or equal to

        friend bool operator>=(const Point &, const Point &); //Greater than or equal to

        friend std::ostream &operator<<(std::ostream &, const Point &); //Output the dimensions of a Point
    };
}
#endif // __point_h
