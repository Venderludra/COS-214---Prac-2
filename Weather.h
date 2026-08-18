#ifndef WEATHER_H
#define WEATHER_H
#include "PlaceDecorator.h"

class Weather : public PlaceDecorator{
    public:
        Weather(Place*);
        void display() override;
};

#endif