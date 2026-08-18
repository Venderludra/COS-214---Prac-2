#include "AquaticNPC.h"
#include <iostream>
using namespace std;

AquaticNPC::AquaticNPC() : NPC("Aquatic"){
}

void AquaticNPC::interact(){
    cout << "Type : " << type << endl;
    cout << "NPC gave you map to the Dungeon of tidal waves"<< endl;
    cout << "NPC gave you potion for water breathing "<<endl;
    cout << "NPC gave you a scroll water magic"<<endl;
}
