#include "Vertex.h"

Vertex::Vertex()
{
    TotalEdges = 0;
    Visited = false;

    CostSoFar = 0.0f;
    parent = 0;
}

bool Vertex::isVisited()
{
    return Visited;
}

void Vertex::setVisitState(bool state)
{
    Visited = state;
}

void Vertex::insertEdge(int Key)
{
    data[TotalEdges++] = Key;
}

ArrayList<int> Vertex::getAllEdgeLeftToRight(int& size)
{
    size = TotalEdges;

    return data;
}

ArrayList<int> Vertex::getAllEdgeRightToLeft(int& size)
{
    size = TotalEdges;

    ArrayList<int> temp;

    for (int i = TotalEdges - 1, j = 0; i >= 0; i--, j++)
        temp[j] = data[i];

    return temp;
}

float Vertex::getCostSoFar()
{
    return CostSoFar;
}

void Vertex::setCostSoFar(float cost)
{
    CostSoFar = cost;
}

int Vertex::getParent()
{
    return parent;
}

void Vertex::setParent(int key)
{
    parent = key;
}
