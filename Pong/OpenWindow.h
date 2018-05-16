#ifndef OPENWINDOW_H_INCLUDED
#define OPENWINDOW_H_INCLUDED
#include "GameUpdate.h"

#define Interval 1000/60
#include <vector>
class OpenWindow
{
    //store all object that inherite gameupdate
    vector<GameUpdate*> objects;
public:
    void attach(GameUpdate*);
    //static function for opengl function
    static void render();
    static void update(int value);
    //to make singleton of openwindow to be able be call in static function of opengl function
    static OpenWindow *Instance()
    {
        if(!instance)
            instance = new OpenWindow;
        return instance;
    }
    //function that will give update for object that attach to this class
    void draw();
    void notify();
    //function that will give view point of windows opengl
    void view2D();
protected:
    static OpenWindow *instance;
};
//static OpenWindow *newwindow;
#endif // OPENWINDOW_H_INCLUDED
