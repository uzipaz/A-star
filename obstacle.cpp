#include "obstacle.h"

obstacle::obstacle()
{

}

obstacle::obstacle(Point3D position, GLfloat width, GLfloat length, GLfloat height)
{
    this->position = position;
    this->CollisionMesh = CollisionMesh;

    this->width = width;
    this->length = length;
    this->height = height;

    this->CollisionMesh.x1 = position.x - width/2;
    this->CollisionMesh.y1 = position.y + length/2;

    this->CollisionMesh.x2 = position.x + width/2;
    this->CollisionMesh.y2 = position.y - length/2;
}

obstacle::~obstacle()
{
}

bool obstacle::initialize()
{
    return true;
}

void obstacle::render()
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    //glLoadIdentity();
    glTranslatef(position.x, position.y, position.z);

    GLfloat w = width * 0.5f, l = length * 0.5f, h = height * 0.5f;

    glBegin(GL_QUADS);
        glVertex3f(-w, l, h);     // Top face
        glVertex3f(w, l, h);
        glVertex3f(w, -l, h);
        glVertex3f(-w, -l, h);

        glVertex3f(-w, l, -h);    // Bottom face
        glVertex3f(w, l, -h);
        glVertex3f(w, -l, -h);
        glVertex3f(-w, -l, -h);

        glVertex3f(-w, -l, h);    // Forward face
        glVertex3f(w, -l, h);
        glVertex3f(w, -l, -h);
        glVertex3f(-w, -l, -h);

        glVertex3f(-w, l, h);     // Rear face
        glVertex3f(w, l, h);
        glVertex3f(w, l, -h);
        glVertex3f(-w, l, -h);

        glVertex3f(w, l, h);      // Right face
        glVertex3f(w, l, -h);
        glVertex3f(w, -l, -h);
        glVertex3f(w, -l, h);

        glVertex3f(-w, l, h);     // Left face
        glVertex3f(-w, l, -h);
        glVertex3f(-w, -l, -h);
        glVertex3f(-w, -l, h);
    glEnd();

    glPopMatrix();
}
