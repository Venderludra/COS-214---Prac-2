#include "RouteStrategy.h"
using namespace std;

//context implementation
Trip::Trip(const std::string& start, const std::string& end) : strategy(new ShortestPath()), //default strategy
      origin(start), 
      destination(end) {}

// Destructor implementation
Trip::~Trip() {
    delete strategy;
}

void Trip::planRoute() const {
    if (strategy) {
        cout << "Trip from " << origin << " to " << destination << ":" << endl;
        cout << "[" << strategy->getName() << "] " << strategy->calculateRoute(origin, destination) <<endl;
    }
}

void Trip::setStrategy(RouteStrategy* newStrategy) {
    delete strategy;
    strategy = newStrategy;
    cout << "Route strategy changed to: " << strategy->getName() << endl;
}

string Trip::getCurrentStrategyName() const {
    return strategy ? strategy->getName() : "None";
}