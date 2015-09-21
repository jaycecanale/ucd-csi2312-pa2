//
// Created by Jayce on 9/14/2015.
//

#include "Cluster.h"

Clustering::Cluster::Cluster(const Clustering::Cluster &cluster) {
    size = cluster.size;
    points = cluster.points;
}

Clustering::Cluster &Clustering::Cluster::operator=(const Clustering::Cluster &cluster) {
    if (&cluster != this) {
        size = cluster.size;
        points = cluster.points;
    }
    return *this;
}

void Clustering::Cluster::add(Clustering::PointPtr const &ptr) {

    Point newOne = new Point(&ptr);

}


/*there are three things we need to do:

chant [7:01 PM]
check whether the `Point` is already in the `Cluster`,

chant [7:01 PM]
wrap the `Point` in an `Lnode`,

chant [7:01 PM]7:01
and make the last `Lnode` in the `Cluster` link to the new
 `Lnode` so that it becomes a member of the list.*/

Clustering::Cluster::~Cluster() {

}
