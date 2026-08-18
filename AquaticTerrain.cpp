#include "AquaticTerrain.h"
#include <iostream>
using namespace std;

AquaticTerrain::AquaticTerrain() : Terrain("Aquatic"){
}

void AquaticTerrain::describe(){
    cout << "You are tavelling across a realm of submerged in endless water and beatiful marine life" << endl;
}