#include "ab.h"
#include <cstdlib>
#include <vector>
// #include "raylib.h"

void AldousBroder::MazeGenerator(Grid *grid)
{
   Cell *cell = grid->selectRandomCell();
   int unvisited = grid->returnSize() - 1; // assigns row x column - 1

   while(unvisited > 0)
   {
        std::vector<Cell*>vicinity = cell->returnNeighbours();
        Cell *neighbour = vicinity[rand() % vicinity.size()];

        if(neighbour->returnLinks().empty()) // meaning the cell has not yet been visited
        {
            cell->setLink(neighbour);
            unvisited--;
        }

        cell = neighbour;// now we (POV cell is here)
   }

}