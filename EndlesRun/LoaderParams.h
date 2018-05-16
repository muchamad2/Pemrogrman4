#ifndef LOADERPARAMS_H_INCLUDED
#define LOADERPARAMS_H_INCLUDED
using namespace std;
class LoaderParams{
public:
    LoaderParams(float x,float y,int width,int height):m_x(x),m_y(y),m_width(width),m_height(height){}
    float X()const{return m_x;}
    float Y()const{return m_y;}
    int Width()const{return m_width;}
    int Height()const{return m_height;}
private:
    float m_x;
    float m_y;
    int m_width;
    int m_height;

};

#endif // LOADERPARAMS_H_INCLUDED
