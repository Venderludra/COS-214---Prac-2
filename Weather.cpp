#include "Weather.h"
#include <iostream>
using namespace std;

Weather::Weather(Place* place) : PlaceDecorator(place){

}

void Weather::display(){
    wrapped->display();
    cout << "Weather: Heavy rain" << endl;
}