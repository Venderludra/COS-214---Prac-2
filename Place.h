#ifndef PLACE_H
#define PLACE_H
#include <string>

class Place{
    protected:
        std::string name; //location name

    public:
        std::string getName();
        virtual ~Place();
        virtual void display() = 0;
};

#endif