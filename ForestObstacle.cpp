#include "ForestObstacle.h"
#include <iostream>
using namespace std;

ForestObstacle::ForestObstacle() : Obstacle("Forest","Labrinth of ever green"){

}

void ForestObstacle::block(){
    cout << "A big tree blocks your path while a horde of wild beasts chase you down" << endl;
}