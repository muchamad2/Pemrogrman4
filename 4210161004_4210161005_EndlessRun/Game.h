#ifndef GAME_H
#define GAME_H
#define Interval 1000/60
#include <windows.h>
#include <GL/glut.h>
#include <vector>
#include <iostream>
#include <cstring>
#include "Player.h"
#include "Factory.h"
#include "Obstacle.h"
#include "LoaderParams.h"
#include "Enemy.h"
#include "UserInterface.h"
#include "HandleInput.h"
#include "GameObjectStore.h"
#define HEIGHT 220
#define WIDTH 720
using namespace std;
enum GameState
{
    GAME_ACTIVE,
    GAME_MENU,
    GAME_WIN
};
class Game
{
public:
    //game state->pergantian scene game
    GameState state;
    //initialiasi game
    void init();
    //fungsi untuk display dan update game
    static void display();
    static void update(int value);
    static Game *instance()
    {
        if(!s_instance)
            s_instance = new Game;
        return s_instance;
    }
    //fungsi titik fokus posisi x dan y dalam window game
    static void view2D(int width,int height);
    //fungsi render dan update untuk metod(funsi) game
    void render();
    void gameUpdate();
    float deltaTime()
    {
        return dt;
    }
    //fungsi pembuatan deltatime
    void Time();
    //fungsi untuk spawning
    void spawnEnemy();
    void spawnObstacle();
    //untuk menciptakan kondisi menang
    void windisplay(string,void*font);
    //fungsi pengecekan colision
    bool checkCollision(Object* player,Object* otherObject);
private:
    Game();
    float dt;
    float timerEnemy;
    float timerObstacle;
    int old_t;
    float timerLimit;
    static Game *s_instance;
    vector<Object*> objects;
    vector<Object*> menu;
};
#endif // GAME_H
