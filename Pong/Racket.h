#ifndef RACKET_H_INCLUDED
#define RACKET_H_INCLUDED
#include "GameUpdate.h"
#define VK_W 0x57
#define VK_S 0x53
class Racket : public GameUpdate
{
    int width;
    int height;
    int speed;
    int selectPlayer;
    float position_x;
    float position_y;
public:
    //constructor
    Racket();
    //inherit from game update
    void draw();
    void update();
    //fungsi yang digunakan untuk menentukan posisi player (racket)
    void setPosition(float positionx,float positiony);
    //menentukan player (racket) yang sedang berjalan
    void setPlayer(int);
    //fungsi yang akan digunakan untuk medapatkan data dari racket(player) untuk collision
    float getPositionX()
    {
        return position_x;
    }
    float getPositionY()
    {
        return position_y;
    }
    int getWidth()
    {
        return width;
    }
    int getHeight()
    {
        return height;
    }
};


#endif // RACKET_H_INCLUDED
