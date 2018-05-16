#include <windows.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <iostream>
#include "Game.h"
#include "HandleInput.h"
using namespace std;

int main(int argc,char* argv[])
{
    Game::instance()->init();
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE|GLUT_DEPTH);
    glutInitWindowPosition(50,50);
    glutInitWindowSize(720,320);
    glutCreateWindow("Endless Run");
    glutDisplayFunc(Game::display);
    glutTimerFunc(Interval,Game::update,0);
    glutReshapeFunc(Game::view2D);
    glutSpecialFunc(HandleInput::keySpecial);
    glutSpecialUpFunc(HandleInput::keySpecialUp);

    glClearColor(0.0f,0.0f,0.0f,1.0f);
    glutMainLoop();
    return EXIT_SUCCESS;
}
