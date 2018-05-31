#ifndef ENTITY_H_INCLUDED
#define ENTITY_H_INCLUDED

#include "miscellaneous.h"

class entity
{
public:
    virtual bool initialize() { return true;}
    virtual void render() =0;
    virtual ~entity() {}

    void setPosition(Point3D p);
    Point3D getPosition();

    void setCollisionMesh(Rectangle r);
    Rectangle getCollisionMesh();

    bool doesCollide(entity* e);


protected:
    Point3D position; // A 3D point representing the position of the centre of object in the world
    Rectangle CollisionMesh;
};

#endif // ENTITY_H_INCLUDED
