#include "GameObjectStore.h"
GameObjectStore* GameObjectStore::instance=0;
GameObjectStore::GameObjectStore()
{
    //ctor
}

GameObjectStore* GameObjectStore::Instance(){
    if(instance == NULL)
        instance = new GameObjectStore();
    return instance;
}

GameObject* GameObjectStore::createObject(const LoaderParams* pParams){
    if(pParams->Type_Id() == "Enemy")
        return new Enemy(pParams);
    else if(pParams->Type_Id() == "Obstacle")
        return new Obstacle(pParams);
}
