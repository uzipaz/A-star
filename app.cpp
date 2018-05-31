#include "app.h"

app::app()
{
    status_loop = true;

    window = NULL;
    path = NULL;
}

bool app::readLevelData()
{
    ifstream source;
    source.open(ADDRESS_LEVEL_DATA, ios_base::in);

    if (!source)
    {
        cout << "Unable to open file\n";
        return false;
    }

    else
    {
        obstacle* temp; ConvexPolygon* temp2; Point2D* temp3; float* values; int n;
        for(std::string line; std::getline(source, line); )
        {
            std::istringstream in(line);
            std::string type;

            in >> type;

            if (type == "obstacle")
            {
                values = new float[6];
                for (int i = 0; i < 6; i++)
                    in >> values[i];

                temp = new obstacle(Point3D(values[0], values[1], values[2]), values[3], values[4], values[5]);

                myLevel.addObstacle(temp);
                delete [] values;
            }

            else if (type == "navpolygon")
            {
                in >> n;
                temp2 = new ConvexPolygon;

                values = new float[2];
                for (int i = 0; i < n; i++)
                {
                    in >> values[0];
                    in >> values[1];

                    temp3 = new Point2D(values[0], values[1]);
                    temp2->addVertex(temp3);
                }

                temp2->initialize();
                myLevel.addNavMesh(temp2);
                delete [] values;
            }

            else if (type == "screensize")
            {
                in >> n;
                screen_width = n;
                in >> n;
                screen_height = n;
            }

            else if (type == "xylimit")
            {
                values = new float[2];
                in >> values[0];
                in >> values[1];

                xLimit = values[0];
                yLimit = values[1];

                delete [] values;
            }

            else if (type == "camdistance")
            {
                values = new float;
                in >> values[0];
                z = values[0];
                delete values;
            }

            else if (type == "startposition")
            {
                values = new float[2];
                in >> values[0];
                in >> values[1];

                StartPoint.x = values[0];
                StartPoint.y = values[1];

                delete [] values;
            }
        }

        return true;
    }
}

bool app::onInitialize()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
        return false;

    if (readLevelData() == false)
        return false;

    window = SDL_CreateWindow("My OpenGL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screen_width, screen_height, SDL_WINDOW_OPENGL);

    if (window == NULL)
    {
        cout << "Could not create window\n";
        return false;
    }

    glcontext = SDL_GL_CreateContext(window);

//----------------------------------------------------------
    glClearColor(0, 0, 0, 0);

    glViewport(0, 0, screen_width, screen_height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, 1.0, 1.0, 100);

    myLevel.initialize();

    Cursor.x = 0.0f; Cursor.y = 0.0f;

    //StartPoint.x = -9.0f; StartPoint.y = -9.0f;
    FinishPoint.x = 0.0f; FinishPoint.y = 0.0f;

    return true;
}

void drawAxes(GLdouble size)
{
    glBegin(GL_LINES);
        glColor3f(1.0, 0, 0); glVertex3f(0, 0, 0); glVertex3f(size, 0, 0); // X axes
        glColor3f(0, 1.0, 0); glVertex3f(0, 0, 0); glVertex3f(0, size, 0); // Y axes
        glColor3f(0, 0, 1.0); glVertex3f(0, 0, 0); glVertex3f(0, 0, size); // Z axes
    glEnd();
}

void app::onRender()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0, 0, z);

    glPointSize(5);
    glColor3f(1.0, 1.0, 1.0);
    myLevel.render();

    glColor3f(0, 1.0, 0);
    StartPoint.render();

    glColor3f(0, 0, 1.0);
    FinishPoint.render();

    if (path != NULL)
    {
        glColor3f(1.0, 1.0, 1.0);
        Point2D temp;
        stack<Point2D> temp_path = *path;
        while (! temp_path.isEmpty())
        {
            temp = temp_path.pop();
            glBegin(GL_LINE_STRIP);
                glVertex2f(temp.x, temp.y);
        }
        glEnd();
    }

    glFlush();
    SDL_GL_SwapWindow(window);
}

void app::onEvent(SDL_Event event)
{
    switch(event.type)
    {
    case SDL_KEYDOWN:
        switch(event.key.keysym.sym)
        {
        case SDLK_ESCAPE:
            status_loop = false;
            break;

        default:
            break;
        }
        break;

    case SDL_MOUSEBUTTONDOWN:
        Cursor.x = ((xLimit / screen_width) * (event.motion.x)) - (xLimit/2);
        Cursor.y = (((-yLimit) / screen_height) * (event.motion.y)) + (yLimit/2);

        if (event.button.button == SDL_BUTTON_LEFT) {
            FinishPoint = Cursor;
        }

        else if (event.button.button == SDL_BUTTON_RIGHT) {
            StartPoint = Cursor;
        }

        if (path != NULL)
            delete path;

        path = myLevel.getOptimalPath(StartPoint, FinishPoint);

        //cout << "X: " << event.motion.x << " " << "Y: " << event.motion.y << "\n";
        //cout << "Cursor.X: " << Cursor.x << " Cursor.Y: " << Cursor.y << "\n";
        break;

    case SDL_QUIT:
        status_loop = false;
        break;

    default:
        break;
    }
}

void app::onCleanUp()
{
    SDL_GL_DeleteContext(glcontext);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

bool app::onExecute()
{
    if (onInitialize() == false)
        return false;

    while (status_loop == true)
    {
        while (SDL_PollEvent(&event))
            onEvent(event);

        onRender();
    }

    onCleanUp();

    return true;
}

