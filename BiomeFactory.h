#ifndef BIOMEFACTORY_H
#define BIOMEFACTORY_H
#include "NPC.h"
#include "Terrain.h"
#include "Obstacle.h"

class BiomeFactory{
    public:
        virtual ~BiomeFactory();
        virtual Terrain* createTerrain() = 0;
        virtual NPC* createNPC() = 0;
        virtual Obstacle* createObstacle() = 0;
};

#endif