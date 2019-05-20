#ifndef PUTSPHERE_H
#define PUTSPHERE_H
#include "figurageometrica.h"

class putSphere : public FiguraGeometrica{

protected:
    int xcenter, ycenter, zcenter, radius;
    float r,g,b,a;

public:
    putSphere(int _xc, int _yc, int _zc, int _radius, float _r,float _g, float _b,float _a);

void draw(sculptor &t);
~putSphere();

};


#endif // PUTSPHERE_H
