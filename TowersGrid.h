#ifndef TOWERSGRID_H
#define TOWERSGRID_H

#include "iostream"
#include "vector"
using namespace std;

class TowersGrid
{
private:
    vector<vector<int>> grid;
    
    int gridSize;
    
    vector<int> heightRange;
    
    void reset();
    
public:
    TowersGrid(int gridSize);
    
    void generate();
    
    void display();
};

#endif