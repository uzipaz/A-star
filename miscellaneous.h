#ifndef MISCELLANEOUS_H_INCLUDED
#define MISCELLANEOUS_H_INCLUDED

#include <GL/gl.h>
#include <GL/glu.h>
#include <cmath>

const GLfloat EQUALITY_THRESHOLD = 0.0001;

struct Point3D
{
    GLfloat x;
    GLfloat y;
    GLfloat z;

    Point3D()
    {
        x = 0; y = 0; z = 0;
    }

    Point3D(GLfloat x, GLfloat y, GLfloat z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }
};

struct Point2D
{
    GLfloat x;
    GLfloat y;

    Point2D()
    {
        x = 0.0f; y = 0.0f;
    }

    Point2D(GLfloat x, GLfloat y)
    {
        this->x = x;
        this->y = y;
    }

    bool isEqual(Point2D other)
    {
        if ( (unsigned(this->x - other.x) < EQUALITY_THRESHOLD)
            && (unsigned(this->y - other.y) < EQUALITY_THRESHOLD) )
        {
            return true;
        }

        return false;
    }

    void render()
    {
        glBegin(GL_POINTS);
            glVertex2f(x, y);
        glEnd();
    }
};

struct Rectangle
{
    GLfloat x1, y1; // Top Left Corner
    GLfloat x2, y2; // Top Right Corner

    Rectangle()
    {
    }

    Rectangle(Point2D a, Point2D b)
    {
        x1 = a.x;
        y1 = a.y;

        x2 = b.x;
        y2 = b.y;
    }

    GLfloat getArea()
    {
        return (x1 - x2) * (y1 - y2);
    }

    bool doesCollide(Rectangle& other_rect)
    {
        if (this->x1 < other_rect.x2 && this->x2 > other_rect.x1 && this->y1 < other_rect.y2 && this->y2 > other_rect.y1)
            return true;

        return false;
    }
};

template <typename T>
void swap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

/*GLfloat calculateEuclideanDistance(int x1, int y1, int x2, int y2)
{
    return (GLfloat)(sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2)));
}*/
#endif // MISCELLANEOUS_H_INCLUDED
