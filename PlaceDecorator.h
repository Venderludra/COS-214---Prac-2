#ifndef PLACEDECORATOR_H
#define PLACEDECORATOR_H
#include "Place.h"

class PlaceDecorator : public Place{
    protected:
        Place* wrapped;
    
    public:
        PlaceDecorator(Place*);
        void display() override;
        virtual ~PlaceDecorator();
};

#endif