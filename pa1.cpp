// Jayce Canale
// 830243111
// PA 2

#include "Point.h"

double computeArea(Point &p1, Point &p2, Point &p3);

int main(void) {

    int inputDim;

    cout << "Please enter the number of dimensions" << endl;
    cin >> inputDim;

    Point p1(inputDim);
    Point p2(p1);

    cout << "There are " << p1.getDim() << " dimensions in point 1" << endl;
    cout << "There are " << p2.getDim() << " dimensions in point 2" << endl;

    p1.setArray();
    p2.setArray();

    cout << "The distance between p1 and p2 is " << p1.distanceTo(p2);

    //delete [] p1.array;
    //delete [] p2.array;
    p1.Point::~Point();
    p2.Point::~Point();

    return 0;
}

//************************************************
// Function Definitions

//Computes the area of the object

double computeArea(Point &p1, Point &p2, Point &p3) {

    double area = 0;
    double sideA = 0;
    double sideB = 0;
    double sideC = 0;
    double s = 0;

    sideA = p1.distanceTo(p2);
    sideB = p2.distanceTo(p3);
    sideC = p3.distanceTo(p1);

    s = (sideA + sideB + sideC) / 2;

    area = sqrt(s*(s-sideA)*(s-sideB)*(s-sideC));

    return area;
}


