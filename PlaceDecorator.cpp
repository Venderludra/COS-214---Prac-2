#include "PlaceDecorator.h"

PlaceDecorator::PlaceDecorator(Place* place){
    wrapped = place;
}

void PlaceDecorator::display(){
    wrapped->display();
}

PlaceDecorator::~PlaceDecorator(){
    delete wrapped;
}