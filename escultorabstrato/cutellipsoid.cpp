#include "cutellipsoid.h"
#include <math.h>

cutEllipsoid::cutEllipsoid(int _xc, int _yc, int _zc, int radx, int rady, int radz)
{

    xcenter = _xc;
    ycenter = _yc;
    zcenter = _zc;
    rx = radx;
    ry = rady;
    rz = radz;

}

cutEllipsoid::~cutEllipsoid()
{


}


void cutEllipsoid::draw(sculptor &t){

    int i,j,k;

        for(i= xcenter - rx; i<xcenter + rx; i++)
        {
            for(j= ycenter - ry; j< ycenter + ry; j++)
            {
                for(k= zcenter - rz; k< zcenter + rz; k++)
                {
                    if ((pow((i - xcenter),2)/(pow(rx,2))) + ((pow((j - ycenter),2))/(pow(ry,2))) + ((pow((k - zcenter),2))/(pow(rz,2))) <= 1.0)
                    {

                        t.cutvoxel(i,j,k);
                    }
                }
            }
      }

}
