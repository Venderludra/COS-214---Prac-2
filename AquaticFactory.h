#ifndef AQUATICFACTORY_H
#define AQUATICFACTORY_H
#include "BiomeFactory.h"

class AquaticFactory : public BiomeFactory{
    public:
        Terrain* createTerrain() override;
        NPC* createNPC() override;
        Obstacle* createObstacle() override;
};

#endif