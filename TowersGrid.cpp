#include "TowersGrid.h"
#include "VectorFunctions.h"

// basic constructor
// resize the vectors and put each height to 0
// also populates the heightRange vector with appropriate values
TowersGrid::TowersGrid(int gridSize)
{
    this->gridSize = gridSize;
    grid.resize(gridSize);
    
    for (int x = 0; x < gridSize; ++x)
        grid[x].resize(gridSize);
    
    for (int x = 0; x < gridSize; ++x)
        for (int y = 0; y < gridSize; ++y)
            grid[x][y] = 0;
    
    for (int x = 0; x < gridSize; ++x)
        heightRange.push_back(x + 1);
}

// generate a valid set of heights for the grid
// this is the tricky part
/*
 Pretty much a brute-force method that knows when to quit early.
 
 The method fills up the grid one tile at a time by picking numbers from
 1 to gridSize out of a list. Each time one of these numbers is used,
 it is removed from the list of potential numbers for the current row.
 In this situation, the first row should always generate correctly.
 
 Later rows have to have the numbers in the rows above them checked as well
 so that both the rows AND columns of the grid are valid. This method of
 blind-picking numbers can lead to impossible situations like
 
 15432
 5134x <- can't put a 2 here, there's already one in its column
 
 In this case, the grid wipes itself and starts over. These impossible
 situations are small enough in terms of resource use to result in
 reasonable generation times and numbers of generation attempts.
 
 */
void TowersGrid::generate()
{
    vector<int> nextHeightPool;
    vector<int> nextRow; // holds the numbers in current column for removeElements
    
    bool impossibleFlag = false; // flag to handle loop control and grid reset for impossible case
    
    nextRow.resize(gridSize);
    
    /*
     MAIN GENERATION LOOP:
     Attempt to generate a valid grid until a proper arrangement is found.
     grid[0][0] will only be 0 if
     
     1. It's the first time the algorithm is trying to generate
     2. The algorithm has tried and failed, which reset the entire grid to 0
     
     Because of this, grid[0][0] being a nonzero number implies that the grid
     has been successfully generated, and that the loop can stop running.
     */
    while (grid[0][0] == 0)
    {
        for (int x = 0; x < gridSize; ++x)
        {
            for (int y = 0; y < gridSize; ++y)
            {
                // creates a list of existing heights in the current tile's row
                for (int x = 0; x < gridSize; ++x)
                    nextRow[x] = grid[x][y];
                
                // this value here is the list of heights not taken in current row/column
                nextHeightPool = removeElements( removeElements( heightRange, grid[x] ), nextRow );
            
                if (nextHeightPool.size() == 0)
                {
                    // we've reached the impossible case, so reset the grid and start over
                    reset();
                    impossibleFlag = true;
                    break;
                }
                else
                {
                    grid[x][y] = randFrom(nextHeightPool);
                }
            }
            if (impossibleFlag)
            {
                impossibleFlag = false;
                break;
            }
        }
    }
}


// resets the heights to 0
// mainly for use in TowersGrid::generate() when the algorithm fails,
// so we keep it private
void TowersGrid::reset()
{
    for (int x = 0; x < gridSize; ++x)
        for (int y = 0; y < gridSize; ++y)
            grid[x][y] = 0;
}

// print image of grid (with heights) to console
void TowersGrid::display()
{
    for (int x = 0; x < gridSize; ++x)
    {
        for (int y = 0; y < gridSize; ++y)
        {
            cout << grid[x][y] << ' ';
        }
        cout << endl;
    }
}