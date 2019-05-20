#include "putsphere.h"
#include <math.h>

putSphere::putSphere(int _xc, int _yc, int _zc, int _radius, float _r, float _g, float _b,float _a)
{
    xcenter = _xc;
    ycenter = _yc;
    zcenter = _zc;
    radius = _radius;
    r = _r;
    g = _g;
    b = _b;
    a = _a;


}

putSphere::~putSphere()
{


}

void putSphere::draw(sculptor &t){
    int i,j,k;

    for(i= xcenter - radius; i<xcenter + radius; i++)
        {
            for(j= ycenter - radius; j< ycenter + radius; j++)
            {
                for(k= zcenter - radius; k< zcenter + radius; k++)
                {
                    if ((pow((i-xcenter),2)) + (pow((j-ycenter),2)) + (pow((k-zcenter),2)) <= (pow(radius,2)))

                    {

                        t.setcolor(r,g,b,a);
                        t.putvoxel(i,j,k);

                    }
                }
            }
        }
    }
