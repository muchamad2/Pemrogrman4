#include "Racket.h"
Racket::Racket()
{
    width = 10;
    height = 80;
    speed = 3;
}
void Racket::draw()
{
    glBegin(GL_QUADS);
    glVertex2f(position_x,position_y);
    glVertex2f(position_x+width,position_y);
    glVertex2f(position_x+width,position_y+height);
    glVertex2f(position_x,position_y+height);
    glEnd();
}
void Racket::setPosition(float positionx,float positiony)
{
    position_x = positionx;
    position_y = positiony;
}
void Racket::update(){
    if(selectPlayer == 2){
        if(GetAsyncKeyState(VK_UP)) position_y += speed;
        if(GetAsyncKeyState(VK_DOWN)) position_y -= speed;
    }
    else if(selectPlayer == 1){
        if(GetAsyncKeyState(VK_W)) position_y += speed;
        if(GetAsyncKeyState(VK_S)) position_y -= speed;
    }
}
void Racket::setPlayer(int player){
    selectPlayer = player;
}
