#include "entity.h"

void entity::setPosition(Point3D p)
{
    this->position = p;
}

void entity::setCollisionMesh(Rectangle r)
{
    this->CollisionMesh = r;
}

Point3D entity::getPosition()
{
    return position;
}

Rectangle entity::getCollisionMesh()
{
    return CollisionMesh;
}

bool entity::doesCollide(entity* e)
{
    return CollisionMesh.doesCollide(e->CollisionMesh);
}

/*virtual bool entity::initialize() {}
virtual void entity::render() {}
virtual entity::~entity() {}*/


