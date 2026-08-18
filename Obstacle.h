#ifndef OBSTACLE_H
#define OBSTACLE_H
#include <string>

class Obstacle{
    protected:
        std::string type;
        std::string labyrinthType;
    
    public:
        Obstacle(std::string,std::string);
        virtual ~Obstacle() ;
        virtual void block() =0;
};


#endif