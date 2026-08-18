#include <iostream>
#include <memory>
#include "TravelMode.h"
#include "RouteStrategy.h"
#include "BiomeFactory.h"
#include "DesertFactory.h"
#include "AquaticFactory.h"
#include "ForestFactory.h"
#include "InfernoFactory.h"
#include "SpaceFactory.h"
#include "World.h"
#include "Place.h"
#include "Region.h"
#include "PlaceDecorator.h"
#include "Quest.h"
#include "Toll.h"

using namespace std;

int main() {
    cout << " This is the 2nd COS214 prac...less gerrit\n";
    cout << endl;

    int choice = 0;
    while (choice != 9) {
        cout << "\n--- MAIN MENU ---" << endl;
        cout << "1. Movement (State Pattern)" << endl;
        cout << "2. Routes (Strategy Pattern)" << endl;
        cout << "3. Map (Composite Pattern)" << endl;
        cout << "4. Place Features (Decorator Pattern)" << endl;
        cout << "5. Biomes (Abstract Factory)" << endl;
        cout << "9. Quit Game" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            //the State pattern lets us change how the Traveller behaves based on what mode of transport they're in. We start walking, then we can switch to bicycle, car, or flying, but only if we have the right items (bike, keys, ticket). The guards make sure we can't do impossible transitions.
            cout << "\n1: the state pattern (aka movement)\n";
            Traveller traveller("Alice");
            
            //at the start we're walking - no items needed to be in this mode
            traveller.move();
            
            //we find a bicycle, so now the guard lets us switch to bicycle mode. The move() method now behaves differently because we're in a different state.
            traveller.findBicycle();
            traveller.switchMode("Bicycle");
            traveller.move();
            
            //we pick up car keys, which allows us to switch to car mode. Again, the behaviour changes because the state changed.
            traveller.findCarKeys();
            traveller.switchMode("Car");
            traveller.move();
            
            //show which modes we can actually switch to right now based on what the current state allows
            traveller.listAvailableModes();
            cout << endl;

        } else if (choice == 2) {
            //the Strategy pattern is different from State because routes are just different algorithms we can choose from. We're not forced to go through transitions or meet guards. We can pick shortest, fastest, scenic, or cheapest route anytime we want, even mid-trip. The Trip object stays the same - we're just swapping out the calculation method.
            cout << "\n2: the strategy pattern (aka the routes)\n";
            Trip trip("London", "Paris");
            
            //the default strategy is shortest path - it calculates the route by minimizing distance
            trip.planRoute();
            
            //we can instantly swap to fastest path strategy without any guards or conditions - just pick a different algorithm
            trip.setStrategy(new FastestPath());
            trip.planRoute();
            
            //swap again to scenic path - still no guards, just swap the algorithm and go
            trip.setStrategy(new ScenicPath());
            trip.planRoute();
            
            //swap one more time to cheapest path - this is why Strategy is so flexible, you can change anytime
            trip.setStrategy(new CheapestPath());
            trip.planRoute();
            cout << endl;

        } else if (choice == 3) {
            //Composite lets us build a tree where Regions are branches that hold things inside them, and Locations are the leaves at the end. The cool part is that both use the same interface, so the client code doesn't care if it's dealing with a leaf or a branch - it just calls display() and the tree recursively displays everything.
            cout << "\n3: the composite (aka the map)\n" ;
            World world;
            
            //create some intermediate nodes - these are Regions that will hold other places inside them
            Region* europe = new Region("Europe");
            Region* africa = new Region("Africa");
            
            //create the leaf nodes - these are specific locations that don't contain anything else
            Place* london = new Region("London");
            Place* paris = new Region("Paris");
            Place* cairo = new Region("Cairo");
            Place* capetown = new Region("Cape Town");
            
            //build the tree structure by having Regions own their children - this creates the part-whole hierarchy
            europe->add(london);
            europe->add(paris);
            africa->add(cairo);
            africa->add(capetown);
            
            //add the regions to the world root to create a multi-level hierarchy
            world.getRoot()->add(europe);
            world.getRoot()->add(africa);
            
            //display the entire tree - the same display() method works for all levels because they all inherit from Place
            world.display();
            cout << endl;
            //the World destructor cleans up the map automatically.

        } else if (choice == 4) {
            //Decorator is how we add features to places without creating a million subclasses. Instead of making LocationWithWeatherAndToll and LocationWithWeatherAndTollAndQuest classes, we just wrap the location with decorators. Each decorator adds one feature and wraps the previous object, building a chain.
            cout << "\n4: the decorator (aka the place Features)\n";
            
            //start with a basic location that has no special features
            Place* location = new Region("Tavern");
            cout << "Basic location:\n";
            location->display();
            
            //wrap it with a Quest decorator - now when we call display(), it displays the tavern info AND the quest
            cout << "\nDecorated with Quest:\n";
            location = new Quest(location);
            location->display();
            
            //wrap it again with a Toll decorator - now we have a chain of Quest wrapping the tavern, then Toll wrapping Quest, so display calls get passed down and each decorator adds its info
            cout << "\nDecorated with Toll:\n";
            location = new Toll(location);
            location->display();
            cout << endl;

            //delete the decorator chain (outermost deletes the innermost automatically)
            delete location; 

        } else if (choice == 5) {
            //abstract Factory ensures that when we create content for a biome, we get a complete matching set. A Desert factory will only produce desert things, never mix desert terrain with ocean NPCs. Each factory creates all three product types together to guarantee coherence.
            cout << "\n5: the abstract factory (aka the biomes)\n" << endl;
            
            //desert factory creates a complete desert family - desert terrain, desert NPC, desert obstacle all matching each other
            cout << "Desert Biome Content:\n" ;
            BiomeFactory* desertFactory = new DesertFactory();
            Terrain* desertTerrain = desertFactory->createTerrain();
            NPC* desertNPC = desertFactory->createNPC();
            Obstacle* desertObstacle = desertFactory->createObstacle();
            
            desertTerrain->describe();
            desertNPC->interact();
            desertObstacle->block();
            cout << endl;
            
            //aquatic factory creates a complete aquatic family - all water-themed content that belongs together
            cout << "Aquatic Biome Content:\n";
            BiomeFactory* aquaticFactory = new AquaticFactory();
            Terrain* aquaticTerrain = aquaticFactory->createTerrain();
            NPC* aquaticNPC = aquaticFactory->createNPC();
            Obstacle* aquaticObstacle = aquaticFactory->createObstacle();
            
            aquaticTerrain->describe();
            aquaticNPC->interact();
            aquaticObstacle->block();
            cout << endl;
            
            //forest factory creates a complete forest family - trees, forest creatures, forest obstacles
            cout << "Forest Biome Content:\n";
            BiomeFactory* forestFactory = new ForestFactory();
            Terrain* forestTerrain = forestFactory->createTerrain();
            NPC* forestNPC = forestFactory->createNPC();
            Obstacle* forestObstacle = forestFactory->createObstacle();
            
            forestTerrain->describe();
            forestNPC->interact();
            forestObstacle->block();
            cout << endl;
            
            //inferno factory creates a complete fire-themed family - lava terrain, fire creatures, flame obstacles
            cout << "Inferno Biome Content:\n";
            BiomeFactory* infernoFactory = new InfernoFactory();
            Terrain* infernoTerrain = infernoFactory->createTerrain();
            NPC* infernoNPC = infernoFactory->createNPC();
            Obstacle* infernoObstacle = infernoFactory->createObstacle();
            
            infernoTerrain->describe();
            infernoNPC->interact();
            infernoObstacle->block();
            cout << endl;
            
            //space factory creates a complete space-themed family - void terrain, alien NPCs, cosmic obstacles
            cout << "Space Biome Content:\n";
            BiomeFactory* spaceFactory = new SpaceFactory();
            Terrain* spaceTerrain = spaceFactory->createTerrain();
            NPC* spaceNPC = spaceFactory->createNPC();
            Obstacle* spaceObstacle = spaceFactory->createObstacle();
            
            spaceTerrain->describe();
            spaceNPC->interact();
            spaceObstacle->block();
            cout << endl;

            //delete factory products first
            delete desertTerrain;
            delete desertNPC;
            delete desertObstacle;
            
            delete aquaticTerrain;
            delete aquaticNPC;
            delete aquaticObstacle;
            
            delete forestTerrain;
            delete forestNPC;
            delete forestObstacle;
            
            delete infernoTerrain;
            delete infernoNPC;
            delete infernoObstacle;
            
            delete spaceTerrain;
            delete spaceNPC;
            delete spaceObstacle;

            //delete factories last
            delete desertFactory;
            delete aquaticFactory;
            delete forestFactory;
            delete infernoFactory;
            delete spaceFactory;

        } else if (choice == 9) {
            cout << "\nExiting game..." << endl;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    cout << "re feditse ngwanaka\n";
    return 0;
}