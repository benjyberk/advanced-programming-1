//
// Benjy Berkowicz - 336182589
// Advanced Programming 2016-2017 Bar Ilan
//

#include "TripInfo.h"

using namespace std;

TripInfo::TripInfo(int r_id, Point r_sPoint, Point r_dPoint, int r_numPassenger, int r_tarif) {
    rideID = r_id;
    startPoint = r_sPoint;
    endPoint = r_dPoint;
    numPassengers = r_numPassenger;
    tarrif = r_tarif;
}

void TripInfo::updateMeter(int) {

}

void TripInfo::changeEndPoint(Point) {

}

int TripInfo::getRideID() {
    return rideID;
}

int TripInfo::getCurrentDistance() {
    return 0;
}

Point TripInfo::getStartPoint() {
    return startPoint;
}

Point TripInfo::getEndPoint() {
    return endPoint;
}
