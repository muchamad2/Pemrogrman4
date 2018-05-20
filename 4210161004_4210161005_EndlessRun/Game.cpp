#include "Game.h"
#include "HandleInput.h"
Game *Game::s_instance = 0;
Game::Game() {}
void Game::windisplay(string menuTxt,void *font){
    int total = 0;
    char *txt = new char[menuTxt.length()+1];
    strcpy(txt,menuTxt.c_str());
    for(int i=0;i<=menuTxt.length();i++){
        total += glutBitmapWidth(font,txt[i]);
    }
    if(menuTxt.find("Highscore")!= string::npos){
        menu.push_back(new UserInterface(new LoaderParams(WIDTH/2-total/2,HEIGHT/2+10,20,20,"UserInterface"),menuTxt,font));
    }
    else
        menu.push_back(new UserInterface(new LoaderParams(WIDTH/2-total/2,HEIGHT/2-10,20,20,"UserInterface"),menuTxt,font));

}
void Game::init()
{
    objects.push_back(new Player(new LoaderParams(10,0,20,40,"Player")));
    objects.push_back(new UserInterface(new LoaderParams(20,HEIGHT - 20,20,30,"UserInterface")));
    string menuTxt = "Press ENTER to Start, ESC to Quit";
    menu.push_back(new UserInterface(new LoaderParams(WIDTH/2-143,HEIGHT/2,20,20,"UserInterface"),menuTxt));
    menuTxt = "Tekan RIGHT_ARROW or LEFT_ARROW to Move and UP_ARROW to jump";
    menu.push_back(new UserInterface(new LoaderParams(WIDTH/2-247,HEIGHT/2-20,20,20,"UserInterface"),menuTxt,GLUT_BITMAP_9_BY_15));
    old_t = glutGet(GLUT_ELAPSED_TIME);
    Factory::InitEnemy(720,51,40,40,"Enemy");
    Factory::InitObstacle(720,0,30,40,"Obstacle");
    timerLimit = 3;
    timerEnemy = 0;
    timerObstacle = 1;
    state = GAME_MENU;
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
void Game::render()
{
    if(state == GAME_ACTIVE)
    {
        for(int i=0; i<objects.size(); i++)
        {
            objects[i]->draw();
        }
    }
    else if(state == GAME_MENU)
    {
        for(int i=0; i<menu.size(); i++)
        {
            menu[i]->draw();
        }
    }
    else if(state == GAME_WIN){
        for(int i=0;i<menu.size();i++){
            menu[i]->draw();
        }
        for(int i=0;i<objects.size();i++){
            objects[i]->draw();
        }
    }
//    Factory::getObstacle(0)->draw();
}
int randomtimer(){
    int timerlimiter = rand()%10 + 1;
    return timerlimiter;
}
void Game::spawnEnemy()
{
    timerEnemy += deltaTime();
    if(timerEnemy>randomtimer())
    {
        LoaderParams *params2 = Factory::getParams("Enemy");
        Enemy *obj = new Enemy(params2);
        objects.push_back(obj);
        timerEnemy = 0;
    }
}
void Game::spawnObstacle(){
    timerObstacle += deltaTime();
    if(timerObstacle > timerLimit){
        LoaderParams *params = Factory::getParams("Obstacle");
        Obstacle *newObj = new Obstacle(params);
        objects.push_back(newObj);
        timerObstacle = 0;
    }
}
void Game::Time()
{
    int t;
    t = glutGet(GLUT_ELAPSED_TIME);
    dt = (t-old_t) / 1000.0;
    old_t = t;
}
void Game::gameUpdate()
{
    if(this->state == GAME_ACTIVE)
    {
        for(int i = 0; i<objects.size(); i++)
        {
            objects[i]->update();
            if(objects[i]->Type() != "Player" )
            {
                if(objects[i]->Type() != "UserInterface")
                {
                    if(checkCollision(objects[0],objects[i])){
                        state = GAME_WIN;
                        menu.clear();
                        windisplay("Highscore : ",GLUT_BITMAP_HELVETICA_12);
                        windisplay("Press Enter to Retry, ESC to Quit",GLUT_BITMAP_9_BY_15);
                    }

                }
            }
            if(objects[i]->Type() != "Player")
            {
                if(objects[i]->Position().getX() < -2)
                {
                    cout<<"delete\n"<<objects[i]->Type();
                    objects.erase(objects.begin()+i);
                }
            }
        }
        spawnEnemy();
        spawnObstacle();
    }
    else if(this->state == GAME_MENU){
        if(HandleInput::Instance()->keyStates[13])
            state = GAME_ACTIVE;
        else if(HandleInput::Instance()->keyStates[27])
            exit(0);
    }
    else if(this->state == GAME_WIN){
        if(HandleInput::Instance()->keyStates[13]){
            objects.clear();
            menu.clear();
            Game::instance()->init();
            state = GAME_ACTIVE;
        }
        else if(HandleInput::Instance()->keyStates[27])
            exit(0);
    }
//    Factory::getObstacle(0)->update();
}
bool Game::checkCollision(Object* player,Object* other)
{
    bool collisionX = player->Position().getX() + player->Width() >= other->Position().getX() &&
                      other->Position().getX() + other->Width() >= player->Position().getX();
    bool collisionY = player->Position().getY() + player->Height() >= other->Position().getY() &&
                      other->Position().getY() + other->Height() >= player->Position().getY();

    return collisionX && collisionY;
}
