#ifndef PUTVOXEL_H
#define PUTVOXEL_H
#include "figurageometrica.h"



class putVoxel : public FiguraGeometrica{
protected:
    int x,y,z;
    float r,g,b,a;

public:
    putVoxel(int _x, int _y, int _z, float _r, float _g, float _b, float _a);
   void draw(sculptor &t);
   ~putVoxel();

};

#endif // PUTVOXEL_H
