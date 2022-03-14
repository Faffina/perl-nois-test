#pragma once
#include <cstdlib>
#include <cmath>
#include <ctime>

struct vector2d
{
    double x, y;
    vector2d();
    vector2d(double nx, double ny);
    vector2d operator+=(const vector2d& a);
    vector2d operator-=(const vector2d& a);
    vector2d operator*=(double a);
    vector2d operator/=(double a);
    vector2d operator-();
    double mod();
    double mod2();
    vector2d normal();
};

vector2d operator+(const vector2d& a, const vector2d& b);
vector2d operator-(const vector2d& a, const vector2d& b);
double dot(const vector2d& a, const vector2d& b);
vector2d operator*(double a, const vector2d& b);
vector2d operator*(const vector2d& a, double b);
vector2d operator/(const vector2d& a, double b);
vector2d polarCor(const double r, const double the);
vector2d randUnit();
vector2d randUnit(int t);

