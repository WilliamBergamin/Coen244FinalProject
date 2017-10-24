//Node.cpp

#include <stdio.h>
#include <iostream>
#include <string>
#include "Node.h"
#include "string.h"
using namespace std;

//Default Constructor
Node::Node() {
    name = "N/A";
}

//Constructor
Node::Node(string n){
    name=n;
}

//Copy constructor
Node::Node(const Node & copy){
    name= copy.name;
    for (int i =0; i<ptr.size(); i++){
        ptr[i] = copy.ptr[i];
    }
}

//Returns the name of a node
string Node::getname(){
    return name;
}

//Points to a certain node
void Node::point(Node* nodepoint){
    ptr.push_back(nodepoint);
}

//Prints node information
void Node::print(){
    if (ptr.size() != 0){
        cout<<"Node "<<getname()<<" linked with:"<<endl;
        for (int i =0; i<ptr.size(); i++){
            cout<<"\t\t"<<i+1<<". "<<ptr[i]->getname()<<endl;
        }
    }else{
        cout<<"Node "<<getname()<<endl;
    }
}
void Node::list(){
    if (ptr.size() != 0){
        for (int i =0; i<ptr.size(); i++){
            if(i != ptr.size()-1){
                cout<<"("<<getname()<<","<<ptr[i]->getname()<<"),";
            }else{
                cout<<"("<<getname()<<","<<ptr[i]->getname()<<")";
            }
        }
    }else{
        cout<<"("<<getname()<<")";
    }
}

//Returns size of the pointer
unsigned long Node::numberof(){
    return ptr.size();
}

//Overloaded [] operator
string Node::operator[](int a){
    return ptr[a]->name;
}

//Destructor
Node::~Node(){

}
