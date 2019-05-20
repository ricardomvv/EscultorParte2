#ifndef PUTELLIPSOID_H
#define PUTELLIPSOID_H
#include "figurageometrica.h"

class putEllipsoid : public FiguraGeometrica{
protected:
    int xcenter, ycenter, zcenter, rx, ry, rz;
    float r,g,b,a;

public:
    putEllipsoid(int _xc, int _yc, int _zc, int radx, int rady, int radz, float _r, float _g, float _b, float _a);
    void draw(sculptor &t);
    ~putEllipsoid();
};

#endif // PUTELLIPSOID_H
