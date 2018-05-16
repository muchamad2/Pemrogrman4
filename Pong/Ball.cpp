#include "Ball.h"

Ball::Ball()
{
    ballSize = 8;
    pos_x = WIDTH / 2 - ballSize/2;
    pos_y = HEIGHT / 2 - ballSize/2;
    dir_x = -1.0f;
    dir_y = 0.0f;
    speed = 4;
    curPlayer = 1;
    isGoal = false;
}
void Ball::draw()
{
    glBegin(GL_QUADS);
    glVertex2f(pos_x,pos_y);
    glVertex2f(pos_x+ballSize,pos_y);
    glVertex2f(pos_x+ballSize,pos_y+ballSize);
    glVertex2f(pos_x,pos_y+ballSize);
    glEnd();
}
void Ball::update()
{
    //movement ball
    pos_x += dir_x * speed;
    pos_y += dir_y * speed;
    //colision
    //hit left racket
    if(pos_x < P1->getPositionX()+P1->getWidth() && pos_x > P1->getPositionX() &&
            pos_y < P1->getPositionY()+P1->getHeight() && pos_y > P1->getPositionY())
    {
        //set fly direction depending on where it hit the racket
        //0.5 if hit the top, 0 in center, -0.5 in bottom
        float newDirY = ((pos_y - P1->getPositionY())/P1->getHeight())-0.5f;
        dir_x = fabs(dir_x);
        dir_y = newDirY;
    }
    //hit right racket
    else if(pos_x > P2->getPositionX()&&pos_x < P2->getPositionX() + P2->getWidth() &&
            pos_y < P2->getPositionY()+P2->getHeight() && pos_y > P2->getPositionY())
    {
        float newDirY = ((pos_y - P2->getPositionY())/P2->getHeight()) - 0.5f;
        dir_x = -fabs(dir_x);
        dir_y = newDirY;
    }
    //hit left wall
    if(pos_x < 0)
    {
        //++score_right;
        curPlayer = 2;
        isGoal = true;
        pos_x = WIDTH/2;
        pos_y = HEIGHT/2;
        dir_x = fabs(dir_x);
        dir_y = 0;
    }
    //hit figt wall
    else if(pos_x > WIDTH)
    {
        //++score_left;
        curPlayer = 1;
        isGoal = true;
        pos_x = WIDTH/2;
        pos_y = HEIGHT/2;
        dir_x = -fabs(dir_x);
        dir_y = 0;
    }
    //hit top wall
    else if(pos_y > HEIGHT-5)
    {
        dir_y = -fabs(dir_y);
    }
    //hit bottom wall
    else if(pos_y < 0)
    {
        dir_y = fabs(dir_y);
    }
    vec2norm(dir_x,dir_y);
}
void Ball::setPlayer(Racket *p1,Racket *p2)
{
    this->P1 = p1;
    this->P2 = p2;
}

