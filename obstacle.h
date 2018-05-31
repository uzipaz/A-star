#ifndef OBSTACLE_H_INCLUDED
#define OBSTACLE_H_INCLUDED

#include "entity.h"

class obstacle: public entity
{
public:
    obstacle();
    obstacle(Point3D position, GLfloat width, GLfloat length, GLfloat height);
    ~obstacle();

    void render();
    bool initialize();

private:
    GLfloat height;
    GLfloat width;
    GLfloat length;
};

#endif // OBSTACLE_H_INCLUDED
