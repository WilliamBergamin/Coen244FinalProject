//Graph.h

#ifndef Graph_h
#define Graph_h
#include "Node.h"
#include <iostream>
#include <vector>

class Graph {
protected:
    vector<Node> things;
    char* name;
    int size;
    Graph();                        //Default constructor
    Graph(string);                  //Constructor
    Graph(const Graph&);            //Copy constructor
    char* word(string);             //Convert string into char*
public:
    string notcap(string);          //returns a standardised string
    bool stop(string);              //returns false if stop is entered
    bool search(string);            //overloaded function to retrun a bool if node already exists
    void print();                   //prints the list of nodes/links
    void list();                    //Prints the list of nodes/links
    void add();                     //Add a node to the graph
    void quireV();                  //Graph queried by a given starting vertex
    void quireE();                  //Graph queried by a given edge
    void search();                  //Graph queried if a value is contained by any of its vertex
    void searchedge();              //Graph queried if a value is contained by any of its edges
    virtual ~Graph();               //Destructor
};
#endif
