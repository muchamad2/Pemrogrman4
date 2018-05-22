#ifndef ENEMY_H
#define ENEMY_H

#include "GameObject.h"


class Enemy : public GameObject
{
public:
    Enemy(const LoaderParams *pParams);
    Enemy(const LoaderParams *pParams,int position);
    virtual ~Enemy();
    void draw();
    void update();
    Vector2D Position()
    {
        return m_position;
    }
    int Width()
    {
        return m_width;
    }
    int Height()
    {
        return m_height;
    }
    string Type()
    {
        return _id;
    }
private:
    int m_width;
    int m_height;
    int random;
};

#endif // ENEMY_H
