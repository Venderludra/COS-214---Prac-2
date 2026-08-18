#ifndef REGION_H
#define REGION_H
#include "Place.h"
#include <vector>

class Region : public Place{
    private:
        std::vector<Place*> childrens;
    public:
        ~Region();
        void add(Place*);
        void remove(Place*);
        void display() override;
};

#endif