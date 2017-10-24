//Undirected.cpp

#include "Undirected.h"
#include <iostream>
using namespace std;

//Default constructor
Undirected::Undirected() : Graph(){
}

//Constructor
Undirected::Undirected(string n) : Graph(n){
}

//Copy constructor
Undirected::Undirected(const Undirected& cool) : Graph(cool){
}

//Linking two nodes
void Undirected::point(){
    string n;
    Node * load = NULL;
    bool correct = true;
    bool go = false;
    bool found1 = false;
    bool found2 = false;
    bool copylink = false;
    int s1 =0;
    int s2 =0;
    int numnode1 =0;
    int numnode2 =0;
    string search1;
    string search2;
    do{
        list();
        do{
            copylink=false;
            do{
                found1 = false;
                cout<<"What is the name of the first desired object to link or enter \"stop\" to stop:";
                cin>>search1;
                
                if(!stop(search1)){
                    for(s1 = 0; s1<size; s1++){
                        if (search1 == things[s1].getname()){
                            found1 = true;
                            numnode1 = s1;
                        }
                    }
                    
                    if(found1 == false){
                        cout<<"The name of the object was not found in the graph\n";
                    }
                }else{
                    found1 = true;
                }
            }while(found1 == false);
            
            if(!stop(search1)){
                do{
                    found2 = false;
                    cout<<"What is the name of the second desired object to link with " << search1 << " or enter \"stop\" to stop: ";
                    cin>>search2;
                    
                    if(!stop(search2)){
                        s2 = 0;
                        for(; s2<size; s2++){
                            if (search2 == things[s2].getname()){
                                found2 = true;
                                numnode2 = s2;
                            }
                        }
                        if(found2 == false){
                            cout<<"The name of the object was not found in the graph\n";
                        }else{
                            s2=0;
                            for(; s2 < things[numnode1].numberof(); s2++){
                                if(things[numnode1][s2] == things[numnode2].getname()){
                                    copylink = true;
                                }
                            }
                            if(copylink == true){
                                cout<<things[numnode1].getname()<<" are alredy linked with "<<things[numnode2].getname()<< endl;
                            }
                        }
                    }else{
                        found2=true;
                    }
                }while(found2 == false);
            }
        }while(copylink == true);
        
        if(!stop(search2) && !stop(search1)){
            
            load = &things[numnode1];
            things[numnode2].point(load);
            load = &things[numnode2];
            things[numnode1].point(load);
            
            
            do{
                cout<<"Would you like to link other objects (y/n): ";
                cin>>n;
                if(n != "y" && n!="n"){
                    cout<<"Invalid input! Please try again. " << endl;
                    correct = true;
                }else{
                    correct = false;
                }
            }while(correct);
            if(n== "y"){
                go=true;
            }
            if(n=="n"){
                go=false;
            }
        }
    }while(go && !stop(search1) && !stop(search2));
}

//Destructor
Undirected::~Undirected(){
    delete [] name;
}
