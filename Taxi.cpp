//
// Benjy Berkowicz - 336182589
// Advanced Programming 2016-2017 Bar Ilan
//

#include "Taxi.h"

Taxi::Taxi(int newId, CarMaker manu, Color newCol) {
    id = newId;
    color = newCol;
    manufacturer = manu;
}

Color Taxi::getColor() {
    return color;
}

CarMaker Taxi::getManufacturer() {
    return manufacturer;
}

int Taxi::getOdom() {
    return odometer;
}

int Taxi::getID() {
    return id;
}

int Taxi::getPrice() {
    return 0;
}

Passenger *Taxi::getPassenger() {
    return 0;
}

void Taxi::setPassenger(Passenger) {

}

void Taxi::addListener(Listener *) {

}

void Taxi::removeListener(Listener *) {

}

void Taxi::setLocation(Point * newPoint) {
    location = newPoint;
}

void Taxi::setDriver(Driver * newDriver) {
    driver = newDriver;
}
