#include "VectorFunctions.h"

// returns random int from lower to upper, inclusive
int randInRange(int lower, int upper)
{
    return rand() % (upper - lower + 1) + lower;
}

// gets a random element out of the given vector
int randFrom(const vector<int>& vec)
{
    return vec[ randInRange(0, vec.size() - 1) ];
}

// search vec for given item
// returns index of first location of item in vec if found, -1 if otherwise
int search(const vector<int>& vec, int item)
{
    for (int x = 0; x < vec.size(); ++x)
        if (vec[x] == item)
            return x;
    
    return -1;
}

// takes base vector "vec" and removes all items from it that are
// also present in the vector "elements"
vector<int> removeElements(const vector<int>& vec, const vector<int>& elements)
{
    vector<int> newVec = vec;
    int nextSearchIndex;
    
    // search "vec" for each element in "elements", remove if found
    for (int x = 0; x < elements.size(); ++x)
    {
        nextSearchIndex = search(newVec, elements[x]);
        if (nextSearchIndex != -1)
            newVec.erase(newVec.begin() + nextSearchIndex);
            
    }
    
    return newVec;
}