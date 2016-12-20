//
// Benjy Berkowicz - 336182589
// Advanced Programming 2016-2017 Bar Ilan
//

#include "findPath.h"
using namespace std;

stack<Point *> * findPath::bfsRoute(GridMap* search, Point source, Point destination) {
    queue<GraphSquare*> nodes;
    GraphSquare* check;
    vector<GraphSquare *> adjacent;
    Point* checkPos;
    bool found = false;

    // First, we assign the source as having 0 distance from the source (for later calculations)
    search->getNode(source)->distanceFromSource = 0;
    // We add the source-point to the stack of points to explore
    nodes.push(search->getNode(source));

    // The while loop explores all adjacent points until there are no more points to search
    // Or until the destination is found
    while (!nodes.empty() && !found) {
        check = nodes.front();
        checkPos = check->gridLocation;
        nodes.pop();
        // Neighbours of the point are given by the GridMap in a clockwise manner
        adjacent = search->getNeighbours(*checkPos);

        // Every neighbour is then checked to see if it is the destination, and if not, its pathway
        // back to the source is assigned (as well as its distance from the source)
        // To avoid repeats, any node that is NOT -1 distance from source (default) is ignored.
        // The 0th element of adjacent in the x member contains the number of elements in the array
        for (int i = 0; i < adjacent.size(); i++) {
            if (adjacent[i]->distanceFromSource == -1) {
                adjacent[i]->distanceFromSource = check->distanceFromSource + 1;
                adjacent[i]->predecessor = checkPos;
                nodes.push(adjacent[i]);
                // If the node is found, we may leave the loop
                if (*adjacent[i]->gridLocation == destination) {
                    found = true;
                    break;
                }
            }
        }
    }

    // We now transverse from the destination to the source, the print-out is in reverse order
    // so we use a stack (FILO).
    stack<Point *> * reverseOrder = new stack<Point *>;
    check = search->getNode(destination);
    found = false;
    // We follow the trail back from the source to the destination using the 'predecessor' member.
    while (!found) {
        Point* current = check->gridLocation;
        reverseOrder->push(current);
        if (*current == source) {
            found = true;
        }
            // The next node is followed backwards
        else {
            check = search->getNode(*(check->predecessor));
        }
    }
    search->reset();
    return reverseOrder;
}
