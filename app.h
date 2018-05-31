#ifndef APP_H_INCLUDED
#define APP_H_INCLUDED

#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

#include <SDL2/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>

#include "entity.h"
#include "obstacle.h"
#include "miscellaneous.h"
#include "ConvexPolygon.h"
#include "map.h"

const float SPEED = 0.1f;
const char ADDRESS_LEVEL_DATA[] = "data.txt";

class app
{
public:
    app();
    bool onExecute();

private:
    bool onInitialize();
    void onEvent(SDL_Event event);
    void onRender();
    void onCleanUp();
    bool readLevelData();

    bool status_loop;

    SDL_Window *window;
    SDL_Event event;
    SDL_GLContext glcontext;

    Point2D StartPoint;
    Point2D FinishPoint;

    Point2D Cursor;

    int screen_width;
    int screen_height;
    float xLimit;
    float yLimit;
    float z;

    map myLevel;

    stack<Point2D>* path;
};


#endif // APP_H_INCLUDED
