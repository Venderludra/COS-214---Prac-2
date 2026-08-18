#include "InfernoFactory.h"
#include "InfernoNPC.h"
#include "InfernoObstacle.h"
#include "InfernoTerrain.h"
#include <iostream>
using namespace std;

Terrain* InfernoFactory::createTerrain(){
    return new InfernoTerrain();
}

NPC* InfernoFactory::createNPC(){
    return new InfernoNPC();
}

Obstacle* InfernoFactory::createObstacle(){
    return new InfernoObstacle();
}

