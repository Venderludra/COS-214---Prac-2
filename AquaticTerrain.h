#ifndef AQUATICTERRAIN_H
#define AQUATICTERRAIN_H
#include "Terrain.h"

class AquaticTerrain : public Terrain{
    public:
        AquaticTerrain();
        void describe() override;
};

#endif