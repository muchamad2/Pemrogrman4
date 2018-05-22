#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "GameObject.h"
class Obstacle : public GameObject
{
public:
    Obstacle(const LoaderParams* pParams);
    virtual ~Obstacle();
    void draw();
    void update();
    Vector2D Position(){return m_position;}
    void setPosition(int x,int y)
    {
        m_position.setX(x);
        m_position.setY(y);
    }
    int Width(){return width;}
    int Height(){return height;}
    string Type(){return _id;}
private:
    int width;
    int height;
};

#endif // OBSTACLE_H
