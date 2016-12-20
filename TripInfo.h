//
// Benjy Berkowicz - 336182589
// Advanced Programming 2016-2017 Bar Ilan
//

#ifndef ADVANCED_EX2_TRIPINFO_H
#define ADVANCED_EX2_TRIPINFO_H


#include "Point.h"

class TripInfo {
private:
    int rideID;
    int currentDistance;
    Point startPoint;
    Point endPoint;
    int tarrif;
    int numPassengers;
public:
    TripInfo(int, Point, Point, int, int);
    void updateMeter(int);
    void changeEndPoint(Point);
    int getRideID();
    int getCurrentDistance();
    Point getStartPoint();
    Point getEndPoint();
};


#endif //ADVANCED_EX2_TRIPINFO_H
