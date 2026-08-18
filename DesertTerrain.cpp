#include "DesertTerrain.h"
#include <iostream>
using namespace std;

DesertTerrain::DesertTerrain() : Terrain("Desert"){
}

void DesertTerrain::describe(){
    cout << "You are travelling across a hot, dry desert with large sand dunes." << endl;
}