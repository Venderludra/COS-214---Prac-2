#include "Location.h"
#include <iostream>
using namespace std;

Location::Location(string descr) : description(descr){
}

void Location::display(){
    cout << "Name of location: " << Place::getName() <<endl;
    cout << "Location Description: " << description << endl;
}