#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include "Object.h"
#include "Vector2D.h"
#include <string>
#include <iostream>
using namespace std;
class GameObject : public Object
{
public:
    GameObject(const LoaderParams* pParams);
    void draw() {}
    void update();
    Vector2D Position() {}
    int Height() {}
    int Width() {}
    string Type() {}
protected:
    Vector2D m_position;
    Vector2D m_velocity;
    Vector2D m_accel;
    string _id;
};

#endif // GAMEOBJECT_H
