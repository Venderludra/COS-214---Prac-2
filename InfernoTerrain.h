#ifndef INFERNOTERRAIN_H
#define INFERNOTERRAIN_H
#include "Terrain.h"

class InfernoTerrain : public Terrain{
    public:
        InfernoTerrain();
        void describe() override;
};

#endif