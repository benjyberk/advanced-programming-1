//
// Benjy Berkowicz - 336182589
// Advanced Programming 2016-2017 Bar Ilan
//

#ifndef ADVANCED_EX2_GAMECONTROL_H
#define ADVANCED_EX2_GAMECONTROL_H


#include <map>
#include "TaxiDispatch.h"

/**
 * The Game Control class handles all input and directs the creation
 * of the objects needed for the game.
 */
class GameControl {
private:
    std::vector<Point> obstacles;
    GridMap * gridmap;
    TaxiDispatch * dispatcher;
    // Tokenizes a string and returns the vector
    std::vector<std::string> tokenizeByChar(std::string, char);
    // Converts the input string into the enumeration based on type
    int enumFromString(std::string raw, char type);
public:
    GameControl();
    // Parses a driver from input and adds it to the Taxi Dispatcher
    void addDriver(std::string);
    // Parses a taxi from input and adds it to the Taxi Dispatcher
    void addTaxi(std::string input);
    // Parses the dimensions of the game, creates the gridmap and obstacles elements
    void getGeneralInput();
    // Adds a new trip to the taxi dispatcher
    void addRide(std::string);
    // Outputs the location of a taxi
    void printTaxiLocation(std::string);
    // Runs all the trips queued.
    void updateTaxiPositions();
    ~GameControl();
};


#endif //ADVANCED_EX2_GAMECONTROL_H
