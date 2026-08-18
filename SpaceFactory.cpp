#include "SpaceFactory.h"
#include "SpaceNPC.h"
#include "SpaceObstacle.h"
#include "SpaceTerrain.h"
#include <iostream>
using namespace std;

Terrain* SpaceFactory::createTerrain(){
    return new SpaceTerrain();
}

NPC* SpaceFactory::createNPC(){
    return new SpaceNPC();
}

Obstacle* SpaceFactory::createObstacle(){
    return new SpaceObstacle();
}
