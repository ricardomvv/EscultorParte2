#ifndef SCULPTOR_H
#define SCULPTOR_H
#include "voxel.h"


/**
 * @brief The sculptor class tem como objetivo reunir as caracteristicas que definem as unidades que compõe o desenho 3D, sendo assim representado por um cubo de lado 1, possuindo os atributos de cor,
 * no padrão RGB
 */
class sculptor
{
protected:
    int nx, ny, nz;
    float _r,_g, _b, _a;
    Voxel ***matriz3D;

public:
    sculptor(int _nx, int _ny, int _nz);
    ~sculptor();
    void setcolor(float r, float g, float b, float alpha);
    void putvoxel(int x, int y, int z);
    void cutvoxel(int x, int y, int z);
    void writeOFF(string filename);
    void writeVECT(string filename);
};

#endif // SCULPTOR_H

