#ifndef QUEST_H
#define QUEST_H
#include "PlaceDecorator.h"

class Quest : public PlaceDecorator{
    public:
        Quest(Place*);
        void display() override;
};

#endif