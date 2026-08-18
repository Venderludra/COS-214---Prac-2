#ifndef SPACETERRAIN_H
#define SPACETERRAIN_H
#include "Terrain.h"

class SpaceTerrain : public Terrain{
    public:
        SpaceTerrain();
        void describe() override;
};

#endif