#ifndef INFERNOOBSTACLE_H
#define INFERNOOBSTACLE_H
#include "Obstacle.h"

class InfernoObstacle : public Obstacle{
    public:
        InfernoObstacle();
        void block() override;
};

#endif