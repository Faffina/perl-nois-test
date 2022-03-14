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
    return vector2d(a.x - b.x, a.y - b.y);
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

vector2d randUnit(const vector2d& a0)
{
    const unsigned w = 8 * sizeof(unsigned);
    const unsigned s = w / 2; // rotation width
    unsigned a = a0.x, b = a0.y;
    a *= 3284157443; b ^= a << s | a >> w-s;
    b *= 1911520717; a ^= b << s | b >> w-s;
    a *= 2048419325;
    float random = a * (3.14159265 / ~(~0u >> 1)); // in [0, 2*Pi]
    vector2d v;
    v.x = cos(random); v.y = sin(random);
    return v;
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

vector2d intVector(const vector2d& a)
{
    return vector2d(int(a.x), int(a.y));
}