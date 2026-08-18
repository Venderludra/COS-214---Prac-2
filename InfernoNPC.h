#ifndef INFERNONPC_H
#define INFERNONPC_H
#include "NPC.h"

class InfernoNPC : public NPC{
    public:
        InfernoNPC();
        void interact() override;
};

#endif