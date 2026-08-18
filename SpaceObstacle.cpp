#include "SpaceObstacle.h"
#include <iostream>
using namespace std;

SpaceObstacle::SpaceObstacle() : Obstacle("Space","Labrinth of darkness"){

}

void SpaceObstacle::block(){
    cout << "You stumble upon a blackhole with it's immense gravity holding you down" << endl;
}