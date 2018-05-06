#include "OpenWindow.h"
OpenWindow *OpenWindow::instance = 0;
void OpenWindow::attach(GameUpdate *newGame)
{
    objects.push_back(newGame);
}
void OpenWindow::render()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    OpenWindow::Instance()->draw();
    glutSwapBuffers();
}
void OpenWindow::update(int value)
{
    OpenWindow::Instance()->notify();
    glutTimerFunc(Interval,update,0);
    glutPostRedisplay();
}
void OpenWindow::notify()
{
    for(int i=0; i<objects.size(); i++)
    {
        objects[i]->update();
    }
}
void OpenWindow::view2D()
{
    glViewport(0,0,WIDTH,HEIGHT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0f,WIDTH,0.0f,HEIGHT,0.0f,1.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
void OpenWindow::draw()
{
    for(int i=0; i<objects.size(); i++)
    {
        objects[i]->draw();
    }
}
