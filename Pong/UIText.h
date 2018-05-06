#ifndef UITEXT_H_INCLUDED
#define UITEXT_H_INCLUDED
#include "Ball.h"
#include "GameUpdate.h"
class UIText : public GameUpdate
{
    int score_left;
    int score_right;
    float pos_x;
    float pos_y;
    string text;
    Ball *curBall;
public:
    //constructor
    UIText();
    //function inherit from gameupdate
    void draw();
    void update();
    //untuk mendapatkan data ball yang berhubungan dengan bola dari player mana yang masuk
    void setBall(Ball *cur);
    //untuk menampilkan tulisan dari score yang masuk
    void drawText(string);
};


#endif // UITEXT_H_INCLUDED
