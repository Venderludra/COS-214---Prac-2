#ifndef TRAVELMODE_H
#define TRAVELMODE_H

#include <string>
#include <iostream>
#include <memory>

class Traveller;

//the abstract base
class TravelMode {
    public:
        virtual ~TravelMode() = default; //virtual destructor
        
        //our pure virtual operations
        virtual std::string move() const = 0;
        virtual std::string getName() const = 0;
        virtual bool canTransition(const Traveller* traveller) const = 0;
};

//the concrete states
class Walking : public TravelMode {
    public:
        std::string move() const override { return "Walking slowly through the terrain."; }
        std::string getName() const override { return "Walking"; }

        bool canTransition(const Traveller* traveller) const override;
};

class Bicycle : public TravelMode {
    public:
        std::string move() const override { return "Pedaling swiftly along the path."; }
        std::string getName() const override { return "Bicycle"; }

        bool canTransition(const Traveller* traveller) const override;
};

class Car : public TravelMode {
    public:
        std::string move() const override { return "Driving fast on the road."; }
        std::string getName() const override { return "Car"; }

        bool canTransition(const Traveller* traveller) const override;
};

class Boat : public TravelMode {
    public:
        std::string move() const override { return "Sailing across the water."; }
        std::string getName() const override { return "Boat"; }

        bool canTransition(const Traveller* traveller) const override;
};

class Flying : public TravelMode {
    public:
        std::string move() const override { return "Soaring through the sky!"; }
        std::string getName() const override { return "Flying"; }

        bool canTransition(const Traveller* traveller) const override;
};

class Transport : public TravelMode {
    public:
        std::string move() const override { return "Taking public transport."; }
        std::string getName() const override { return "Transport"; }

        bool canTransition(const Traveller* traveller) const override;
};

//the context
class Traveller {
    private:
        std::unique_ptr<TravelMode> currentMode;
        
        std::string name;
        //state variables for transition guards
        bool hasBicycle;
        bool hasBoat;
        bool hasCarKeys;
        bool hasPlaneTicket;
        bool hasTransportPass;

    public:
        Traveller(const std::string& travellerName = "Wayfarer");
        ~Traveller() = default; // unique_ptr handles memory cleanup

        //the getters for the states to use in guard checks
        bool getHasBicycle() const { return hasBicycle; }
        bool getHasBoat() const { return hasBoat; }
        bool getHasCarKeys() const { return hasCarKeys; }
        bool getHasPlaneTicket() const { return hasPlaneTicket; }
        bool getHasTransportPass() const { return hasTransportPass; }

        //the setters to unlock new modes during gameplay
        void findBicycle() { hasBicycle = true; }
        void findBoat() { hasBoat = true; }
        void findCarKeys() { hasCarKeys = true; }
        void findPlaneTicket() { hasPlaneTicket = true; }
        void findTransportPass() { hasTransportPass = true; }

        //behaviour
        void move() const;
        
        //the runtime state switching (Guarded)
        void switchMode(const std::string& targetMode);
        void listAvailableModes() const;
};

#endif