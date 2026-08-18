#ifndef FORESTFACTORY_H
#define FORESTFACTORY_H
#include "BiomeFactory.h"

class ForestFactory : public BiomeFactory{
    public:
        Terrain* createTerrain() override;
        NPC* createNPC() override;
        Obstacle* createObstacle() override;
};

#endif