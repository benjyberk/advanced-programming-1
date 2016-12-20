//
// Benjy Berkowicz - 336182589
// Advanced Programming 2016-2017 Bar Ilan
//

#ifndef ADVANCED_EX2_TAXIDISPATCH_H
#define ADVANCED_EX2_TAXIDISPATCH_H

class Driver;
class DriverTaxiContainer;

#include "DriverTaxiContainer.h"
#include <map>
#include <vector>
#include <deque>
#include "Driver.h"
#include "Taxi.h"
#include "TripInfo.h"
#include "DriverLocationListener.h"
#include "GridMap.h"

/**
 * The TaxiDispatcher holds all trip orders as well as taxis, drivers
 * and their positions.  It keeps track of the locations via listeners
 */
class TaxiDispatch {
private:
    std::map<int, DriverTaxiContainer *> database;
    std::deque<TripInfo *> trips;
    std::vector<DriverLocationListener *> listeners;
    GridMap * gridMap;
public:
    TaxiDispatch(GridMap *);
    // Runs the trips in the trips database
    void provideTaxi();
    void addTaxi(Taxi *);
    void addDriver(Driver *);
    void addTrip(TripInfo *);
    Point * getDriverLocation(int id);
    ~TaxiDispatch();
};


#endif //ADVANCED_EX2_TAXIDISPATCH_H
