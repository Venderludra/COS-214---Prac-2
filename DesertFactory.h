#ifndef DESERTFACTORY_H
#define DESERTFACTORY_H
#include "BiomeFactory.h"

class DesertFactory : public BiomeFactory{
    public:
        Terrain* createTerrain() override;
        NPC* createNPC() override;
        Obstacle* createObstacle() override;
};

#endif