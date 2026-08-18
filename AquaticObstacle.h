#ifndef AQUATICOBSTACLE_H
#define AQUATICOBSTACLE_H
#include "Obstacle.h"

class AquaticObstacle : public Obstacle{
    public:
        AquaticObstacle();
        void block() override;
};

#endif