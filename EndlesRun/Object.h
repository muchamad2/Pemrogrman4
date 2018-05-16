#ifndef OBJECT_H_INCLUDED
#define OBJECT_H_INCLUDED
#include "LoaderParams.h"
#include <windows.h>
#include <GL/glut.h>
class Object{
public:
    virtual void draw() = 0;
    virtual void update() = 0;
protected:
    Object(const LoaderParams *pParams){}
};


#endif // OBJECT_H_INCLUDED
