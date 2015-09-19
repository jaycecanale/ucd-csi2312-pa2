//
// Functions
//
/*
#include "Point.h"
#include <cmath>
double inputX;
double inputY;
double inputZ;
Point p1;
Point p2;
Point p3;

// Receives the coordinates for Point1

void setCoordsPoint1() {
    cout << "Please input Point 1 coordinates" << endl;
    cout << "   X: " ;
    cin >> inputX;
    cout << "   Y: " ;
    cin >> inputY;
    cout << "   Z: " ;
    cin >> inputZ;
    cout << endl;

    p1.setX(inputX);
    p1.setY(inputY);
    p1.setZ(inputZ);
}

// Receives the coordinates for Point2

void setCoordsPoint2() {
    cout << "Please input Point 2 coordinates" << endl;
    cout << "   X: " ;
    cin >> inputX;
    cout << "   Y: " ;
    cin >> inputY;
    cout << "   Z: " ;
    cin >> inputZ;
    cout << endl;

    p2.setX(inputX);
    p2.setY(inputY);
    p2.setZ(inputZ);
}

// Receives the coordinates for Point3

void setCoordsPoint3() {
    cout << "Please input Point 3 coordinates" << endl;
    cout << "   X: " ;
    cin >> inputX;
    cout << "   Y: " ;
    cin >> inputY;
    cout << "   Z: " ;
    cin >> inputZ;
    cout << endl;

    p3.setX(inputX);
    p3.setY(inputY);
    p3.setZ(inputZ);

}

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
