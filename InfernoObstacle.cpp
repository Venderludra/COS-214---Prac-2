#include "InfernoObstacle.h"
#include <iostream>
using namespace std;

InfernoObstacle::InfernoObstacle() : Obstacle("Inferno","Labrinth of HellFire"){

}

void InfernoObstacle::block(){
    cout << "A great heat waves and an army of fire giants block you path." << endl;
}