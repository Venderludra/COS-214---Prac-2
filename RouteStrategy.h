#ifndef ROUTESTRATEGY_H
#define ROUTESTRATEGY_H

#include <string>
#include <iostream>
#include <memory>

    //the abstract strategy
    class RouteStrategy {
        public:
            virtual ~RouteStrategy() = default; //virtual destructor
            
            virtual std::string calculateRoute(const std::string& origin, const std::string& destination) const = 0;
            virtual std::string getName() const = 0;
    };

    //the concrete strategies
    class ShortestPath : public RouteStrategy {
        public:
            std::string calculateRoute(const std::string& origin, const std::string& destination) const override {
                return "Calculating the shortest distance route from " + origin + " to " + destination + ".";
            }
            std::string getName() const override { return "Shortest Path"; }
    };

    class FastestPath : public RouteStrategy {
        public:
            std::string calculateRoute(const std::string& origin, const std::string& destination) const override {
                return "Calculating the fastest time route from " + origin + " to " + destination + ".";
            }
            std::string getName() const override { return "Fastest Path"; }
    };

    class ScenicPath : public RouteStrategy {
        public:
            std::string calculateRoute(const std::string& origin, const std::string& destination) const override {
                return "Calculating the most scenic route from " + origin + " to " + destination + ".";
            }
            std::string getName() const override { return "Scenic Path"; }
    };

    class CheapestPath : public RouteStrategy {
        public:
            std::string calculateRoute(const std::string& origin, const std::string& destination) const override {
                return "Calculating the cheapest cost route from " + origin + " to " + destination + ".";
            }
            std::string getName() const override { return "Cheapest Path"; }
    };

    //the context
    class Trip {
        private:
            std::unique_ptr<RouteStrategy> strategy;//remember - the unique_ptr "manages" our memory
            std::string origin;
            std::string destination;

        public:
            Trip(const std::string& start, const std::string& end);
            ~Trip(); //the destructor

            //behaviour
            void planRoute() const;

            //the runtime strategy switching
            void setStrategy(std::unique_ptr<RouteStrategy> newStrategy);
            std::string getCurrentStrategyName() const;
    };

#endif