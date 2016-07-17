#ifndef VECTORFUNCTIONS
#define VECTORFUNCTIONS

#include "cstdlib"
#include "vector"
using namespace std;

int randInRange(int lower, int upper);

int randFrom(const vector<int>& vec);

int search(const vector<int>& vec, int item);

vector<int> removeElements(const vector<int>& vec, const vector<int>& elements);

#endif