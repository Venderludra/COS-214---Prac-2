#ifndef NPC_H
#define NPC_H
#include <string>

class NPC {
    protected:
        std::string type;
    public:
        NPC(std::string);
        virtual ~NPC();
        virtual void interact() =0;
};

#endif