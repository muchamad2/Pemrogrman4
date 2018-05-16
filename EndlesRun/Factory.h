#ifndef FACTORY_H
#define FACTORY_H
#include <vector>
#include "Obstacle.h"
using namespace std;
class Factory
{
    public:
        static GameObject *getObstacle(string type);
    private:
        static vector<GameObject*> obstacles;
};

#endif // FACTORY_H
