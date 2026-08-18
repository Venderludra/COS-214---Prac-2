#include "TravelMode.h"
#include <map>

    //state guards
    bool Walking::canTransition(const Traveller* t) const {
        //walking can always be left
        return true; 
    }

    bool Bicycle::canTransition(const Traveller* t) const {
        //they can leave Bicycle if they have it. here we check if you have the item to ensure you can switch
        return t->getHasBicycle(); 
    }

    bool Car::canTransition(const Traveller* t) const {
        return t->getHasCarKeys();
    }

    bool Boat::canTransition(const Traveller* t) const {
        return t->getHasBoat();
    }

    bool Flying::canTransition(const Traveller* t) const {
        return t->getHasPlaneTicket();
    }

    bool Transport::canTransition(const Traveller* t) const {
        return t->getHasTransportPass();
    }

    //context
    Traveller::Traveller(const std::string& travellerName)
        : currentMode(std::make_unique<Walking>()), //we first start on foot
        name(travellerName),
        hasBicycle(false), hasBoat(false), hasCarKeys(false), 
        hasPlaneTicket(false), hasTransportPass(false) {}

    void Traveller::move() const {
        if (currentMode) {
            std::cout << name << " is " << currentMode->move() << std::endl;
        }
    }

    void Traveller::switchMode(const std::string& targetMode) {
        if (!currentMode) return;

        //our guard check point.we ask the currentState if we are allowed to leave it
        if (!currentMode->canTransition(this)) {
            std::cout << "GUARD FAILED: Cannot leave current mode ("<< currentMode->getName() << ")!" << std::endl;
            return;
        }

        //create the new mode
        std::unique_ptr<TravelMode> newMode;
        if (targetMode == "Walking") newMode = std::make_unique<Walking>();
        else if (targetMode == "Bicycle") newMode = std::make_unique<Bicycle>();
        else if (targetMode == "Car") newMode = std::make_unique<Car>();
        else if (targetMode == "Boat") newMode = std::make_unique<Boat>();
        else if (targetMode == "Flying") newMode = std::make_unique<Flying>();
        else if (targetMode == "Transport") newMode = std::make_unique<Transport>();
        else {
            std::cout << "Unknown mode: " << targetMode << std::endl;
            return;
        }

        //leak-free swap (the old mode is auto-deleted by unique_ptr)
        currentMode = std::move(newMode);
        std::cout << "Switched to: " << currentMode->getName() << std::endl;
    }

    void Traveller::listAvailableModes() const {
        std::cout << "\n--- Available Modes to attempt to switch to ---" << std::endl;
        std::string modes[] = {"Walking", "Bicycle", "Car", "Boat", "Flying", "Transport"};
        
        //first, check if we can even leave the current mode
        if (!currentMode->canTransition(this)) {
            std::cout << "You are LOCKED into " << currentMode->getName() 
                    << ". Find the required item to unlock switching!" << std::endl;
            return;
        }

        //and if we can leave, show the available targets
        for (const auto& m : modes) {
            std::cout << " [AVAILABLE] " << m << std::endl;
        }
    }