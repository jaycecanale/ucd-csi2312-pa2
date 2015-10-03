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
            NodePtr tempNode = points->next;
            PointPtr tempPoint = points->data;

            if (ptr != tempPoint) {     // If Point is not equal to the next point insert into head
                for (int i = 0; i < ptr->getDim(); i++) {
                    if (ptr->getValue(i) > tempPoint->getValue(i)) {
                        points = newNode;
                        points->data = ptr;
                        newNode->next = tempNode->next;
                        newNode->data = tempNode->data;
                        size++;
                        break;
                    }
                }

                NodePtr tempNode2 = tempNode->next;
                PointPtr tempPoint2 = tempNode->data;

                do {
                    if (ptr != tempPoint2) {
                        for (int i = 0; i < ptr->getDim(); i++) {
                            if (ptr->getValue(i) > tempPoint2->getValue(i)) {
                                tempNode->next = newNode;
                                tempNode->data = ptr;
                                newNode->next = tempNode2;
                                newNode->data = tempPoint2;
                                size++;
                                tempNode2 = nullptr;
                                break;
                            }
                        }
                    }
                }
                    while (tempNode2 != nullptr);
            }
        }
        else
        {
            points = newNode;
            points->data = ptr;
            size++;
        }
    }

    //Remove a point from Cluster
    const PointPtr &Cluster::remove(PointPtr const &ptr) {
        if (points != nullptr) {
            bool found = true;

            while(!found) {
                
            }
        }

        return 0;
    }



}






