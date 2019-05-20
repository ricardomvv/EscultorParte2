#include "sculptor.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <math.h>

using namespace std;
/**
 * @brief sculptor::sculptor é lasse responsável pela e manipulação da matriz de voxels utilizado para representar as figuras geométricas.
 * @param _nx É Dimensão X da matriz de Voxels.
 * @param _ny É Dimensão Y da matriz de Voxels.
 * @param _nz É Dimensão Z da matriz de Voxels.
 */


sculptor::sculptor(int _nx, int _ny, int _nz)
{
    nx = _nx;
    ny = _ny;
    nz = _nz;
    _r = 0;
    _g = 0;
    _b = 0;
    _a = 0;

//Para realizar a alocação dinâmica de memória (usando "new" em C++) e gerar a matriz3D.


       matriz3D = new Voxel**[nx];
       matriz3D[0] = new Voxel*[nx*ny];
       matriz3D[0][0] = new Voxel[nx*ny*nz];

       for(int i=0; i< nx; i++)
       {

           matriz3D[i+1] = matriz3D[i] + ny;

           for(int j=0; j< ny; j++)
           {
               matriz3D[i][j+1] = matriz3D[i][j] + nz;
           }

       }

       for(int i = 0; i < nx; i++)
       {
           for(int j = 0; j < ny; j++)
           {
               for(int k = 0; k < nz; k++)
               {
                   matriz3D[i][j][k].r = 0;
                   matriz3D[i][j][k].g = 0;
                   matriz3D[i][j][k].b = 0;
                   matriz3D[i][j][k].a = 0;
                   matriz3D[i][j][k].isOn = false;
               }
           }
       }
   }


   sculptor::~sculptor()
   {
       //Destrutor de Classes
       if (nx == 0 || ny ==0 || nz ==0){
           return;
       }

       delete [] matriz3D[0][0];
       delete [] matriz3D[0];
       delete [] matriz3D;
   }
   /**
    * @brief sculptor::setcolor Definir as cores, fazendo com que o valores das cores (R,G,B) fiquem entre 0 e 1.
    * @param r
    * @param g
    * @param b
    * @param alpha
    */
   void sculptor::setcolor(float r, float g, float b, float alpha)
   {


       if(r >1)
       {
           _r = 1;
       }
       else if(r <0)
       {
           _r = 0;
       }
       else
       {
           _r = r;
       }

       // Para GREEN:
       if(g >1)
       {
           _g = 1;
       }
       else if(g <0)
       {
           _g = 0;
       }
       else
       {
           _g = g;
       }

       // Para BLUE:
       if(b >1)
       {
           _b = 1;
       }
       else if(b <0)
       {
           _b = 0;
       }
       else
       {
           _b = b;
       }

       //Para Alpha:
       if(alpha >1)
       {
           _a = 1;
       }
       else if(alpha <0)
       {
           _a = 0;
       }
       else
       {
           _a = alpha;
       }

   }

   /**
    * @brief sculptor::cutvoxel Desativa o voxel na posição (x,y,z),fazendo isOn = false
    * @param x
    * @param y
    * @param z
    */
   void sculptor::cutvoxel(int x, int y, int z)
   {


       matriz3D[x][y][z].isOn = false;


   }

   /**
    * @brief sculptor::putvoxel Ativa o voxel na posição (x,y,z),fazendo isOn = true e atribuindo a cor atual de desenho
    * @param x
    * @param y
    * @param z
    */
   void sculptor::putvoxel(int x, int y, int z)
   {



       matriz3D[x][y][z].isOn = true;
       matriz3D[x][y][z].r = _r;
       matriz3D[x][y][z].g = _g;
       matriz3D[x][y][z].b = _b;
       matriz3D[x][y][z].a = _a;
   }



   void sculptor::writeOFF(string filename)
   {
       char pontos[nx][ny][nz];
       int i,j,k;
       int Nvoxels = 0; // Variavel que contabiliza o numero de Voxels.
       int Nvar = 0;
       bool vX, vY, vZ;

       ofstream fout;

       for(i = 0; i < nx; i++)
       {
           for(j = 0; j < ny; j++)
           {
               for(k = 0; k < nz; k++)
               {
                   pontos[i][j][k] = 0; //Inicialmente preenchemos a matriz com 0
               }
           }
       }

          for(int i = 1; i < nx-1; i++)
              for(int j = 1; j < ny-1; j++)
                  for(int k = 1; k < nz-1; k++){
                      vX = false; vY = false; vZ=false;

                      if(matriz3D[i][j][k-1].isOn && matriz3D[i][j][k+1].isOn)
                          vZ = true;

                      if(matriz3D[i][j-1][k].isOn && matriz3D[i][j+1][k].isOn)
                          vY = true;

                      if(matriz3D[i-1][j][k].isOn && matriz3D[i+1][j][k].isOn)
                          vX = true;

                      if(vX && vY && vZ){
                          pontos[i][j][k] = 1;
                      }
                  }


       fout.open(filename.c_str());

       if(fout.is_open() == false)
       {
           cout << "arquivo nao foi aberto\n";
           exit(1);

       }

       fout<<"OFF"<<endl;



       for(i = 0; i < nx; i++)
       {

           for(j = 0; j < ny; j++)
           {

               for(k = 0; k < nz; k++)
               {
                   if (matriz3D[i][j][k].isOn && pontos[i][j][k] == 0){
                   Nvoxels++; // Essa parte que vai permitir encontrar a quantidade de voxels, por exemplo: na dimenssão 2x2x2 existem 24 Voxels.
                        }
               }
           }
       }

       fout<<Nvoxels*8<<" "<<Nvoxels*6<<" 0"<<endl;//SEGUNDA LINHA

       for(j=0; j<ny; j++)
       {
           for (i=0; i<nx; i++)
           {
               for(int k=0; k<nz; k++)
               {
                   fout<<-0.5+i<<" "<<0.5+j<<" "<<-0.5+k<<endl; //TERCEIRA LINHA EM DIANTE
                   fout<<-0.5+i<<" "<<-0.5+j<<" "<<-0.5+k<<endl;
                   fout<<0.5+i<<" "<<-0.5+j<<" "<<-0.5+k<<endl;
                   fout<<0.5+i<<" "<<0.5+j<<" "<<-0.5+k<<endl;
                   fout<<-0.5+i<<" "<<0.5+j<<" "<<0.5+k<<endl;
                   fout<<-0.5+i<<" "<<-0.5+j<<" "<<0.5+k<<endl;
                   fout<<0.5+i<<" "<<-0.5+j<<" "<<0.5+k<<endl;
                   fout<<0.5+i<<" "<<0.5+j<<" "<<0.5+k<<endl; //DÉCIMA LINHA

               }
           }
       }



       for(k=0; k<nz; k++)
       {
           for(j=0; j<ny; j++)
           {
               for (i=0; i<nx; i++)
               {

                   fout <<"4 "<<0+Nvar*8<<" "<<3+Nvar*8<<" "<<2+Nvar*8<<" "<<1+Nvar*8<<" "<<matriz3D[i][j][k].r<<" "<<matriz3D[i][j][k].g<<" "<<matriz3D[i][j][k].b<<" "<<matriz3D[i][j][k].a<<endl;
                   fout <<"4 "<<4+Nvar*8<<" "<<5+Nvar*8<<" "<<6+Nvar*8<<" "<<7+Nvar*8<<" "<<matriz3D[i][j][k].r<<" "<<matriz3D[i][j][k].g<<" "<<matriz3D[i][j][k].b<<" "<<matriz3D[i][j][k].a<<endl;
                   fout <<"4 "<<0+Nvar*8<<" "<<1+Nvar*8<<" "<<5+Nvar*8<<" "<<4+Nvar*8<<" "<<matriz3D[i][j][k].r<<" "<<matriz3D[i][j][k].g<<" "<<matriz3D[i][j][k].b<<" "<<matriz3D[i][j][k].a<<endl;
                   fout <<"4 "<<0+Nvar*8<<" "<<4+Nvar*8<<" "<<7+Nvar*8<<" "<<3+Nvar*8<<" "<<matriz3D[i][j][k].r<<" "<<matriz3D[i][j][k].g<<" "<<matriz3D[i][j][k].b<<" "<<matriz3D[i][j][k].a<<endl;
                   fout <<"4 "<<3+Nvar*8<<" "<<7+Nvar*8<<" "<<6+Nvar*8<<" "<<2+Nvar*8<<" "<<matriz3D[i][j][k].r<<" "<<matriz3D[i][j][k].g<<" "<<matriz3D[i][j][k].b<<" "<<matriz3D[i][j][k].a<<endl;
                   fout<<" 4 "<<1+Nvar*8<<" "<<2+Nvar*8<<" "<<6+Nvar*8<<" "<<5+Nvar*8<<" "<<matriz3D[i][j][k].r<<" "<<matriz3D[i][j][k].g<<" "<<matriz3D[i][j][k].b<<" "<<matriz3D[i][j][k].a<<endl;
                   Nvar++;

               }
           }

       }

   }

   void sculptor::writeVECT(string filename)
   {

       int Nvoxels = 0;
       int pontos[nx][ny][nz];
       int i,j,k;


       for(i = 0; i < nx; i++)
       {
           for(j = 0; j < ny; j++)
           {
               for(k = 0; k < nz; k++)
               {
                   pontos[i][j][k] = 0;
               }
           }
       }

       ofstream fout;

       fout.open(filename.c_str());
       if(fout.is_open()== false)
       {
           cout << "arquivo nao foi aberto\n";
           exit(1);
       }

       fout << "VECT" << endl;

       for(i = 0; i < nx; i++)
       {
           for(j = 0; j < ny; j++)
           {
               for(k = 0; k < nz; k++)
               {

                   Nvoxels++;

               }
           }
       }

       fout << Nvoxels << " " << Nvoxels << " " << Nvoxels << endl;

       for (i =0; i<Nvoxels; i++)
       {
           fout << "1" <<" ";
       }
       fout << endl;
       for (i =0; i<Nvoxels; i++)
       {
           fout << "1" <<" ";
       }
       fout << endl;
       for(i = 0; i < nx; i++)
       {
           for(j = 0; j < ny; j++)
           {
               for(k = 0; k < nz; k++)
               {

                   fout << i <<" "<< j <<" "<< k << endl;

               }
           }
       }
       for(i = 0; i < nx; i++)
       {
           for(j = 0; j < ny; j++)
           {
               for(k = 0; k < nz; k++)
               {

                   fout << matriz3D[i][j][k].r <<" "<< matriz3D[i][j][k].g <<" "<< matriz3D[i][j][k].b <<" "<< matriz3D[i][j][k].a << endl;

               }
           }
       }

   }

