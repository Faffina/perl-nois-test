#include "vector2d.h"


vector2d::vector2d()
{
    x = 0;
    y = 0;
}

vector2d::vector2d(double nx, double ny): x(nx), y(ny) {};

vector2d vector2d::operator*=(double a)
{
    x *= a;
    y *= a;
    return *this;
}

vector2d vector2d::operator+=(const vector2d& a)
{
    x += a.x;
    y += a.y;
    return *this;
}

vector2d vector2d::operator-=(const vector2d& a)
{
    x -= a.x;
    y -= a.y;
    return *this;
}

vector2d vector2d::operator-()
{
    x = -x;
    y = -y;
    return *this;
}

vector2d vector2d::operator/=(double a)
{
    x /= a;
    y /= a;
    return *this;
}

vector2d operator*(double a, const vector2d& b)
{
    return vector2d(b.x * a, b.y * a);
}

vector2d operator*(const vector2d& a, double b)
{
    return vector2d(a.x * b, a.y * b);
}

vector2d operator+(const vector2d& a, const vector2d& b)
{
    return vector2d(a.x + b.x, a.y + a.y);
}

vector2d operator-(const vector2d& a, const vector2d& b)
{
    return vector2d(a.x - b.x, a.y - a.y);
}

vector2d operator/(const vector2d& a, double b)
{
    return vector2d(a.x / b, a.y / b);
}

double dot(const vector2d& a, const vector2d& b)
{
    return a.x*b.x + a.y*b.y;
}

vector2d polarCor(const double r, const double the)
{
    return vector2d(r*cos(the), r*sin(the));
}

vector2d randUnit()
{
    return randUnit(time(0));
}

vector2d randUnit(int t)
{
    srand(t);
    double the = (double(rand()) / RAND_MAX) * 2 * M_PI;
    return polarCor(1, the);
}

double vector2d::mod2()
{
    return x*x + y*y;
}

double vector2d::mod()
{
    return sqrt(mod2());
}

vector2d vector2d::normal()
{
    *this /= mod();
    return *this;
}