#ifndef GAME_H
#define GAME_H
#define Interval 1000/60
#include <windows.h>
#include <GL/glut.h>
#include <vector>
#include <iostream>
#include "Player.h"
#include "Factory.h"
#include "Obstacle.h"

using namespace std;
class Game
{
public:
    void init();
    static void display();
    static void update(int value);
    static Game *instance()
    {
        if(!s_instance)
            s_instance = new Game;
        return s_instance;
    }
    static void view2D(int width,int height);
    void render();
    void gameUpdate();
    float deltaTime(){return dt;}
    void Time();
    void spawnEnemy();
    void popBack(){objects.pop_back();}
private:
    Game();
    float dt;
    float timer;
    int old_t;
    float timerLimit;
    static Game *s_instance;
    vector<Object*> objects;
};
#endif // GAME_H
