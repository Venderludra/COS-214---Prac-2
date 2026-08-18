#ifndef FORESTNPC_H
#define FORESTNPC_H
#include "NPC.h"

class ForestNPC : public NPC{
    public:
        ForestNPC();
        void interact() override;
};

#endif