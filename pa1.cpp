// Jayce Canale
// 830243111
// PA 2

#include "Point.h"

using namespace Clustering;

double computeArea(Point &p1, Point &p2, Point &p3);

int main(void) {

    int inputDim;
    double inputVal;

    cout << "Please enter the number of dimensions" << endl;
    cin >> inputDim;

    Point p1(inputDim);
    Point p2(inputDim);

    cout << "Enter the values for Point 1" << endl;

    for (int i = 0; i < p1.getDim(); i++) {
        cin >> inputVal;
        p1.setValue(i, inputVal);
    }

    cout << "Enter the values for Point 2" << endl;

    for (int i = 0; i < p2.getDim(); i++) {
        cin >> inputVal;
        p2.setValue(i, inputVal);
    }

    cout << endl;

    if (p1 < p2) {
        cout << "p1 is less than p2" << endl;
    }
    else
        cout << "p1 is greater than p2" << endl;


    cout << "The values for Point 1 are " ;

    for(int i = 0; i < p1.getDim(); i++){
        cout << p1.getValue(i) << " " ;
    }

    cout << endl;

    p1.Point::~Point();


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


