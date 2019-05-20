#include "cutsphere.h"
#include <math.h>

cutSphere::cutSphere(int _xc, int _yc, int _zc, int _r)
{

    xcenter = _xc;
    ycenter = _yc;
    zcenter = _zc;
    radius = _r;

}

cutSphere::~cutSphere()
{


}

void cutSphere::draw(sculptor &t){

    int i,j,k;

    for(i= xcenter - radius; i<xcenter + radius; i++)
        {
            for(j= ycenter - radius; j< ycenter + radius; j++)
            {
                for(k= zcenter - radius; k< zcenter + radius; k++)
                {
                    if ((pow((i-xcenter),2)) + (pow((j-ycenter),2)) + (pow((k-zcenter),2)) <= (pow(radius,2)))

                    {

                        t.cutvoxel(i,j,k);

                    }
                }
            }
        }

}
