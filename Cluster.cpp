//
// Created by Jayce on 9/14/2015.
//

#include "Cluster.h"

namespace Clustering {

    //Copy Constructor
    Cluster::Cluster(const Cluster &cluster) {
        size = cluster.size;
        points = cluster.points;
    }

    //Overloaded operator=
    Cluster &Cluster::operator=(const Cluster &cluster) {
        if (&cluster != this) {
            size = cluster.size;
            points = cluster.points;
        }
        return *this;
    }

    //Destructor
    Cluster::~Cluster() {

    }

    //Add a point to Cluster
    void Cluster::add(PointPtr const &ptr)
    {
        NodePtr newNode = new Node;     // Create new Node

        if (points != nullptr) {        // If head is not empty
            NodePtr tempNode = points->next;    //Place next into tempNode
            PointPtr tempPoint = points->data;  //Place points into tempPoint

            if (ptr != tempPoint) {     // If Point is not equal to the tempPoint insert into head

                for (int i = 0; i < ptr->getDim(); i++) {
                    if (ptr->getValue(i) > tempPoint->getValue(i)) {    //If ptr is greater than tempPoint
                        points = newNode;                               // Place newNode into points
                        points->data = ptr;                             // Place ptr into points->data
                        newNode->next = tempNode;                       // place tempNode into newNode->next
                        newNode->data = tempPoint;                      // place tempPoint into newNode->data
                        size++;
                        break;
                    }
                }

//                NodePtr tempNode2 = tempNode->next;
//                PointPtr tempPoint2 = tempNode->data;
//
//                do {
//                    if (ptr != tempPoint2) {
//                        for (int i = 0; i < ptr->getDim(); i++) {
//                            if (ptr->getValue(i) > tempPoint2->getValue(i)) {
//                                tempNode->next = newNode;
//                                tempNode->data = ptr;
//                                newNode->next = tempNode2;
//                                newNode->data = tempPoint2;
//                                size++;
//                                tempNode2 = nullptr;
//                                break;
//                            }
//                        }
//                    }
//                }
//                while (tempNode2 != nullptr);
            }
        }
        else
        {
            points = newNode;
            points->data = ptr;
            points->next = nullptr;
            size++;
        }
    }

    //Remove a point from Cluster
    const PointPtr &Cluster::remove(PointPtr const &ptr) {
        if (points != nullptr) {
            if(points->data == ptr){
                points->data = NULL;
                points = points->next;
            }
        }

        return ptr;
    }

    // Output the Points in a Cluster
    std::ostream &Clustering::operator<<(std::ostream &ostream, const Cluster &cluster) {
        if (cluster.points != nullptr && cluster.size != 0) {
            NodePtr tempNodePtr = cluster.points;
            PointPtr tempPointPtr = cluster.points->data;

            std::cout << *tempPointPtr << std::endl;

            while(tempNodePtr->next != nullptr) {
                //tempNodePtr = tempNodePtr->next;
                tempPointPtr = tempNodePtr->data;

                std::cout << *tempPointPtr << std::endl;
            }
            std::cout << std::endl;
        }
        else {
            std::cout << "Cluster is empty" << std::endl;
        }

        return ostream;
    }
}
