#ifndef VERTEX_H_INCLUDED
#define VERTEX_H_INCLUDED

#include "ArrayList.h"

class Vertex
{
public:
    Vertex();

    void insertEdge(int Key);

    ArrayList<int> getAllEdgeLeftToRight(int& size);
    ArrayList<int> getAllEdgeRightToLeft(int& size);

    bool isVisited();
    void setVisitState(bool state);

    float getCostSoFar();
    void setCostSoFar(float cost);

    int getParent();
    void setParent(int key);
private:
    bool Visited;

    ArrayList<int> data;
    int TotalEdges;

    float CostSoFar; // g_value
    int parent; //  best parent so far
};

#endif // VERTEX_H_INCLUDED
