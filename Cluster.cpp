//
// Created by Jayce on 9/14/2015.
//

#include "Cluster.h"

namespace Clustering {

    //Copy Constructor
    Clustering::Cluster::Cluster(const Clustering::Cluster &cluster) {
        size = cluster.size;
        points = cluster.points;
    }

    //Overloaded operator=
    Clustering::Cluster &Clustering::Cluster::operator=(const Clustering::Cluster &cluster) {
        if (&cluster != this) {
            size = cluster.size;
            points = cluster.points;
        }
        return *this;
    }
}

    //Destructor


    void Clustering::Cluster::add(PointPtr const &ptr) {
        LNodePtr newNode = new LNode;
        newNode->p = ptr;
        newNode->next = nullptr;
        points = newNode;
    }






