//main.cpp


#include <stdio.h>
#include "Direct.h"
#include "Undirected.h"
#include <iostream>
#include "string.h"
using namespace std;


//different functions
void help();
bool end(string);
string notcap(string);

int main(){
    
    char*  goodname = NULL;
    string command = "N/A";
    string kindofGraph = "N/A";
    string name = "N/A";
    bool wrongans = false;
    bool goodans;
    bool correct =true;
    
    cout<<"*---------------------------------------------------------------------------------*\n";
    cout<<"Welcome to the Graph Generator!" << endl;
    cout<<"If you ever need aid working the program, type \"Help\" for extra information!\n";
    cout<<"If you ever want to stop the program, type \"End\"." <<endl;
    cout<<"*---------------------------------------------------------------------------------*\n";
    
    do{
        cout<<"Would you like to create a directed or undirected graph (d/u): ";
        cin>>kindofGraph;
        
        kindofGraph = notcap(kindofGraph);
        
        if (kindofGraph != "d" && kindofGraph != "u"){
            wrongans = true;
        }
        
        if(kindofGraph == "d"){
            wrongans = false;
            cout<<"What is the name of your graph: ";
            cin>>name;
            goodname = new char[name.length()+1];
            for(int i=0; i < (name.length()+1); i++){
                goodname[i]=name[i];
            }
            
            Direct graph(goodname);
            
            while(correct){
                cout<<"Would you like to add nodes to "<<name<<" (y/n): ";
                cin>>command;
                command=notcap(command);
                if(command == "y"){
                    graph.add();
                    correct = false;
                }
                if(command == "n"){
                    correct = false;
                    cout<<"Fine. The graph "<<name<<" is empty\n";
                }
            }
            
            help();
            
            do{
                goodans=true;
                cout<<"Enter your command: ";
                cin>>command;
                
                command = notcap(command);
                
                if(command == "help"){
                    goodans=false;
                    help();
                }
                if(command == "add"){
                    goodans=false;
                    graph.add();
                }
                if(command == "list"){
                    goodans=false;
                    graph.list();
                }
                if(command == "link"){
                    goodans=false;
                    graph.point();
                }
                if(command == "vertexpath"){
                    goodans=false;
                    graph.quireV();
                }
                if(command == "edgepath"){
                    goodans=false;
                    graph.quireE();
                }
                if(command == "searchvertex"){
                    goodans=false;
                    graph.search();
                }
                if(command == "searchedge"){
                    goodans=false;
                    graph.searchedge();
                }
                if(end(command)){
                    goodans=false;
                    cout<<"*---------------------------------------------------------------------------------*\n";
                    cout<<"Thank you for using the Graph Generator!" << endl;
                    cout<<"*---------------------------------------------------------------------------------*\n";
                }
                if(goodans){
                    cout<<"**Invalide command** type \"Help\" to list different options\n";
                }
            }while(!end(command));
        }
        
        if(kindofGraph == "u"){
            wrongans = false;
            cout<<"What is the name of your graph: ";
            cin>>name;
            
            goodname = new char[name.length()+1];
            for(int i=0; i < (name.length()+1); i++){
                goodname[i]=name[i];
            }
            
            Undirected graph(goodname);
            
            while(correct){
                cout<<"Would you like to add nodes to "<<name<<" (y/n): ";
                cin>>command;
                command=notcap(command);
                if(command == "y"){
                    graph.add();
                    correct = false;
                }
                if(command == "n"){
                    correct = false;
                    cout<<"Fine. The graph "<<name<<" is empty\n";
                }
            }
            
            help();
            
            do{
                goodans=true;
                
                cout<<"Enter you command: ";
                cin>>command;
                
                command = notcap(command);
                
                if(command == "help"){
                    goodans=false;
                    help();
                }
                if(command == "add"){
                    goodans=false;
                    graph.add();
                }
                if(command == "list"){
                    goodans=false;
                    graph.list();
                }
                if(command == "link"){
                    goodans=false;
                    graph.point();
                }
                if(command == "vertexpath"){
                    goodans=false;
                    graph.quireV();
                }
                if(command == "edgepath"){
                    goodans=false;
                    graph.quireE();
                }
                if(command == "searchvertex"){
                    goodans=false;
                    graph.search();
                }
                if(command == "searchedge"){
                    goodans=false;
                    graph.searchedge();
                }
                if(end(command)){
                    goodans=false;
                    cout<<"*---------------------------------------------------------------------------------*\n";
                    cout<<"Thank you for using the Graph Generator!" << endl;
                    cout<<"*---------------------------------------------------------------------------------*\n";
                }
                if(goodans){
                    cout<<"**Invalide command** Type \"Help\" to list diffrent options\n";
                }
            }while(!end(command));
        }
    }while(wrongans);
}

//function to bring a sting to a standardised no capitalse
string notcap(string word){
    for(int i = 0; i<word.length(); i++){
        if(word[i]>=65 && word[i]<=92){
            word[i]=word[i]+32;
        }
    }
    return word;
}

//function to look if stinsg is equal to the word end
bool end(string n){
    bool end = false;
    n = notcap(n);
    if(n == "end"){
        end = true;
    }
    return end;
}

//function that returns all the options
void help(){
    cout<<"*---------------------------------------------------------------------------------*\n";
    cout<<"Commands: \n";
    cout<<"Type \"Add\" to add objects to the graph.\n";
    cout<<"Type \"List\" to list all the object and there links.\n";
    cout<<"Type \"Link\" to link the object to each other in the graph.\n";
    cout<<"Type \"VertexPath\" to list the path a vertex leads.\n";
    cout<<"Type \"EdgePath\" to search if an edge exists in the graph and list the paths.\n";
    cout<<"Type \"SearchVertex\" to search if an object is present in the graph.\n";
    cout<<"Type \"SearchEdge\" to search if an edge is present in the graph.\n";
    cout<<"Type \"End\" if you are done using the Graph Generator. \n";
    cout<<"*---------------------------------------------------------------------------------*\n";
}

