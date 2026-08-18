#include "ForestTerrain.h"
#include <iostream>
using namespace std;

ForestTerrain::ForestTerrain() : Terrain("Forest"){
}

void ForestTerrain::describe(){
    cout << "You are tavelling across a dense and packed forest of trees and wildlife" << endl;
}