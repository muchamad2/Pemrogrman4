#include "UserInterface.h"
int UserInterface::curScore = 0;
UserInterface::UserInterface(const LoaderParams *pParams) : Object(pParams),m_position(pParams->X(),pParams->Y())
{
    m_width = pParams->Width();
    m_height = pParams->Height();
    _type_id = pParams->Type_Id();
    score=0;
    gameConsUsed = true;
    fontDecide =false;
}
UserInterface::UserInterface(const LoaderParams *pParams,string text):Object(pParams),m_position(pParams->X(),pParams->Y()){
    m_width = pParams->Width();
    m_height = pParams->Height();
    _type_id = pParams->Type_Id();
    score = 0;
    showTxt = text;
    gameConsUsed = true;
    fontDecide = true;
}
UserInterface::UserInterface(const LoaderParams *pParams,string text,void* font):Object(pParams),m_position(pParams->X(),pParams->Y()){
    m_width = pParams->Width();
    m_height = pParams->Height();
    _type_id = pParams->Type_Id();
    score = 0;
    showTxt = text;
    this->font = font;
    gameConsUsed = false;
    fontDecide = true;
}
UserInterface::~UserInterface()
{
    //dtor
}
string int2str(int x){
    stringstream ss;
    ss<<x;
    return ss.str();
}
void UserInterface::draw(){
    if(Game::instance()->state == 0){

    }
    if(Game::instance()->state == 1){
        drawText(showTxt);
    }
    else {
        drawText(showTxt);
        if(!fontDecide){
            glColor3f(1.0f,0.0f,1.0f);
            drawText("Score : "+int2str(score));
        }
        int found = showTxt.find("Highscore");
        if(found != string::npos){
            drawText(showTxt+int2str(curScore));
        }
    }
}
void UserInterface::update(){
    if(Game::instance()->state == 0){
        score += 0.5;
        curScore = score;
    }
}
void UserInterface::drawText(string text){

    glRasterPos2f(m_position.getX(),m_position.getY());
    char *txt = new char[text.length()+1];
    strcpy(txt,text.c_str());
    //int bitmapLengt;
    for(int i=0;i<=text.length();i++){
        if(Game::instance()->state == GAME_ACTIVE || gameConsUsed){
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,txt[i]);
        }
        else
            glutBitmapCharacter(font,txt[i]);
        //bitmapLengt += glutBitmapWidth(GLUT_BITMAP_HELVETICA_18,txt[i]);
    }
   // cout<<bitmapLengt<<endl;
}
