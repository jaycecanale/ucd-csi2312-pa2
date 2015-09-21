// Jayce Canale
// 830243111
// PA 2

#include "Point.h"

using namespace Clustering;

    double computeArea(Point &p1, Point &p2, Point &p3);

    int main(void) {

        int inputDim;
        double inputVal;

        std::cout << "Please enter the number of dimensions" << std::endl;
        std::cin >> inputDim;

        Point p1(inputDim);
        Point p2(inputDim);
        Point p3(inputDim);
        //Cluster(p1);

        std::cout << "Enter the values for Point 1" << std::endl;

        for (int i = 0; i < p1.getDim(); i++) {
            std::cin >> inputVal;
            p1.setValue(i, inputVal);
        }

        std::cout << "Enter the values for Point 2" << std::endl;

        for (int i = 0; i < p2.getDim(); i++) {
            std::cin >> inputVal;
            p2.setValue(i, inputVal);
        }

        std::cout << std::endl;

        if (p1 < p2) {
            std::cout << "p1 is less than p2" << std::endl;
        }
        else
            std::cout << "p1 is greater than p2" << std::endl;


        std::cout << "The values for Point 1 are ";

        p3 = p1 + p2;

        for (int i = 0; i < p1.getDim(); i++) {
            std::cout << p3.getValue(i) << " " ;
        }

        std::cout << std::endl;

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

        area = sqrt(s * (s - sideA) * (s - sideB) * (s - sideC));

        return area;
    }