#ifndef GAMEOBJECTSTORE_H
#define GAMEOBJECTSTORE_H

#include "GameObject.h"
#include "Enemy.h"
#include "Obstacle.h"
#include "LoaderParams.h"
class GameObjectStore
{
    public:
        static GameObjectStore *Instance();
        GameObject* createObject(const LoaderParams*);
    private:
        GameObjectStore();
        static GameObjectStore *instance;
};
typedef GameObjectStore Storage;
#endif // GAMEOBJECTSTORE_H
