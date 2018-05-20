#ifndef OBJECT_H_INCLUDED
#define OBJECT_H_INCLUDED
#include "LoaderParams.h"
#include <windows.h>
#include <GL/glut.h>
#include "Vector2D.h"
#include <string>
class Object
{
public:
    virtual void draw() = 0;
    virtual void update() = 0;
    virtual Vector2D Position() = 0;
    virtual int Width() = 0;
    virtual int Height() = 0;
    virtual string Type() = 0;
protected:
    Object(const LoaderParams *pParams) {}
};


#endif // OBJECT_H_INCLUDED
