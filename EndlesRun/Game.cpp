#include "Game.h"
#include "HandleInput.h"
Game *Game::s_instance = 0;
Game::Game() {}
void Game::init()
{
    objects.push_back(new Player(new LoaderParams(10,0,20,40),"Player"));
    old_t = glutGet(GLUT_ELAPSED_TIME);
    timerLimit = 5;
}
void Game::display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    Game::instance()->render();
    glutSwapBuffers();
}
void Game::update(int value)
{
    Game::instance()->gameUpdate();
    Game::instance()->Time();
    Game::instance()->spawnEnemy();
    glutTimerFunc(Interval,update,0);
    glutPostRedisplay();
}
void Game::view2D(int width,int height)
{
    glViewport(0,0,width,height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0f,width,0.0f,height,0.0f,1.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
void Game::render(){
    for(int i=0;i<objects.size();i++){
        objects[i]->draw();
    }
//    Factory::getObstacle(0)->draw();
}
void Game::spawnEnemy(){
    int i = 0;
    timer += deltaTime();
    if(timer > timerLimit){
        GameObject *newObstacle = Factory::getObstacle("Obstacle");
        timer = 0;
        i++;
        cout<<"Spawn"<<endl;
        objects.push_back(newObstacle);
    }
}
void Game::Time(){
    int t;
    t = glutGet(GLUT_ELAPSED_TIME);
    dt = (t-old_t) / 1000.0;
    old_t = t;
}
void Game::gameUpdate(){
    for(int i = 0;i<objects.size();i++){
        objects[i]->update();
    }
//    Factory::getObstacle(0)->update();
}
