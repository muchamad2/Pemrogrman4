#ifndef PLAYER_H
#define PLAYER_H
#include "HandleInput.h"
#include "GameObject.h"
#include "Vector2D.h"

class Player : public GameObject//, public HandleInput
{
public:
    Player(const LoaderParams* pParams);
    ~Player();
    void draw();
    void update();
    Vector2D Position()
    {
        return m_position;
    }
    int Height()
    {
        return m_height;
    }
    int Width()
    {
        return m_width;
    }
    string Type()
    {
        return _id;
    }
private:
    float speed;
    int m_height;
    int m_width;
    bool isJump;
    bool isMove;
};

#endif // PLAYER_H
