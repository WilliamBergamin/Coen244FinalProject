//Undirected

#ifndef Undirect_h
#define Undirect_h
#include <iostream>
#include "Graph.h"
using namespace std;

class Undirected : public Graph{
public:
    Undirected();                         //Default constructor
    Undirected(string);                    //Constructor
    Undirected(const Undirected&);        //Copy constructor
    void point();
    virtual ~Undirected();                //Destructor
};

#endif
