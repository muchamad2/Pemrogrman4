#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "GameObject.h"
class Obstacle : public GameObject
{
    public:
        Obstacle(const LoaderParams* pParams,string id);
        ~Obstacle();
        void draw();
        void update
        Vector2D getPosition(){return m_position;}
        void setPosition(int x,int y){
            m_position.setX(x);
            m_position.setY(y);
        }
    private:
        int width;
        int height;
};

#endif // OBSTACLE_H
