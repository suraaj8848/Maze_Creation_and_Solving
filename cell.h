#ifndef CELL_H
#define CELL_H

#include <vector>

class Distance;

class Cell
{
    private:
    int row, column; // this will store the postion of the cell once part of the grid
    std::vector<Cell*> LinkTable; // hash table can be used as well since they have o(1) search time but a cell can have at max four links and normally 
    // the link number is even less, so the memory efficiency of vectors is preferred

    // these are for the address to its neigbours
    Cell *North;
    Cell *South;
    Cell *East;
    Cell * West;

    public:
        Cell(int row, int column);
        

        Cell* getNorth();
        Cell* getSouth();
        Cell* getEast();
        Cell* getWest();
        void setWest(Cell *cell);
        void setEast(Cell *cell);
        void setSouth (Cell *cell);
        void setNorth(Cell *cell);
        std::vector<Cell*> returnLinks();

        bool isLinked(Cell *cell);
        void setLink(Cell *cell, bool bidi = true);

        std::vector<Cell*> returnNeighbours();
        Distance* distances();

};


#endif