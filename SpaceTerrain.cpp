#include "SpaceTerrain.h"
#include <iostream>
using namespace std;

SpaceTerrain::SpaceTerrain() : Terrain("Space"){
}

void SpaceTerrain::describe(){
    cout << "You are travelling across a void shrouded by darkness, the only thing you see and hear are your panicked breath and heartbeat." << endl;
}