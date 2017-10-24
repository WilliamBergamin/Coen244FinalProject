//Node.h

#ifndef Node_h
#define Node_h
#include <iostream>
#include "string.h"
#include <vector>
using namespace std;

class Node{
private:
    string name;
    vector<Node*> ptr;
public:
    Node();                                         //Default constructor
    Node(string);                                   //Constructor
    Node(const Node &);                             //Copy constructor
    void point(Node*);                              //Points to a certain node
    string getname();                               //Returns the name of a node
    unsigned long numberof();                       //Returns the size of the pointer
    string operator[](int a);                       //Overloaded [] operator
    void list();                                    //list le node and its links
    void print();                                   //Print node information
    virtual ~Node();                                //Destructor
};

#endif
