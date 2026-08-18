#ifndef TERRAIN_H
#define TERRAIN_H
#include <string>

class Terrain {
    protected:
        std::string type;
    public:
        Terrain(std::string);
        virtual ~Terrain();
        virtual void describe() = 0;
};

#endif