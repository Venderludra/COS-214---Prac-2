#ifndef TOLL_H
#define TOLL_H
#include "PlaceDecorator.h"

class Toll : public PlaceDecorator{
    public:
        Toll(Place*);
        void display() override;
};

#endif