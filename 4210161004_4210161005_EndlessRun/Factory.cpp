#include "Factory.h"
vector<LoaderParams*> Factory::params;

LoaderParams *Factory::getParams(string type)
{
    for(int i=0; i<params.size(); i++)
    {
        if(params[i]->Type_Id() == type)
            return params[i];
    }
    if(type == "Obstacle")
        params.push_back(new LoaderParams(720,0,30,40,type));
    else if(type != "Player")
        params.push_back(new LoaderParams(720,50,40,40,type));
    return params[params.size()-1];
}
void Factory::InitEnemy(float posx,float posy,int width,int height,string type)
{
    params.push_back(new LoaderParams(posx,posy,width,height,type));
}
void Factory::InitObstacle(float posx,float posy,int width,int height,string type)
{
    params.push_back(new LoaderParams(posx,posy,width,height,type));
}

