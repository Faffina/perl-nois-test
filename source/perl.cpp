#include "perl.h"


double interp(double a, double b, double w)
{
    if(w >= 1) return b;
    if(w <= 0) return a;
    return (b - a) * (3 - 2 * w) * w * w + a;
}

double gradientDot(vector2d pos, vector2d node)
{
    return dot(node - pos, randUnit(pos));
}

double prelin(vector2d pos)
{
    int x0 = (int)floor(pos.x);
    int x1 = x0 + 1;
    int y0 = (int)floor(pos.y);
    int y1 = y0 + 1;
    double sx = pos.x - (double)x0;
    double sy = pos.y - (double)y0;
    double n0, n1, ix0, ix1, value;
    n0 = gradientDot(vector2d(x0, y0), pos);
    n1 = gradientDot(vector2d(x1, y0), pos);
    ix0 = interp(n0, n1, sx);
    n0 = gradientDot(vector2d(x0, y1), pos);
    n1 = gradientDot(vector2d(x1, y1), pos);
    ix1 = interp(n0, n1, sx);
    value = interp(ix0, ix1, sy);
    return value;
}