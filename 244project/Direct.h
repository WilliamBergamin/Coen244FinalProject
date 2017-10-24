//Direct.h

#ifndef Direct_h
#define Direct_h
#include <iostream>
#include "Graph.h"
using namespace std;

class Direct : public Graph{
public:
    Direct();                       //Default constructor
    Direct(string);                 //Constructor
    Direct(const Direct&);          //Copy constructor
    void point();
    virtual ~Direct();              //Destructor
};


#endif /* Direct_h */
