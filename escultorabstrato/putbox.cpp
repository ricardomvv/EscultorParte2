#include "putbox.h"

putBox::putBox(int _x0, int _x1, int _y0, int _y1, int _z0, int _z1, int _r, int _g, int _b, int _a)
{

x0 = _x0;
x1 = _x1;
y0 = _y0;
y1 = _y1;
z0 = _z0;
z1 = _z1;
r = _r;
g = _g;
b = _b;
a = _a;

}

putBox::~putBox()
{


}

void putBox::draw(sculptor &t){

    int i,j,k;

       for (i = x0; i<x1; i++)
       {
           for (j = y0; j<y1; j++)
           {
               for (k = z0; k<z1; k++)
               {
                   t.setcolor(r,g,b,a);
                   t.putvoxel(i,j,k);

               }
           }
       }

}
