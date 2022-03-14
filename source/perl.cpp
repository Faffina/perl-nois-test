#include "perl.h"


double interp(double a, double b, double w)
{
    return (b - a) * (3 - 2 * w) * w * w + a;
}

double gradientDot(vector2d pos, vector2d node)
{
    return dot(randUnit(int(pos.x)*int(pos.y)), pos - node);
}

double prelin(vector2d pos)
{
    vector2d n0 = intVector(pos);
    vector2d n1(n0.x, n0.y + 1);
    vector2d n2(n0.x + 1, n0.y + 1);
    vector2d n3(n0.x + 1, n0.y);
    vector2d s = pos - n0;
    return interp(
                interp(gradientDot(pos, n0), gradientDot(pos, n3), s.x), 
                interp(gradientDot(pos, n1), gradientDot(pos, n2), s.x), 
                s.y
                );
}