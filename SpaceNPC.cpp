#include "SpaceNPC.h"
#include <iostream>
using namespace std;

SpaceNPC::SpaceNPC() : NPC("Space"){
}

void SpaceNPC::interact(){
    cout << "Type : " << type << endl;
    cout << "NPC gave you map to the Dungeon of Eternal darkness"<< endl;
    cout << "NPC gave you a space gun "<<endl;
}
