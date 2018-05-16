#ifndef PLAYER_H
#define PLAYER_H
#include "HandleInput.h"
#include "GameObject.h"
#include "Vector2D.h"

class Player : public GameObject//, public HandleInput
{
    public:
        Player(const LoaderParams* pParams,string id);
        ~Player();
        void draw();
        void update();
        Vector2D getPosition(){return m_position;}
    private:
        float speed;
        int height;
        int width;
        bool isJump;
        bool isMove;
};

#endif // PLAYER_H
