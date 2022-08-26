#include <iostream>
#include "graphm.h"
#include "graph.h"
#include "coloring.h"
using namespace std;

int main()
{
    GraphM *g = new GraphM(2);
    Coloring *color = new Coloring(2,g);
    cout << "Hello World!" << endl;
    return 0;
}
