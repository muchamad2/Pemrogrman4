#include "HandleInput.h"
HandleInput *HandleInput::sInstance = 0;

void HandleInput::keySpecial(int key,int x,int y)
{
    HandleInput::Instance()->keySpecialState[key] = true;
}
void HandleInput::keySpecialUp(int key,int x,int y)
{
    HandleInput::Instance()->keySpecialState[key] = false;
}
void HandleInput::keyboardKey(unsigned char key,int x,int y)
{
    HandleInput::Instance()->keyStates[key] = true;
}
void HandleInput::keyboardKeyUp(unsigned char key,int x,int y)
{
    HandleInput::Instance()->keyStates[key] = false;
}
