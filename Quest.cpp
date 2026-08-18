#include "Quest.h"
#include <iostream>
using namespace std;

Quest::Quest(Place* place) : PlaceDecorator(place){

}

void Quest::display(){
    wrapped->display();
    cout << "Quest: Find the Holy grail" << endl;
}