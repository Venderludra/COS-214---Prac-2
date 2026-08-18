#include "World.h"
#include <iostream>
using namespace std;

World::World(){
    root = new Region("World");
}

Region* World::getRoot(){
    return root;
}

void World::display(){
    root->display();
}

World::~World(){
    delete root;
}