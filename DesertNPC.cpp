#include "DesertNPC.h"
#include <iostream>
using namespace std;

DesertNPC::DesertNPC() : NPC("Desert"){
}

void DesertNPC::interact(){
    cout << "Type : " << type << endl;
    cout << "NPC gave you map to the Dungeon of the great sands forge"<< endl;
    cout << "NPC gave you map to Oasis to recover and get more supplies "<<endl;
}

