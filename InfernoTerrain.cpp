#include "InfernoTerrain.h"
#include <iostream>
using namespace std;

InfernoTerrain::InfernoTerrain() : Terrain("Inferno"){
}

void InfernoTerrain::describe(){
    cout << "You are tavelling across a realm of immense heat and all you can see it fire and lava" << endl;
}