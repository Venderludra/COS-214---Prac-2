#include "Region.h"
#include <iostream>
using namespace std;

Region::~Region(){
    for(auto children : childrens){
        delete children;
    }
}

void Region::add(Place* place){
    childrens.push_back(place);
}

void Region::remove(Place* place){
    for(auto it = childrens.begin() ; it != childrens.end(); it++){
        if(*it == place){
            delete *it;
            childrens.erase(it);
            return;
        }
    }
}

void Region::display(){
    cout << "Region: " << this->getName() <<endl;
    for(Place* place : childrens){
        place->display();
    }
}