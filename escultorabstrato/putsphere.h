#ifndef PUTSPHERE_H
#define PUTSPHERE_H
#include "figurageometrica.h"

class putSphere : public FiguraGeometrica{

protected:
    int xcenter, ycenter, zcenter, radius, r, g ,b, a;

public:
    putSphere(int _xc, int _yc, int _zc, int _radius, int _r,int _g, int _b,int _a);

void draw(sculptor &t);
~putSphere();

};


#endif // PUTSPHERE_H
