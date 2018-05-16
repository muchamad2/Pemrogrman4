#include "GameObject.h"

GameObject::GameObject(const LoaderParams* pParams,string id) : Object(pParams),m_position(pParams->X(),pParams->Y()),m_velocity(0,0),m_accel(0,0)
{
    type_id = id;
}
void GameObject::update(){
    m_velocity += m_accel;
    m_position += m_velocity;
}
