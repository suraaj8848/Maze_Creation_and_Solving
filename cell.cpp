#include "cell.h"
#include <algorithm>
#include <queue>
#include "distance.h"


   
        Cell::Cell(int row, int column): row(row), column(column)
        {
            North = nullptr;
            South = nullptr;
            East = nullptr;
            West = nullptr;
        }

        // getters and setter
        Cell* Cell::getNorth() { return North;}
        Cell* Cell::getSouth() {return South;}
        Cell* Cell::getEast() { return East;}
        Cell* Cell::getWest() {return West;}

        void Cell::setWest(Cell *cell) { West = cell;}
        void Cell::setEast(Cell *cell) { East = cell;}
        void Cell::setSouth (Cell *cell) {South = cell;}
        void Cell::setNorth(Cell *cell) {North = cell;}

        std::vector<Cell*> Cell::returnLinks()
        {
            return this->LinkTable;
        }

        //updating the link table if two cells are to be linked
        bool Cell::isLinked(Cell *cell)
        {
            return (std::find(LinkTable.begin(), LinkTable.end(), cell) !=LinkTable.end()); 
        }

        void Cell::setLink(Cell *cell, bool bidi)
        {
            if(!(isLinked(cell)))
            {
                this->LinkTable.push_back(cell);  
            }

            if(bidi)
            {
                cell->setLink(this, false);  // this for bidirectional 
            }
        }


        std::vector<Cell*> Cell::returnNeighbours()
        {
            std::vector<Cell*> vicinas;
            if(North) vicinas.push_back(North);
            if(South) vicinas.push_back(South);
            if(East) vicinas.push_back(East);
            if(West) vicinas.push_back(West);

            return vicinas;
        }
    Distance* Cell::distances()
    {
        Distance *RootCell = new Distance(this); // root cell
        std::queue<Cell*> Frontier;
        Frontier.push(this);

        while(!Frontier.empty())
        {
            Cell *cell = Frontier.front();
            Frontier.pop(); // deletes the front element

            for(auto &cells: cell->returnLinks())
            {
                if(RootCell->distFromRoot(cells) == -1)
                {
                    RootCell->setDistance(cells, RootCell->distFromRoot(cell) + 1);
                    Frontier.push(cells);
                }
            }
        }

        return RootCell;
    
    }