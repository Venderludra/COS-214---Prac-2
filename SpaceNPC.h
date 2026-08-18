#ifndef SPACENPC_H
#define SPACENPC_H
#include "NPC.h"

class SpaceNPC : public NPC{
    public:
        SpaceNPC();
        void interact() override;
};

#endif