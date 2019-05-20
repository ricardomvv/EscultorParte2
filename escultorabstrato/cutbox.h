#ifndef CUTBOX_H
#define CUTBOX_H
#include "figurageometrica.h"

class cutBox : public FiguraGeometrica{
protected:
    int x0, x1, y0, y1, z0, z1;

public:
    cutBox(int _x0, int _x1, int _y0, int _y1, int _z0, int _z1);
    void draw(sculptor &t);
    ~cutBox();

};

#endif // CUTBOX_H
