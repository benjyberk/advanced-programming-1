//
// Benjy Berkowicz - 336182589
// Advanced Programming 2016-2017 Bar Ilan
//

#include "StandardTaxi.h"

using namespace std;

StandardTaxi::StandardTaxi(int id, CarMaker manu, Color color) : Taxi(
        id, manu, color) {

}

void StandardTaxi::move(stack<Point *> * path) {
    while (!path->empty()) {
        location->x = path->top()->x;
        location->y = path->top()->y;
        path->pop();
    }
}
