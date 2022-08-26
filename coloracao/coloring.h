#ifndef COLORING_H
#define COLORING_H
#include <vector>
#include "graphm.h"
#include <algorithm>
class Coloring
{
private:
    std::vector<int> *colors;
    GraphM *g = nullptr;

public:
    Coloring(int n, GraphM *g);

    bool isSafe(int pos, int color);
    std::vector<int>* kColoring(int i =0);
    int l321(int index, int lambda, int color);
    ~Coloring();
};

#endif
