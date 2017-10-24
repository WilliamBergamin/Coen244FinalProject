
//Graph.cpp

#include <stdio.h>
#include <iostream>
#include "Graph.h"
using namespace std;

//Default constructor
Graph::Graph(){
    name = word("N/A");
    size = 0;
}

//Contructor
Graph::Graph(string graphName){
    name = word(graphName);
    size=0;
}

//Copy constructor
Graph::Graph(const Graph& copyGraph){
    size = copyGraph.size;
    name = copyGraph.name;
    for(int i=0; i<size; i++){
        things[i]=copyGraph.things[i];
    }
}

//Convert a string to a char*
char* Graph::word(string n){
    char* ptrchar = new char[n.length()+1];
    for(int i=0; i < (n.length()+1); i++){
        ptrchar[i]=n[i];
    }
    return ptrchar;
}

bool Graph::stop(string stop){
    stop = notcap(stop);
    if(stop == "stop"){
        return true;
    }else{
        return false;
    }
}

//function that turns every upper case to lower case
string Graph::notcap(string word){
    for(int i = 0; i<word.length(); i++){
        if(word[i]>=65 && word[i]<=92){
            word[i]=word[i]+32;
        }
    }
    return word;
}

//function that looks if a node is present, if so return true
bool Graph::search(string lookingfor){
    bool found = false;
    for(int i = 0; i< things.size(); i++){
        if(lookingfor == things[i].getname()){
            found = true;
        }
    }
    return found;
}


//Add a node to a graph
void Graph::add(){
    string n;
    do{
        cout<<"Enter a name for the new object that will be added to graph \""<<this->name<<"\" or \"stop\" to stop: ";
        cin>>n;
        
        if(search(n)){
            cout<< n <<" already exist in "<<name<<endl;
        }else if(!stop(n)){
            Node newnode(n);
            things.push_back(newnode);           //Store copy in vector
            ++size;
        }
            
    }while(!stop(n));
}

//function to print out the nodes and edges of the graph
void Graph::list(){
    cout<<endl<<"List for "<<name<<" :\n";
    cout<<"{";
    for(int i=0; i<size; i++){
        if(i == size-1){
            things[i].list();
        }else{
            things[i].list();
            cout<<",";
        }
    }
    cout<<"}"<<endl<<endl;
}

//Function that prints the nodes and what each of them point to
void Graph::print(){
    cout<<"List for "<<name<<" :\n";
    for(int i=0; i<size; i++){
        cout<<"->";
        things[i].print();
    }
}


//Function that starts at a node possible to select a node to which it points and print that one out so forth until the user want to stop
//Function - A graph can be queried if a value is contained by any of its vertex.
void Graph::quireV(){
    
    if(size != 0){
        bool existeInGraph = false;
        bool existeInNode = false;
        bool nonelinked = false;
        string searchNode;
        int foundnode = 0;
        
        do{
            list();
            
            cout<<"Here are all the objects contained in "<<this->name<<". Enter name of object: ";
            cin>>searchNode;
        
            for(int i = 0; i< things.size(); i++){
                if(searchNode == things[i].getname()){
                    foundnode = i;
                    if(things[i].numberof() == 0){
                        nonelinked = true;
                    }
                }
            }
            
        }while(!search(searchNode) || stop(searchNode));
        
        if(!nonelinked){
            if(!stop(searchNode)){
                do{
                    existeInGraph = false;
                    existeInNode = false;
                    nonelinked = false;
                    
                    things[foundnode].print();
                    
                    cout<<"Here are all the objects contained in "<<things[foundnode].getname()<<". Select the name of a object or enter \"stop\" to stop task: ";
                    cin>>searchNode;
                
                    for(int i = 0; i<size; i++){
                        if(searchNode == things[i].getname()){
                            existeInGraph = true;
                        
                            for(int j=0; j < things[foundnode].numberof(); j++){
                                if(searchNode == things[foundnode][j]){
                                    foundnode = i;
                                    if(things[i].numberof() == 0){
                                        nonelinked = true;
                                    }
                                    existeInNode = true;
                                }
                            }
                        }
                    }
                    if(!stop(searchNode)){
                        if(!existeInGraph){
                            cout<<"The object entered does not existed in the graph.\n";
                        }
                        if(!existeInNode){
                            cout<<"**The object entered was not linked to "<<things[foundnode].getname()<<"**\n";
                        }
                    }else{
                        nonelinked = true;
                    }
                }while(!nonelinked);
            }
            if(nonelinked && !stop(searchNode)){
                things[foundnode].print();
                cout<<"**end of path** \n";
            }
        }else{
            things[foundnode].print();
            cout<<"**end of path** \n";
        }
    }else{
        cout<<"There are no objects in "<<name<<"!\n";
    }
}

