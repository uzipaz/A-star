#include "map.h"

#include <iostream>
using namespace std;

map::map()
{
    //this->StaticObj = NULL;
    //this->NavMeshes = NULL;

    this->NumOfPolygons = 0;
    this->NumOfObstacles = 0;
}

map::~map()
{
    /*if (this->StaticObj != NULL)
        delete [] StaticObj;

    if (this->NavMeshes != NULL)
        delete [] NavMeshes;*/
}

/*bool map::initialize(obstacle* StaticObj, int NumOfObstacles, ConvexPolygon* NavMeshes, int NumOfPolygons)
{
    this->StaticObj = StaticObj;
    this->NumOfObstacles = NumOfObstacles;

    this->NavMeshes = NavMeshes;
    this->NumOfPolygons = NumOfPolygons;

    if (NavMeshes != NULL)
        createGraphFromMesh();

    return true;
}*/

bool map::initialize()
{
    createGraphFromMesh();

    /*ArrayList<int> edges; int size, i, j;
    for (i = 0; i < NumOfPolygons; i++)
    {
        cout << i << ": ";
        edges = Graph[i].getAllEdgeLeftToRight(size);
        for (j = 0; j < size - 1; j++)
        {
            cout << edges[j] << ", ";
        }

        cout << edges[j] << "\n";
    }*/

    return true;
}

void map::addObstacle(obstacle* obj)
{
    StaticObj[NumOfObstacles++] = *obj;
}

void map::addNavMesh(ConvexPolygon* poly)
{
    NavMeshes[NumOfPolygons++] = *poly;
}

void map::render()
{
    int i;
    for (i = 0; i < NumOfObstacles; i++)
        StaticObj[i].render();

    glColor3f(1.0f, 0, 1.0f);
    for (i = 0; i < NumOfPolygons; i++)
        NavMeshes[i].render();
}

stack<Point2D>* map::getOptimalPath(Point2D StartPos, Point2D FinishPos)
{
    int StartIndex = -1, FinishIndex = -1, CurrentIndex;
    int i;

    for (i = 0; i < NumOfPolygons; i++)
    {
        if (NavMeshes[i].inclusionOfPoint(StartPos))
            StartIndex = i;

        if (NavMeshes[i].inclusionOfPoint(FinishPos))
            FinishIndex = i;
    }

    if (StartIndex == -1 || FinishIndex == -1)
        return NULL;

    else
    {
        stack<Point2D>* path = new stack<Point2D>;
        if (StartIndex == FinishIndex)
        {
            path->push(FinishPos);
            path->push(StartPos);

            return path;
        }

        ArrayList<Vertex> temp_graph = Graph;
        explore(temp_graph, StartPos, StartIndex, FinishPos, FinishIndex);

        CurrentIndex = temp_graph[FinishIndex].getParent();
        path->push(FinishPos);

        while (CurrentIndex != StartIndex)
        {
            path->push(NavMeshes[CurrentIndex].getCentroid());
            CurrentIndex = temp_graph[CurrentIndex].getParent();
        }

        path->push(StartPos);

        return path;
    }
}

void map::explore(ArrayList<Vertex>& temp_graph, Point2D StartPos, int StartIndex, Point2D FinishPos, int FinishIndex)
{
    int CurrentIndex = StartIndex, NumOfEdges, i, NextIndex;
    GLfloat new_g_value;
    PriorityQueue<float> PQ;
    ArrayList<int> edges;

    temp_graph[StartIndex].setCostSoFar(0.0);
    temp_graph[StartIndex].setVisitState(true);

    PQ.insert(StartIndex, getDistance(StartPos, FinishPos));

    while(! PQ.isEmpty())
    {
        CurrentIndex = PQ.remove();

        if (CurrentIndex == FinishIndex)
            return;

        else
        {
            edges = temp_graph[CurrentIndex].getAllEdgeLeftToRight(NumOfEdges);
            for (i = 0; i < NumOfEdges; i++)
            {
                NextIndex = edges[i];

                new_g_value = temp_graph[CurrentIndex].getCostSoFar() + getDistance(NavMeshes[CurrentIndex].getCentroid(), NavMeshes[NextIndex].getCentroid());
                if ((!temp_graph[NextIndex].isVisited()) || new_g_value < temp_graph[NextIndex].getCostSoFar())
                {
                    temp_graph[NextIndex].setCostSoFar(new_g_value);
                    temp_graph[NextIndex].setParent(CurrentIndex);

                    if (!temp_graph[NextIndex].isVisited())
                        temp_graph[NextIndex].setVisitState(true);

                    PQ.insert(NextIndex, temp_graph[NextIndex].getCostSoFar() + getDistance(NavMeshes[NextIndex].getCentroid(), FinishPos));
                }
            }
        }
    }
}

void map::createGraphFromMesh()
{
    int i, j;
    for (i = 0; i < NumOfPolygons; i++)
    {
        for (j = 0; j < NumOfPolygons; j++)
        {
            if (NavMeshes[i].isNeighbor(&(NavMeshes[j])) && j != i)
            {
                Graph[i].insertEdge(j);
                //Graph[j].insertEdge(i);
            }
        }
    }
}

GLfloat map::getDistance(Point2D StartPos, Point2D FinishPos)
{
    return (GLfloat)(sqrt(pow(StartPos.x - FinishPos.x, 2) + pow(StartPos.y - FinishPos.y, 2)));
}

