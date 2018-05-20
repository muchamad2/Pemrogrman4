#include "Obstacle.h"
#include "Game.h"
Obstacle::Obstacle(const LoaderParams *pParams) : GameObject(pParams)
{
    //ctor
    height = pParams->Height();
    width = pParams->Width();
}

Obstacle::~Obstacle()
{
    //cout<<"delete";
}

void Obstacle::draw()
{
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f,1.0f,0.0f);
    glVertex2f(m_position.getX(),m_position.getY());
    glVertex2f(m_position.getX(),m_position.getY()+height);
    glVertex2f(m_position.getX()+width,m_position.getY());
    glEnd();
}
void Obstacle::update()
{
    GameObject::update();
    m_velocity.setX(-3);
}
