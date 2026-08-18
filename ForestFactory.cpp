#include "ForestFactory.h"
#include "ForestNPC.h"
#include "ForestObstacle.h"
#include "ForestTerrain.h"
#include <iostream>
using namespace std;

Terrain* ForestFactory::createTerrain(){
    return new ForestTerrain();
}

NPC* ForestFactory::createNPC(){
    return new ForestNPC();
}

Obstacle* ForestFactory::createObstacle(){
    return new ForestObstacle();
}
