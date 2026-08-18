#ifndef AQUATICNPC_H
#define AQUATICNPC_H
#include "NPC.h"

class AquaticNPC : public NPC{
    public:
        AquaticNPC();
        void interact() override;
};

#endif