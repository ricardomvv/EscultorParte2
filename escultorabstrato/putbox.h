#ifndef PUTBOX_H
#define PUTBOX_H
#include "figurageometrica.h"

class putBox : public FiguraGeometrica {
protected:
    int x0,x1, y0,y1, z0,z1;
    float r,g,b,a;

public:
    putBox(int _x0, int _x1, int _y0, int _y1, int _z0, int _z1, float _r, float _g, float _b, float _a);
    void draw(sculptor &t);
    ~putBox();
};

#endif // PUTBOX_H
