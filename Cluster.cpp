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
    void Cluster::add(PointPtr const &ptr) {
        LNodePtr newNode = new LNode;     // Create new LNode

        if (points == nullptr) {        //If head is empty
            points = newNode;           //Assign newNode to head
            points->p = ptr;         //Assign ptr to head's p
            points->next = nullptr;     //Assign head's next to NULL
        }
        else {
        LNodePtr prevNode = points;
        PointPtr prevPoint = points->p;

            if(prevPoint != ptr) {
                if (*ptr > *prevPoint || *ptr == *prevPoint) {
                    points = newNode;
                    points->p = ptr;
                    newNode->next = prevNode;
                }
                else if (prevNode->next != nullptr) {
                    while (prevNode != nullptr) {
                        LNodePtr nextNode = prevNode->next;
                        PointPtr nextPoint = nextNode->p;

                        if (nextPoint == ptr) {
                            break;
                        }
                        else {
                            if (*ptr > *nextPoint || *ptr == *nextPoint) {
                                prevNode = newNode;
                                prevNode->p = ptr;
                                newNode->next = nextNode;
                                newNode->next->p = nextPoint;
                                break;
                            }
                            else {
                                prevPoint = nextPoint;
                                prevNode = nextNode;
                                break;
                            }
                        }
                    }
                }
                else{
                    points->next = newNode;
                    points->next->p = ptr;
                    newNode->next = nullptr;
                }
            }
        }
        size++;
    }

    //Remove a point from Cluster
    const PointPtr &Cluster::remove(PointPtr const &ptr) {
        if (points != nullptr) {                   //If list is not empty
            LNodePtr currentNode = points;
            LNodePtr trailNode = 0;

            while (currentNode != nullptr){         //Traverses the list to find ptr
                if(currentNode->p == ptr) {
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
            LNodePtr tempNodePtr = cluster.points;
            PointPtr tempPointPtr = cluster.points->p;

            std::cout << *tempPointPtr ;

            while(tempNodePtr->next != nullptr) {
                tempNodePtr = tempNodePtr->next;
                tempPointPtr = tempNodePtr->p;

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
        LNodePtr lhsNodePtr = lhs.points;
        LNodePtr rhsNodePtr = rhs.points;

        if (lhs.size == rhs.size) {
            while(lhsNodePtr != nullptr) {
                if (lhsNodePtr->p != rhsNodePtr->p) {
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
            LNodePtr tempNodePtr = rhs.points;

            while (tempNodePtr != nullptr){
                this->add(tempNodePtr->p);
                tempNodePtr = tempNodePtr->next;
            }
            return *this;
        }
    }

    Cluster &Cluster::operator-=(const Cluster &rhs) {
        if (rhs.size > 0) {
            LNodePtr rhsNodePtr = rhs.points;
            LNodePtr thisNodePtr = points;

            while(thisNodePtr != nullptr) {
                    if (thisNodePtr->p == rhsNodePtr->p) {
                        remove(thisNodePtr->p);
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
        LNodePtr lhsNodePtr = lhs.points;
        LNodePtr rhsNodePtr = rhs.points;

        while (lhsNodePtr != nullptr && rhsNodePtr != nullptr){         //Traverse both lists until we reach nullptr
            sum.add(lhsNodePtr->p);                                  //Add lhsNodePtr p to Cluster
            sum.add(rhsNodePtr->p);                                  //Add rhsNodePtr p to Cluster
            lhsNodePtr = lhsNodePtr->next;                              //Move to next in lhsNodePtr
            rhsNodePtr = rhsNodePtr->next;                              //Move to next in rhsNodePtr
        }
        return sum;
    }

    const Cluster operator-(const Cluster &lhs, const Cluster &rhs) {
        Cluster difference;
        LNodePtr lhsNodePtr = lhs.points;
        LNodePtr rhsNodePtr = rhs.points;

        while (lhsNodePtr != nullptr && rhsNodePtr != nullptr) {        //Traverse both lists until we reach nullptr
            if (lhsNodePtr->p == rhsNodePtr->p){                              //If two Nodes match
                difference.add(lhsNodePtr->p);                       //Add the node to the new Cluster
            }
            lhsNodePtr = lhsNodePtr->next;                              //Move to next in lhsNodePtr
            rhsNodePtr = rhsNodePtr->next;                              //Move to next in rhsNodePtr
        }
        return difference;
    }

    Cluster &Cluster::operator+=(const Point &rhs) {                    //Adds a Point to a Cluster
        LNodePtr newNode = new LNode;
        newNode->p = new Point(rhs);

        this->add(newNode->p);

        return *this;
    }

    Cluster &Cluster::operator-=(const Point &rhs) {
        if (points != nullptr) {                   //If list is not empty
            LNodePtr currentNode = points;
            LNodePtr trailNode = 0;

            while (currentNode != nullptr){         //Traverses the list to find rhs
                if(currentNode->p == &rhs) {
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
        return *this;
    }

    const Cluster operator+(const Cluster &lhs, const PointPtr &rhs) {
        Cluster sum;

        sum.add(rhs);
        sum += lhs;

        return sum;
    }
}
