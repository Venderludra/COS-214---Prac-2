#ifndef SPACEFACTORY_H
#define SPACEFACTORY_H
#include "BiomeFactory.h"

class SpaceFactory : public BiomeFactory{
    public:
        Terrain* createTerrain() override;
        NPC* createNPC() override;
        Obstacle* createObstacle() override;
};

#endif