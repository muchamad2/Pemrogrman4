#ifndef GAMEUPDATE_H_INCLUDED
#define GAMEUPDATE_H_INCLUDED

#define WIDTH 500
#define HEIGHT 200

#include <windows.h>
#include <GL/glut.h>
#include <iostream>
#include <cmath>
#include <cstring>
#include <sstream>
using namespace std;

class GameUpdate
{
public:
    virtual void draw() = 0;
    virtual void update() = 0;
};


#endif // GAMEUPDATE_H_INCLUDED
