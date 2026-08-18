#include "AquaticObstacle.h"
#include <iostream>
using namespace std;

AquaticObstacle::AquaticObstacle() : Obstacle("Aquatic","Labrinth of tidal waves"){

}

void AquaticObstacle::block(){
    cout << "A great Tidal waves has appeared and blocked your ways along with a shiver of sharks" << endl;
}