#ifndef SPACEOBSTACLE_H
#define SPACEOBSTACLE_H
#include "Obstacle.h"

class SpaceObstacle : public Obstacle{
    public:
        SpaceObstacle();
        void block() override;
};

#endif