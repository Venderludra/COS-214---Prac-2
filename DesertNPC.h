#ifndef DESERTNPC_H
#define DESERTNPC_H
#include "NPC.h"

class DesertNPC : public NPC{
    public:
        DesertNPC();
        void interact() override;
};

#endif