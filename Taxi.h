//
// Benjy Berkowicz - 336182589
// Advanced Programming 2016-2017 Bar Ilan
//

#ifndef ADVANCED_EX2_TAXI_H
#define ADVANCED_EX2_TAXI_H

class Passenger;
class Listener;
class Driver;

#include <stack>
#include "Color.h"
#include "Passenger.h"
#include "CarMaker.h"
#include "Driver.h"

class Taxi {
private:
    int id;
    int odometer;
    CarMaker manufacturer;
    Color color;
    Driver* driver;
    Listener** listeners;
protected:
    Passenger* passengers;
    Point* location;
    int tariff;
public:
    Taxi(int, CarMaker, Color);
    Color getColor();
    CarMaker getManufacturer();
    int getOdom();
    int getID();
    int getPrice();
    Passenger* getPassenger();
    void setPassenger(Passenger);
    void setLocation(Point *);
    virtual void move(std::stack<Point *> *) = 0;
    void addListener(Listener*);
    void removeListener(Listener*);
    void setDriver(Driver *);
};


#endif //ADVANCED_EX2_TAXI_H
