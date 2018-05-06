#ifndef BALL_H_INCLUDED
#define BALL_H_INCLUDED
#include "GameUpdate.h"
#include "Racket.h"
class Ball : public GameUpdate
{
    int ballSize;
    int speed;
    int curPlayer;
    bool isGoal;
    Racket *P1,*P2;
    float pos_x;
    float pos_y;
    float dir_x;
    float dir_y;
public:
    //constructor
    Ball();
    //inherit from gameupdate
    void draw();
    void update();
    //fungsi yang digunakan untuk memperoleh data dari player untuk collision
    void setPlayer(Racket *p1,Racket *p2);
    //function that use for normilize direction ball
    void vec2norm(float& x,float &y)
    {
        float length = sqrt((x*x)+(y*y));
        if(length != 0.0f)
        {
            length = 1.0f/length;
            y*= length;
            x*= length;
        }
    }
    //fungsi untuk memberitahu player yang memasukkan bola
    int getPlayer(){return curPlayer;}
    //function for check condition in goal or not
    bool IsGoal(){return isGoal;}
    void setGoal(){isGoal = false;}
};

#endif // BALL_H_INCLUDED
