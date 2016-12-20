//
// Benjy Berkowicz - 336182589
// Advanced Programming 2016-2017 Bar Ilan
//

#include "LuxuryTaxi.h"

using namespace std;

LuxuryTaxi::LuxuryTaxi(int id, CarMaker manu, Color color) : Taxi(id, manu, color) {

}

void LuxuryTaxi::move(stack<Point *> * path) {
    while (!path->empty()) {
        location->x = path->top()->x;
        location->y = path->top()->y;

        path->pop();
    }
}
