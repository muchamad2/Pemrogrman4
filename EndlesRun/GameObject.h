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
        GameObject(const LoaderParams* pParams,string id);
        void draw(){}
        void update();
        string getType(){return type_id;}
    protected:
        Vector2D m_position;
        Vector2D m_velocity;
        Vector2D m_accel;
        string type_id;
};

#endif // GAMEOBJECT_H
