#include "cutvoxel.h"

cutVoxel::cutVoxel(int _x, int _y, int _z)
{

    x = _x;
    y = _y;
    z = _z;
}

cutVoxel::~cutVoxel()
{


}

void cutVoxel::draw(sculptor &t){

    t.cutvoxel(x,y,z);
}

