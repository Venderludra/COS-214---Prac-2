#include "ForestNPC.h"
#include <iostream>
using namespace std;

ForestNPC::ForestNPC() : NPC("Forest"){
}

void ForestNPC::interact(){
    cout << "Type : " << type << endl;
    cout << "NPC gave you map to the Dungeon of Snow"<< endl;
    cout << "NPC gave you map to the canyone where an ancient sowrd is sealed"<<endl;
}

