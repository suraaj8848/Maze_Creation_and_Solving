#include "distance.h"
#include "cell.h"
#include <algorithm>


Distance::Distance(Cell *cell) : root(cell)
{
    DistanceValues[root] = 0; // root cell is the starting point
}

int Distance::distFromRoot(Cell *cell)
{
    return (DistanceValues.count(cell)? DistanceValues[cell] : -1); // returns -1 if not found
}

void Distance::setDistance(Cell *cell, int distance)
{
    DistanceValues[cell] = distance;
}

std::unordered_map<Cell*, int> Distance::getAllDistances()
{
    return DistanceValues;
}

std::vector<Cell*> Distance::shortestPathto(Cell *goal)
{
    std::vector<Cell*> Path;
    Cell *current = goal;

    while(current!=root)
    {
        Path.push_back(current);
        for(auto &neighbour :current->returnLinks())
        {
            if(distFromRoot(neighbour) < distFromRoot(current))
            {
                current = neighbour;
                break;
            }
        }   
    }
    Path.push_back(root);
    std::reverse(Path.begin(), Path.end());
    return Path;
}