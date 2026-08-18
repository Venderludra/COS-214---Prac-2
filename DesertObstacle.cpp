#include "DesertObstacle.h"
#include <iostream>
using namespace std;

DesertObstacle::DesertObstacle() : Obstacle("Desert","Labrinth of Sand Forges"){

}

void DesertObstacle::block(){
    cout << "A great sand Storm blocks your path along with your vision" << endl;
}