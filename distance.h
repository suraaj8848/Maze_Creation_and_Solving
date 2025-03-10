#ifndef DISTANCE_H
#define DISTANCE_H

#include <unordered_map>
#include <vector>


class Cell;

class Distance
{
    private:
        Cell *root;
        std::unordered_map<Cell*, int> DistanceValues; // hash table to store the vvalues of distance from the root cell

    public:
        Distance(Cell *cell);
        int distFromRoot(Cell *cell); //return distance from root
        void setDistance(Cell *cell, int distance); //set distance from root]
        std::unordered_map<Cell*, int> getAllDistances(); //returns the entire hashtable
        std::vector<Cell*> shortestPathto(Cell *goal); //returns the shortest path
};

#endif