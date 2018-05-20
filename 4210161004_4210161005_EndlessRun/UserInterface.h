#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include "Object.h"
#include "Vector2D.h"
#include "string"
#include <sstream>
#include "Game.h"
class UserInterface : public Object
{
    public:
        UserInterface(const LoaderParams *pParams);
        UserInterface(const LoaderParams *pParams,string text);
        UserInterface(const LoaderParams *pParams,string text,void*font);
        ~UserInterface();
        //virtual fungsi
        void draw();
        void update();
        Vector2D Position(){return m_position;}
        int Height(){return m_height;}
        int Width(){return m_width;}
        string Type(){return _type_id;}
        //fungsi untuk membuat text dalam game
        void drawText(string text);
    private:
        float score;
        static int curScore;
        string _type_id;
        string showTxt;
        int m_height;
        int m_width;
        void *font;
        bool gameConsUsed;
        bool fontDecide;
        Vector2D m_position;
};

#endif // USERINTERFACE_H
