#ifndef FACTORY_H
#define FACTORY_H
#include <vector>
#include <ctime>
#include "LoaderParams.h"
using namespace std;
class Factory
{
public:
    static LoaderParams *getParams(string type);
    static void InitEnemy(float posx,float posy,int width,int height,string type);
    static void InitObstacle(float posx,float posy,int width,int height,string type);
private:
    static vector<LoaderParams*> params;
};

#endif // FACTORY_H
