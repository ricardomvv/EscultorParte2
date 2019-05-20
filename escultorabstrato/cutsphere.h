#ifndef CUTSPHERE_H
#define CUTSPHERE_H
#include "figurageometrica.h"

class cutSphere : public FiguraGeometrica{
protected:

    int xcenter, ycenter, zcenter, radius;

public:
    cutSphere(int _xc, int _yc, int _zc, int _r);
    void draw(sculptor &t);
    ~cutSphere();

};

#endif // CUTSPHERE_H
