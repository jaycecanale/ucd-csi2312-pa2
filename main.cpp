// Jayce Canale
// 830243111
// PA 2

#include "Point.h"
#include "Cluster.h"

using namespace Clustering;

//double computeArea(Point &p1, Point &p2, Point &p3);

int main(void) {

    //Point p1(3);
    //p1.setValue(0, 4);

    PointPtr p1 = new Point(3);
    p1->setValue(0, 4);
    p1->setValue(1, 5);
    p1->setValue(2, 6);

    PointPtr p2 = new Point(3);
    p2->setValue(0, 7);
    p2->setValue(1, 8);
    p2->setValue(2, 9);

    PointPtr p3 = new Point(3);

    std::cout << "P1 has " << p1->getDim() << " Dimensions " << std::endl;

//    std::cout << "The values of P1 are " ;
//    for (int i = 0; i < p1->getDim(); i++){
//        std::cout << p1->getValue(i) << " " ;
//    }

    //std::cout << std::endl;

    *p3 = *p1 + *p2;

//    for (int i = 0; i < p3->getDim(); i++) {
//        std::cout << p3->getValue(i) << " " ;
//    }

    std::cout << *p1;
    std::cout << *p3;

    Cluster c1;

    c1.add(p1);
    c1.add(p2);
//    c1.add(p3);
//    c1.remove(p1);

    std::cout << c1;

    return 0;
}


//************************************************
// Function Definitions

//Computes the area of the object

/*double computeArea(Point &p1, Point &p2, Point &p3) {

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
}*/
