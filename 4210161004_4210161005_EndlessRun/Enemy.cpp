#include "Enemy.h"

Enemy::Enemy(const LoaderParams *pParams) : GameObject(pParams)
{
    m_width = pParams->Width();
    m_height = pParams->Height();
    random = rand()%5+5;
}
Enemy::Enemy(const LoaderParams *pParams,int position) : GameObject(pParams)
{
    m_width = pParams->Width();
    m_height = pParams->Height();
    m_position.setY(position);
    random = rand()%5+5;
}

Enemy::~Enemy()
{
    //dtor
}
void Enemy::draw()
{
    glBegin(GL_QUADS);
    glColor3f(1.0f,0.0f,0.0f);
    glVertex2f(m_position.getX(),m_position.getY());
    glVertex2f(m_position.getX()+m_width,m_position.getY());
    glVertex2f(m_position.getX()+m_width,m_position.getY()+m_height);
    glVertex2f(m_position.getX(),m_position.getY()+m_height);
    glEnd();
}
void Enemy::update()
{
    GameObject::update();

    m_velocity.setX(random*-1);
}
