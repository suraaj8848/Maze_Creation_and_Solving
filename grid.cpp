#include "grid.h"
#include <cstdlib>
#include <sstream>
#include <unordered_set>



Grid::Grid(int row, int column) : Row(row), Column(column)
{
    this->prepareGrid();
    this->createCellsinGrid();
}

Grid::~Grid() {
    // Iterate through the grid and delete each Cell*
    for (int i = 0; i < Row; i++) {
        for (int j = 0; j < Column; j++) {
            delete gridTable[i][j]; // Delete each Cell object
        }
    }
}

Cell* Grid::getCell(int row, int column)
{
    if(row >= Row || row < 0 || column >= Column || column < 0)
    {
        return nullptr;
    }
    return gridTable[row][column];
}

void Grid::prepareGrid() // this function will create a new 2D GridTable which will store a cell
{
    gridTable.resize(Row, std::vector<Cell*>(Column));
    for(int i=0; i<Row; i++)
    {
        for(int j=0;j<Column; j++)
        {
            gridTable[i][j] = new Cell(i, j);
        }
    }
}

void Grid::createCellsinGrid()
{
    for(int i=0; i<Row; i++)
    {
        for(int j=0;j<Column; j++)
        {
            Cell *testCell = gridTable[i][j];
            testCell->setNorth(getCell(i-1, j));
            testCell->setEast(getCell(i, j+1));
            testCell->setWest(getCell(i, j-1));
            testCell->setSouth(getCell(i+1,j));
        }
    }

}

std::vector<std::vector<Cell*>> Grid::returnGrid()
{
    return this->gridTable;
}

Cell* Grid::selectRandomCell()
{
    int ro = rand() % Row;
    int col = rand() % Column;

    return gridTable[ro][col];
}

int Grid::returnSize()
{
    return Row * Column;
}


std::string Grid::toString() {
    std::stringstream output;
    std::unordered_map<Cell*, int> pathIndices;  // Map to store the index of each cell in the path

    for (size_t i = 0; i < path.size(); ++i) {
        pathIndices[path[i]] = i;  
    }

  
    output << "+";
    for (int i = 0; i < Column; i++) {
        output << "---+";
    }
    output << "\n";

    for (int i = 0; i < Row; i++) {
        std::string top = "|";
        std::string bottom = "+";

        for (int j = 0; j < Column; j++) {
            Cell* cell = gridTable[i][j];

            std::string body = "   ";  

         
            if (pathIndices.find(cell) != pathIndices.end()) {
                if (pathIndices[cell] < 10) {
                    body = " " + std::to_string(pathIndices[cell]) + " ";  
                } else {
                    body = std::to_string(pathIndices[cell]) + " "; 
                }
            }

            std::string eastWall = (cell->getEast() && cell->isLinked(cell->getEast())) ? " " : "|";
            top += body + eastWall;

            std::string southWall = (cell->getSouth() && cell->isLinked(cell->getSouth())) ? "   " : "---";
            bottom += southWall + "+";
        }

        output << top << "\n";
        output << bottom << "\n";
    }

    return output.str();
}

int Grid::returnRow()
{
    return Row;
}

int Grid::returnColumn()
{
    return Column;
}

void Grid::setPath(std::vector<Cell*> road)
{
    path = road;
}



