#ifndef WORLD_H
#define WORLD_H
#include "Region.h"

class World{
    private:
        Region* root;

    public:
        World();
        Region* getRoot();
        void display();
        ~World();
};

#endif