//function that serches for a possible link between two nodes
//If exist, prints out all the possible links between second and other node possible for user to select that node and print all its links possible to select a linked node... so forth
//Function - A graph can be queried by given an edge, if this edge exists in the graph
void Graph::quireE(){
    
    if(size != 0){
        bool error = false;
        bool existeInGraph = false;
        bool existeInNode = false;
        bool nonelinked = false;
        bool onelinkedtotwo = false;
        bool twolinkedtoone = false;
        string searchnew;
        string search1;
        string search2;
        string direction;
        int found1 = 0;
        int found2 = 0;
        int foundnode = 0;
        
        //look if both nodes are contained in the graph
        do{
            list();
        
            cout<<"Here are all the objects contained in "<<this->name<<". Enter name of first object: ";
            cin>>search1;
            
            for(int i = 0; i< things.size(); i++){
                if(search1 == things[i].getname()){
                    found1 = i;
                }
            }
            
            cout<<"Enter name of second object: ";
            cin>>search2;
            
            for(int i = 0; i< things.size(); i++){
                if(search2 == things[i].getname()){
                    found2 = i;
                }
            }
            
            if(!search(search1)){
                cout<<"**The first object entered is not present in the Graph**\n";
            }
            if(!search(search2)){
                cout<<"**The second object entered is not present in the Graph**\n";
            }
        }while(!search(search1) || !search(search2));
        
        //find which node is linked to which node
        for(int i=0; i<things[found1].numberof(); i++){
            if(things[found2].getname() == things[found1][i]){
                twolinkedtoone = true;
            }
        }
        for(int i=0; i<things[found2].numberof(); i++){
            if(things[found1].getname() == things[found2][i]){
                onelinkedtotwo = true;
            }
        }
    
        //identifying the diretion for the quire to follow
        if(twolinkedtoone && !onelinkedtotwo){
            cout<<things[found1].getname()<<" is only linked to "<<things[found2].getname()<<", thus this will be the direction of the edge\n";
            foundnode = found2;
        }
        if(!twolinkedtoone && onelinkedtotwo){
            cout<<things[found2].getname()<<" is only linked to "<<things[found1].getname()<<", thus this will be the direction of the edge\n";
            foundnode = found1;
        }
        
        
        if(twolinkedtoone && onelinkedtotwo){
            cout<<things[found1].getname()<<" & "<<things[found2].getname()<<" are linked to each other\n";
            do{
                cout<<"Enter \"one\" to direct the quire "<<things[found1].getname()<<" -> "<<things[found2].getname()<<" or \"two\" to direct it "<<things[found2].getname()<<" -> "<<things[found1].getname()<<" :";
                cin>>direction;
                direction = notcap(direction);
                if(direction == "one"){
                    error = false;
                    foundnode = found2;
                }
                if(direction == "two"){
                    error = false;
                    foundnode = found1;
                }
                if(direction != "two" && direction != "one"){
                    cout<<"***Invalide command***\n";
                    error = true;
                }
            }while(error);
        }
        
        if(!twolinkedtoone && !onelinkedtotwo){
            cout<<"This edge is not pesent in "<<name<<", sorry"<<endl;
        }else{
            do{
                existeInGraph = false;
                existeInNode = false;
                nonelinked = false;
            
                things[foundnode].print();
            
                if(things[foundnode].numberof() == 0){
                    cout<<"**end of path** \n";
                    nonelinked = true;
                    searchnew = "stop";
                }else{
                
                    cout<<"Here are all the objects contained in "<<things[foundnode].getname()<<". Select the name of a object or enter \"stop\" to stop task: ";
                    cin>>searchnew;
            
                    for(int i = 0; i<size; i++){
                        if(searchnew == things[i].getname()){
                            existeInGraph = true;
                    
                            for(int j=0; j < things[foundnode].numberof(); j++){
                                if(searchnew == things[foundnode][j]){
                                    foundnode = i;
                                    if(things[i].numberof() == 0){
                                        nonelinked = true;
                                    }
                                    existeInNode = true;
                                }
                            }
                        }
                    }
                    if(!stop(searchnew)){
                        if(!existeInGraph){
                            cout<<"The object entered does not existed in the graph.\n";
                        }
                        if(!existeInNode){
                            cout<<"**The object entered was not linked to "<<things[foundnode].getname()<<"**\n";
                        }
                    }else{
                        nonelinked = true;
                    }
                }
            }while(!nonelinked);
            if(nonelinked && !stop(searchnew)){
                things[foundnode].print();
                cout<<"**end of path** \n";
            }
        }
    }else{
        cout<<"There are no objects in "<<name<<"!\n";
    }
}


