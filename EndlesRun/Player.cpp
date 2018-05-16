#include "Player.h"
#include "Game.h"
Player::Player(const LoaderParams *pParams,string id) : GameObject(pParams,id)
{
    speed =10;
    height = pParams->Height();
    width = pParams->Width();
    isJump = false;
}

Player::~Player()
{
    //dtor
}

void Player::draw(){
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,1.0f);
    glVertex2f(m_position.getX(),m_position.getY());
    glVertex2f(m_position.getX()+width,m_position.getY());
    glVertex2f(m_position.getX()+width,m_position.getY()+height);
    glVertex2f(m_position.getX(),m_position.getY()+height);
    glEnd();
}
void Player::update(){
    GameObject::update();
    m_accel.setY(-98 * Game::instance()->deltaTime());
    m_accel.setX(-90 * Game::instance()->deltaTime());
    if(m_position.getY() <= 1){
        m_position.setY(0);
        isJump = false;
    }
    if(m_position.getX() <= 1)
    {
        m_position.setX(0);
        isMove = false;
    }
    if(HandleInput::Instance()->keySpecialState[GLUT_KEY_UP] && !isJump){
        m_velocity.setY(20);
        isJump = true;
    }
    if(HandleInput::Instance()->keySpecialState[GLUT_KEY_RIGHT] && !isMove){
        m_velocity.setX(speed);
        isMove = true;
    }
    else{
        m_velocity.setX(0);
        isMove = false;
    }
    //m_velocity.setX(1*speed);
}
