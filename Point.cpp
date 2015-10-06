#include "Point.h"

namespace Clustering {

    Point::Point(int initDim) {
        dim = initDim;
        values = new double[dim]();
    }

//Copy Constructor
    Point::Point(const Clustering::Point &point) {
        dim = point.dim;

        values = new double[point.dim];

        for (int i = 0; i < dim; i++) {
            values[i] = point.values[i];
        }
    }

//Overloaded operator=
    Point &Clustering::Point::operator=(const Clustering::Point &point) {
        if (&point != this) {
            dim = point.dim;
            values = new double[point.dim];
            for (int i = 0; i < dim; i++) {
                values[i] = point.values[i];
            }
        }

        return *this;
    }

//Destructor
    Point::~Point() {
        delete[] values;
        values = NULL;
    }

// Mutator methods

    void Point::setDim(int newDim) {
        dim = newDim;
    }

    void Point::setValue(int index, double value) {
        values[index] = value;
    }

//Accessors
//Return the current values of private member variables
    int Point::getDim() const {
        return dim;
    }

    double Point::getValue(int value) const {
        return values[value];
    }

//Functions
//This function calculates the distance between two points
    double Point::distanceTo(const Point &point) const {
        double distance = 0;
        double something = 0;

        for (int i = 0; i < getDim(); i++) {
            something += pow((point.values[i] - values[i]), 2);
        }

        distance = sqrt(something);

        return distance;

    }

//Members
    //Multiply a Point by a given number
    Point &Point::operator*=(double num) {
        for (int i = 0; i < dim; i++) {
            values[i] *= num;
        }
        return *this;
    }

    //Divide a Point by a given number
    Point &Point::operator/=(double num) {
        if (num == 0) {
            std::cout << "Not divisable by zero" << std::endl;
        }
        else {
        for (int i = 0; i < dim; i++) {
            values[i] /= num;
        }
        }
        return *this;
    }


//Friends

// Adds one point's dimensions to a particular point
    Point &operator+=(Point &point, const Point &point1) {
        for (int i = 0; i < point.dim; i++) {
            point.values[i] += point1.values[i];
        }
        return point;
    }

// Subtracts one point's dimensions from a particular point
    Point &operator-=(Point &point, const Point &point1) {

        for (int i = 0; i < point.dim; i++) {
            point.values[i] -= point1.values[i];
        }
        return point;
    }

//Adds two points dimensions together
    Point operator+(const Point &point, const Point &point1) {

        Point sum(point.dim);

        for (int i = 0; i < point.dim; i++) {
            sum.values[i] = point.values[i] + point1.values[i];
        }

        return sum;
    }

//Subtracts two points dimensions from each other
    const Point operator-(const Point &point, const Point &point1) {

        Point diff(point.dim);

        for (int i = 0; i < point.dim; i++) {
            diff.values[i] = point.values[i] - point1.values[i];
        }

        return diff;
    }

// Determines whether two points are equal
    bool operator==(const Point &point, const Point &point1) {
        bool equal = true;
        int index = 0;

        while (index < point.dim)
            if (point.values[index] == point1.values[index]) {
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
            if (point.values[index] == point1.values[index]) {
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
            if (point.values[i] > point1.values[i]) {
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
            if (point.values[i] < point1.values[i]) {
                greaterThan = false;
                break;
            }
        }
        return greaterThan;
    }

    //Determines if a point is less than or equal to a point
    bool operator<=(const Point &point, const Point &point1) {
        bool lessOrEqual = true;

        for (int i = 0; i < point.dim; i++) {
            if (point.values[i] >= point1.values[i]) {
                lessOrEqual = false;
                break;
            }
        }
        return lessOrEqual;
    }

    //Determines whether a point is greater than or equal to a point
    bool operator>=(const Point &point, const Point &point1) {
        bool greaterOrEqual = true;

        for (int i = 0; i < point.dim; i++) {
            if (point.values[i] <= point1.values[i]) {
                greaterOrEqual = false;
                break;
            }
        }
        return greaterOrEqual;
    }

    //Output the dimensions in a Point
    std::ostream &operator<<(std::ostream &ostream, const Point &point) {
        for(int i = 0; i < point.dim; i++){
            std::cout << point.getValue(i) << " ";
        }
        std::cout << std::endl;

        return ostream;
    }
}
