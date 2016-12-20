//
// Benjy Berkowicz - 336182589
// Advanced Programming 2016-2017 Bar Ilan
//

#include "TaxiDispatch.h"
#include "findPath.h"

using namespace std;

void TaxiDispatch::provideTaxi() {
    findPath router;
    stack<Point *> * path;

    // We loop through all the trips, assigning them/running them if possible
    while (!trips.empty()) {
        // We take the first trip
        TripInfo * current = trips[0];

        // We search for a taxi/driver in the correct position
        for (int i = 0; i < listeners.size(); i++) {
            DriverLocationListener * foundListener = listeners[i];
            Point a = *(foundListener->getLocation());
            Point b = current->getStartPoint();
            int foundID = foundListener->id;
            // If we have found a taxi at the correct location
            if (a == b) {
                // We move the taxi along the calculated route
                path = router.bfsRoute(gridMap, a, current->getEndPoint());
                database[foundID]->taxi->move(path);

                listeners.erase(listeners.begin() + i);
                listeners.push_back(foundListener);
                delete path;
                break;
            }
        }

        delete trips.front();
        trips.pop_front();
    }
}

void TaxiDispatch::addTaxi(Taxi * newTaxi) {
    // If the taxi ID doesn't appear, we initialize it
    if (database.count(newTaxi->getID()) == 0) {
        database[newTaxi->getID()] = new DriverTaxiContainer();
    }
    newTaxi->setLocation(database[newTaxi->getID()]->location);
    database[newTaxi->getID()]->setTaxi(newTaxi);
}

void TaxiDispatch::addDriver(Driver * newDriver) {
    // If the driver id doesn't appear, we initialize it
    if (database.count(newDriver->getID()) == 0) {
        database[newDriver->getID()] = new DriverTaxiContainer();
    }

    // We generate the listener, and attune it to the location of the driver
    Point * start = database[newDriver->getID()]->location;
    DriverLocationListener * l = new DriverLocationListener(start, newDriver->getID());
    listeners.push_back(l);
    newDriver->addListener(l);
    database[newDriver->getID()]->setDriver(newDriver);
}

void TaxiDispatch::addTrip(TripInfo * newTrip) {
    // We add the trip to the list of trips
    trips.push_back(newTrip);
}

Point *TaxiDispatch::getDriverLocation(int id) {
    // We search the listeners for the correct ID
    for (int i = 0; i < listeners.size(); i++) {
        if (listeners[i]->id == id) {
            return listeners[i]->getLocation();
        }
    }
}

TaxiDispatch::TaxiDispatch(GridMap * grid) {
    gridMap = grid;
}

TaxiDispatch::~TaxiDispatch() {
    for (int i = 0; i < listeners.size(); i++) {
        delete listeners[i];
    }
    for (int i = 0; i < trips.size(); i++) {
        delete trips[i];
    }

    typedef map<int, DriverTaxiContainer *>::iterator it_type;
    for(it_type iterator = database.begin(); iterator != database.end(); iterator++) {
        delete iterator->second;
    }

}
