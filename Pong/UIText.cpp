#include "UIText.h"

string int2str(int x){
    stringstream ss;
    ss<<x;
    return ss.str();
}
void UIText::setBall(Ball*curball){
    curBall = curball;
}
UIText::UIText(){
    pos_x = WIDTH/2-10;
    pos_y = HEIGHT-15;
    score_left = 0;
    score_right = 0;
}
void UIText::draw()
{
    drawText(int2str(score_left)+" : "+int2str(score_right));
}
void UIText::update(){
    if(curBall->getPlayer() == 1 && curBall->IsGoal()){
        ++score_left;
        curBall->setGoal();
    }else if(curBall->getPlayer() == 2 && curBall->IsGoal()){
        ++score_right;
        curBall->setGoal();
    }
}
void UIText::drawText(string text){
    glRasterPos2f(pos_x,pos_y);
    char *txt = new char[text.length()+1];
    strcpy(txt,text.c_str());
    for(int count = 0;count <= text.length();count++){
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13,txt[count]);
    }
}
