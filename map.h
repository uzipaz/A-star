#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED

#include "ArrayList.h"

#include "obstacle.h"
#include "ConvexPolygon.h"
#include "Vertex.h"
#include "stack.h"
#include "PriorityQueue.h"

class map
{
public:
    map();
    ~map();

    //bool initialize(obstacle* StaticObj, int NumOfObstacles, ConvexPolygon* NavMeshes, int NumOfPolygons);
    bool initialize();
    void addObstacle(obstacle* StaticObj);
    void addNavMesh(ConvexPolygon* poly);
    void render();

    stack<Point2D>* getOptimalPath(Point2D StartPos, Point2D FinishPos); // using A*
private:
    stack<int>* Astar(Point2D StartPos, Point2D FinishPos);
    void explore(ArrayList<Vertex>& temp_graph, Point2D StartPos, int StartIndex, Point2D FinishPos, int FinishIndex);

    GLfloat getDistance(Point2D StartPos, Point2D FinishPos);
    void createGraphFromMesh(); // create a pathfinding graph from navigation meshes

    ArrayList<obstacle> StaticObj;
    int NumOfObstacles;

    ArrayList<ConvexPolygon> NavMeshes;
    int NumOfPolygons;

    ArrayList<Vertex> Graph; // Pathfinding graph for A* algorithm
};

#endif // MAP_H_INCLUDED
