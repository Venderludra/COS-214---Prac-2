#include "Toll.h"
#include <iostream>
using namespace std;

Toll::Toll(Place* place) : PlaceDecorator(place){

}

void Toll::display(){
    wrapped->display();
    cout << "Toll: 100" << endl;
}