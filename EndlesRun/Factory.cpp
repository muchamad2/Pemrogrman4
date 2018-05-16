#include "Factory.h"
vector<GameObject*> Factory::obstacles;

GameObject *Factory::getObstacle(string type){
    if(!obstacles.empty()){
        for(int i=0;i< obstacles.size();i++){
            if(obstacles[i]->getType() == type){
                obstacles.erase(obstacles.begin()+i);
                obstacles.insert(obstacles.begin()+i,new Obstacle(new LoaderParams(720,0,20,40),type));
                return obstacles[i];
            }
        }
        obstacles.push_back(new Obstacle(new LoaderParams(720,0,50,20),type));
        return obstacles[obstacles.size()-1];
    }
    else
    {
        obstacles.push_back(new Obstacle(new LoaderParams(720,0,40,20),type));
        return obstacles[obstacles.size()-1];
    }
}
