//
// Created by Jayce on 9/14/2015.
//

#ifndef PA1_CLUSTER_H
#define PA1_CLUSTER_H

#include "Point.h"

namespace Clustering {

    typedef Point *PointPtr;
    typedef struct Lnode *LNodePtr;

    struct LNode {
        PointPtr p;
        LNodePtr next;
    };

    class Cluster {
        int size;
        LNodePtr points;

    public:
        Cluster() : size(0), points(nullptr) {};

        //Big 3: Copy, Overloaded operator=, Destructor
        Cluster(const Cluster &);

    };
}
#endif //PA1_CLUSTER_H
