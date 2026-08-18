#ifndef LOCATION_H
#define LOCATION_H
#include "Place.h"

class Location : public Place{
    private:
        std::string description;

    public:
        Location(std::string);
        void display() override;

};

#endif