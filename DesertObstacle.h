#ifndef DESERTOBSTACLE_H
#define DESERTOBSTACLE_H
#include "Obstacle.h"

class DesertObstacle : public Obstacle{
    public:
        DesertObstacle();
        void block() override;
};

#endif