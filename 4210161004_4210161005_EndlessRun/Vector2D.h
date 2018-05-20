#ifndef VECTOR2D_H
#define VECTOR2D_H
#include <cmath>

using namespace std;
class Vector2D
{
public:
    Vector2D(float x,float y):m_x(x),m_y(y) {}
    float getX()
    {
        return m_x;
    }
    float getY()
    {
        return m_y;
    }

    Vector2D operator+(const Vector2D& v2)const;
    friend Vector2D& operator+=(Vector2D& v1,const Vector2D& v2);
    Vector2D operator*(float scalar);
    Vector2D& operator*=(float scalar);
    Vector2D operator-(const Vector2D& v2)const;
    friend Vector2D& operator-=(Vector2D& v1,const Vector2D& v2);
    Vector2D operator/(float scalar);
    Vector2D& operator/=(float scalar);
    void normalize();
    void setX(float x);
    void setY(float y);
private:
    float length()
    {
        return sqrt(m_x*m_x+m_y*m_y);
    }
    float m_x;
    float m_y;
};

#endif // VECTOR2D_H
