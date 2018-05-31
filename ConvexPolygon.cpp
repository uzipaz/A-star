#include "ConvexPolygon.h"

ConvexPolygon::ConvexPolygon()
{
    NumOfVertices = 0;
}

ConvexPolygon::ConvexPolygon(ArrayList<Point2D> vertices, int NumOfVertices)
{
    this->vertices = vertices;
    this->NumOfVertices = NumOfVertices;

    this->findCentroid();
}

ConvexPolygon::~ConvexPolygon()
{

}

bool ConvexPolygon::initialize()
{
    this->findCentroid();
    return true;
}

void ConvexPolygon::addVertex(Point2D* p)
{
    vertices[NumOfVertices++] = *p;
}

Point2D ConvexPolygon::getCentroid()
{
    return Centroid;
}

void ConvexPolygon::render()
{
    int i;
    glBegin(GL_LINE_LOOP);
        for(i = 0; i < NumOfVertices; i++)
            glVertex2f(vertices[i].x, vertices[i].y);
    glEnd();

    Centroid.render();
}

bool ConvexPolygon::inclusionOfPoint(Point2D& p)
{
    int i, j;
    bool result = false;

    for (i = 0, j = NumOfVertices-1; i < NumOfVertices; j = i++) {
    if ( ((vertices[i].y>p.y) != (vertices[j].y>p.y)) &&
	 (p.x < (vertices[j].x-vertices[i].x) * (p.y-vertices[i].y) / (vertices[j].y-vertices[i].y) + vertices[i].x) )
       result = !result;
  }
  return result;
}

bool ConvexPolygon::isNeighbor(ConvexPolygon* other)
{
    int i, j;

    int NumOfEquals = 0;

    bool found, done = false;
    for (i = 0; i < this->NumOfVertices && !done; i++)
    {
        found = false;
        for (j = 0; j < other->NumOfVertices && !found; j++)
        {
            if (this->vertices[i].isEqual(other->vertices[j]))
            {
                NumOfEquals++;
                found = true;
            }
        }

        if (NumOfEquals > 1)
            done = true;
    }

    return done;
}

void ConvexPolygon::findCentroid()
{
    GLdouble SumOfX = 0.0d, SumOfY = 0.0d;

    int i;
    for (i = 0; i < NumOfVertices; i++)
    {
        SumOfX = SumOfX + vertices[i].x;
        SumOfY = SumOfY + vertices[i].y;
    }

    Centroid.x = SumOfX / NumOfVertices;
    Centroid.y = SumOfY / NumOfVertices;
}

