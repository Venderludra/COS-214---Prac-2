#ifndef FORESTOBSTACLE_H
#define FORESTOBSTACLE_H
#include "Obstacle.h"

class ForestObstacle : public Obstacle{
    public:
        ForestObstacle();
        void block() override;
};

#endif