#ifndef CUTELLIPSOID_H
#define CUTELLIPSOID_H
#include "figurageometrica.h"

class cutEllipsoid : public FiguraGeometrica{
protected:
    int xcenter, ycenter, zcenter, rx, ry, rz;

public:
    cutEllipsoid(int _xc, int _yc, int _zc, int radx, int rady, int radz);
    void draw (sculptor &t);
    ~cutEllipsoid();
};

#endif // CUTELLIPSOID_H
