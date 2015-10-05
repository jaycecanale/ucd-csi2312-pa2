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
        else{
            NodePtr tempNode;           //Create a temporary node
            PointPtr tempPoint;         //and a temporary point

            tempNode = points;          //Assign the head into temporary node
            tempPoint = points->data;   //and assign the Points into temporary point

            points = newNode;           //Then assign the newNode into the head
            points->data = ptr;         //and the ptr into the heads data
            points->next = tempNode;    //and point the heads next to the tempNode
        }
        size++;                         //increase size

        if(points->next != nullptr){
            NodePtr currNode = points;
            NodePtr tempNode;
            PointPtr tempPoint;

            while(currNode != nullptr){
                if(currNode->data > currNode->next->data){
                    break;
                }
                else{
                    tempNode = currNode;
                    tempPoint = currNode->data;

                    currNode = currNode->next;
                    currNode->data = currNode->next->data;

                    currNode->next = tempNode;
                    currNode->next->data = tempPoint;
                }
                currNode = currNode->next;
            }
        }
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
        NodePtr lhsNodePtr = lhs.points;
        NodePtr rhsNodePtr = rhs.points;

        if (lhs.size == rhs.size) {
            while(lhsNodePtr != nullptr) {
                if (lhsNodePtr->data != rhsNodePtr->data) {
                        equal = false;
                    }
                    else {
                        equal = true;
                    }
                lhsNodePtr = lhsNodePtr->next;
                rhsNodePtr = rhsNodePtr->next;
            }
        }
        return equal;
    }

    //Adds one Clusters points to another
    Cluster &Cluster::operator+=(const Cluster &rhs) {
        if (rhs.size > 0) {
            NodePtr tempNodePtr = rhs.points;

            while (tempNodePtr != nullptr){
                this->add(tempNodePtr->data);
                tempNodePtr = tempNodePtr->next;
            }
            return *this;
        }
    }

    Cluster &Cluster::operator-=(const Cluster &rhs) {
        if (rhs.size > 0) {
            NodePtr rhsNodePtr = rhs.points;
            NodePtr thisNodePtr = points;

            while(thisNodePtr != nullptr) {
                    if (thisNodePtr->data == rhsNodePtr->data) {
                        remove(thisNodePtr->data);
                    }
                thisNodePtr = thisNodePtr->next;
                rhsNodePtr = rhsNodePtr->next;
            }
        }
        return *this;
    }

    //Adds two Clusters Points together to create new Cluster
    const Cluster operator+(const Cluster &lhs, const Cluster &rhs) {
        Cluster sum;
        NodePtr lhsNodePtr = lhs.points;
        NodePtr rhsNodePtr = rhs.points;

        while (lhsNodePtr != nullptr && rhsNodePtr != nullptr){         //Traverse both lists until we reach nullptr
            sum.add(lhsNodePtr->data);                                  //Add lhsNodePtr data to Cluster
            sum.add(rhsNodePtr->data);                                  //Add rhsNodePtr data to Cluster
            lhsNodePtr = lhsNodePtr->next;                              //Move to next in lhsNodePtr
            rhsNodePtr = rhsNodePtr->next;                              //Move to next in rhsNodePtr
        }
        return sum;
    }

    const Cluster operator-(const Cluster &lhs, const Cluster &rhs) {
        Cluster difference;
        NodePtr lhsNodePtr = lhs.points;
        NodePtr rhsNodePtr = rhs.points;

        while (lhsNodePtr != nullptr && rhsNodePtr != nullptr) {        //Traverse both lists until we reach nullptr
            if (lhsNodePtr->data == rhsNodePtr->data){                              //If two Nodes match
                difference.add(lhsNodePtr->data);                       //Add the node to the new Cluster
            }
            lhsNodePtr = lhsNodePtr->next;                              //Move to next in lhsNodePtr
            rhsNodePtr = rhsNodePtr->next;                              //Move to next in rhsNodePtr
        }
        return difference;
    }
}
