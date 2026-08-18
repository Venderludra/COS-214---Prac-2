#include "AquaticFactory.h"
#include "AquaticNPC.h"
#include "AquaticObstacle.h"
#include "AquaticTerrain.h"
#include <iostream>
using namespace std;

Terrain* AquaticFactory::createTerrain(){
    return new AquaticTerrain();
}

NPC* AquaticFactory::createNPC(){
    return new AquaticNPC();
}

Obstacle* AquaticFactory::createObstacle(){
    return new AquaticObstacle();
}
