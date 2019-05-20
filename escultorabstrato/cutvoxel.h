#ifndef CUTVOXEL_H
#define CUTVOXEL_H
#include "figurageometrica.h"

class cutVoxel : public FiguraGeometrica{
protected:
    int x,y,z;

public:
    cutVoxel(int _x, int _y, int _z);
    void draw(sculptor &t);
    ~cutVoxel();
};

#endif // CUTVOXEL_H
