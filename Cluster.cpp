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

        if (points == nullptr) {        //If head is empty
            points = newNode;           //Assign newNode to head
            points->data = ptr;         //Assign ptr to head's data
            points->next = nullptr;     //Assign head's next to NULL
        }
        else{                           //else
            NodePtr tempNode;           //Create a temporary Node
            PointPtr tempPoint;         //And a temporary Point

            tempNode = points;          //Assign the head into temporary node
            tempPoint = points->data;   //and assign the Points into temporary Point

            points = newNode;           //Then assign the newNode into the head
            points->data = ptr;         //and the ptr into the heads data
            points->next = tempNode;    //and point the heads next to the tempNode
        }
        size++;                         //increase size

//        for(int seek = 0; seek < size; seek++) {
//            for(int i = seek + 1; i < ptr->getDim(); i++) {
//                if (points->data->getValue(i) < ptr->getValue(seek)) {
//                    NodePtr tempNode;           //Create a temporary Node
//                    PointPtr tempPoint;         //And a temporary Point
//
//                    tempNode = points;          //Assign the head into temporary node
//                    tempPoint = points->data;   //and assign the Points into temporary Point
//
//                    points = newNode;           //Then assign the newNode into the head
//                    points->data = ptr;         //and the ptr into the heads data
//                    points->next = tempNode;    //and point the heads next to the tempNode
//                }
//            }
//        }
    }

    //Remove a point from Cluster
    const PointPtr &Cluster::remove(PointPtr const &ptr) {
        if (points != nullptr) {                   //If list is not empty
            NodePtr currentNode = points;
            NodePtr trailNode = 0;

            while (currentNode != nullptr){         //Traverses the list to find ptr
                if(currentNode->data == ptr) {
                    break;
                }
                else {
                    trailNode = currentNode;
                    currentNode = currentNode->next;
                }
            }

            if(currentNode == nullptr){             //If end of list is reached
                std::cout << "Not Found \n";        //output "Not Found"
            }
            else{                                   //Delete from head
                if (points == currentNode) {
                    points = points->next;
                }
                else {                              //Delete from beyond the head
                    trailNode->next = currentNode->next;
                }
                delete currentNode;
                size--;
            }
        }

        return ptr;
    }

    // Output the Points in a Cluster
    std::ostream &Clustering::operator<<(std::ostream &ostream, const Cluster &cluster) {
        if (cluster.points != nullptr && cluster.size != 0) {
            NodePtr tempNodePtr = cluster.points;
            PointPtr tempPointPtr = cluster.points->data;

            std::cout << *tempPointPtr ;

            while(tempNodePtr->next != nullptr) {
                tempNodePtr = tempNodePtr->next;
                tempPointPtr = tempNodePtr->data;

                std::cout << *tempPointPtr ;
            }

        }
        else {
            std::cout << "Cluster is empty" << std::endl;
        }

        return ostream;
    }

    //Determines if two points share the same address
    bool operator==(const Cluster &lhs, const Cluster &rhs) {
        bool equal = false;

        if (lhs.size == rhs.size) {
            for(int i = 0; i < lhs.size; i++) {
                if (lhs.points->data->getValue(i) == rhs.points->data->getValue(i)){
                    equal = true;
                }
                else {
                    equal = false;
                }
            }
        }
        return equal;
    }
}






