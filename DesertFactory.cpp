#include "DesertFactory.h"
#include "DesertNPC.h"
#include "DesertObstacle.h"
#include "DesertTerrain.h"
#include <iostream>
using namespace std;

Terrain* DesertFactory::createTerrain(){
    return new DesertTerrain();
}

NPC* DesertFactory::createNPC(){
    return new DesertNPC();
}

Obstacle* DesertFactory::createObstacle(){
    return new DesertObstacle();
}
