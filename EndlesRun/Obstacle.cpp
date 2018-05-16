#include "Obstacle.h"
#include "Game.h"
Obstacle::Obstacle(const LoaderParams *pParams,string id) : GameObject(pParams,id)
{
    //ctor
    height = pParams->Height();
    width = pParams->Width();
}

Obstacle::~Obstacle()
{
        cout<<"delete";
}

void Obstacle::draw(){
    glBegin(GL_TRIANGLES);
    glVertex2f(m_position.getX(),m_position.getY());
    glColor3f(1.0f,1.0f,0.0f);
    glVertex2f(m_position.getX()+width/2,m_position.getY()+height);
    glVertex2f(m_position.getX()+width,m_position.getY());
    glEnd();
}
void Obstacle::update(){
    GameObject::update();
    m_velocity.setX(-1);
}