void Graph::search(){
    if(size != 0){
        string searching = "N/A";
        bool found = false;
        cout<<"Please enter the desired value of the object to search: ";
        cin>>searching;
        for(int i = 0; i< things.size(); i++){
            if(searching == things[i].getname()){
                found = true;
            }
        }
        if(found){
            cout<<searching<<" is contained in "<<name<<endl;
        }else{
            cout<<searching<<" is NOT contained in "<<name<<endl;
        }
    }else{
        cout<<"There are no objects in "<<name<<"!\n";
    }
}

void Graph::searchedge(){
    
    if(size != 0){
        bool onelinkedtotwo = false;
        bool twolinkedtoone = false;
        string searchnew;
        string search1;
        string search2;
        string direction;
        int found1 = 0;
        int found2 = 0;
        int foundnode = 0;
    
        do{
            list();
            
            cout<<"Here are all the objects contained in "<<this->name<<". Enter name of first object: ";
            cin>>search1;
            
            for(int i = 0; i< things.size(); i++){
                if(search1 == things[i].getname()){
                    found1 = i;
                }
            }
        
            cout<<"Enter name of seconde object: ";
            cin>>search2;
            
            for(int i = 0; i< things.size(); i++){
                if(search2 == things[i].getname()){
                    found2 = i;
                }
            }
            
            if(!search(search1)){
            cout<<"**The first object entered is not present in the Graph**\n";
            }
            if(!search(search2)){
                cout<<"**The second object entered is not present in the Graph**\n";
            }
        }while(!search(search1) || !search(search2));
        
        //find which node is linked to which node
        for(int i=0; i<things[found1].numberof(); i++){
            if(things[found2].getname() == things[found1][i]){
                twolinkedtoone = true;
            }
        }
        for(int i=0; i<things[found2].numberof(); i++){
            if(things[found1].getname() == things[found2][i]){
                onelinkedtotwo = true;
            }
        }
    
        //identifying the diretion for the quire to follow
        if(twolinkedtoone && !onelinkedtotwo){
            cout<<things[found1].getname()<<" -> "<<things[found2].getname()<<", is an edge in "<<name<<endl;
            foundnode = found2;
        }
        if(!twolinkedtoone && onelinkedtotwo){
            cout<<things[found2].getname()<<" -> "<<things[found1].getname()<<", is an edge in "<<name<<endl;
            foundnode = found1;
        }
    
    
        if(twolinkedtoone && onelinkedtotwo){
            cout<<things[found1].getname()<<" & "<<things[found2].getname()<<" are linked both ways \n";
        }
    
        if(!twolinkedtoone && !onelinkedtotwo){
            cout<<things[found1].getname()<<" & "<<things[found2].getname()<<" are NOT linked \n";
        }
    }else{
        cout<<"There are no objects in "<<name<<"!\n";
    }
}

//Destructor
Graph::~Graph(){
    
}
