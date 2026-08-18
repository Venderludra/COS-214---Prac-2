#include "RouteStrategy.h"
using namespace std;

//context implementation
Trip::Trip(const std::string& start, const std::string& end) : strategy(std::make_unique<ShortestPath>()), //default strategy
      origin(start), 
      destination(end) {}

// Destructor implementation
Trip::~Trip() {
    // The std::unique_ptr strategy member automatically deletes the strategy object.
    // No manual delete is required here to avoid memory leaks.
}

void Trip::planRoute() const {
    if (strategy) {
        cout << "Trip from " << origin << " to " << destination << ":" << endl;
        cout << "[" << strategy->getName() << "] " << strategy->calculateRoute(origin, destination) <<endl;
    }
}

void Trip::setStrategy(std::unique_ptr<RouteStrategy> newStrategy) {
    //leak-free swap (old strategy is auto-deleted by unique_ptr)
    strategy = move(newStrategy);
    cout << "Route strategy changed to: " << strategy->getName() << endl;
}

string Trip::getCurrentStrategyName() const {
    return strategy ? strategy->getName() : "None";
}