#ifndef GRID_H
#define GRID_H
#include <vector>
#include "cell.h"
#include <string>
#include "distance.h"
#include <unordered_map>

class Grid
{
    private:
        int Row, Column; //these are for the amount of ro and col
        std::vector<std::vector<Cell*>> gridTable;
        std::vector<Cell*> path; //stores the cell with the shortest path

    public:
        Grid(int row, int column);
        ~Grid();
        void prepareGrid();
        void createCellsinGrid();
        Cell* getCell(int row, int column);
        Cell* selectRandomCell();
        std::vector<std::vector<Cell*>> returnGrid();
        int returnSize();
        std::string toString();
        void draw(int cellSize);
        int returnRow();
        int returnColumn();
        void setPath(std::vector<Cell*> road);
   
        
};


#endif