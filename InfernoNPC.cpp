#include "InfernoNPC.h"
#include <iostream>
using namespace std;

InfernoNPC::InfernoNPC() : NPC("Inferno"){
}

void InfernoNPC::interact(){
    cout << "Type : " << type << endl;
    cout << "NPC gave you map to the Dungeon of tarturus"<< endl;
    cout << "NPC gave you potion of flame immunity"<<endl;
}
