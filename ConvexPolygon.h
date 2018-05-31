#ifndef CONVEXPOLYGON_H_INCLUDED
#define CONVEXPOLYGON_H_INCLUDED

#include "ArrayList.h"

#include "miscellaneous.h"

class ConvexPolygon // 2D convex polygon
{
public:
    ConvexPolygon();
    ConvexPolygon(ArrayList<Point2D> vertices, int NumOfVertices);
    ~ConvexPolygon();

    bool initialize();
    bool inclusionOfPoint(Point2D& p); // Checks wether the point 'p' exists inside the polygon or not
    Point2D getCentroid();

    void addVertex(Point2D* p);

    void render();

    bool isNeighbor(ConvexPolygon* other);
private:
    void findCentroid();

    ArrayList<Point2D> vertices;
    int NumOfVertices;

    Point2D Centroid;
};

#endif // CONVEXPOLYGON_H_INCLUDED
