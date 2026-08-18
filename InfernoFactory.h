#ifndef INFERNOFACTORY_H
#define INFERNOFACTORY_H
#include "BiomeFactory.h"

class InfernoFactory : public BiomeFactory{
    public:
        Terrain* createTerrain() override;
        NPC* createNPC() override;
        Obstacle* createObstacle() override;
};

#endif