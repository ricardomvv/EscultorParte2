#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <string>

#include "sculptor.h"
#include "figurageometrica.h"
#include "voxel.h"
#include "putbox.h"
#include "putvoxel.h"
#include "cutvoxel.h"
#include "cutbox.h"
#include "putsphere.h"
#include "cutsphere.h"
#include "putellipsoid.h"
#include "cutellipsoid.h"

using namespace std;


//C:/Users/Ricardo Varela/Documents/escultorabstrato/steste.txt

int main()
{
    ifstream fin;
        string s;
        stringstream ss;
        sculptor *c;

        int nx = 0;
        int ny = 0;
        int nz = 0;
        float r,g,b,a;

        vector<FiguraGeometrica*> fig;
        unsigned int n = 0;


            fin.open("steste.txt");

            if(!fin.is_open()){

                exit(0);

              }
            cout<<"Arquivo aberto com sucesso!"<<endl;

            getline(fin, s);

            ss.str(s);

            ss >> s;
            ss >> nx >> ny >> nz;

            c = new sculptor(nx,ny,nz);

            ss.clear();

            while(fin.good()){
                getline(fin, s);
                ss.str(s);
                ss >> s;

                if(s.compare("putvoxel") == 0){
                    int x,y,z;
                    ss >> x >> y >> z >> r >> g >> b >> a;
                    fig.push_back(new putVoxel(x,y,z,r,g,b,a));
                    fig[n]->draw(*c);
                    n++;
                }
                if(s.compare("cutvoxel") == 0){
                    int x,y,z;
                    ss >> x >> y >> z;
                    fig.push_back(new cutVoxel(x,y,z));
                    fig[n]->draw(*c);
                    n++;
                }

                if(s.compare("putbox") == 0){
                    int x0,x1,y0,y1,z0,z1;
                    ss >> x0 >> x1 >> y0 >> y1 >> z0 >> z1 >> r >> g >> b >> a;
                    fig.push_back(new putBox(x0,x1,y0,y1,z0,z1,r,g,b,a));
                    fig[n]->draw(*c);
                    n++;
                }
                if(s.compare("cutbox") == 0){
                    int x0,x1,y0,y1,z0,z1;
                    ss >> x0 >> x1 >> y0 >> y1 >> z0 >> z1;
                    fig.push_back(new cutBox(x0,x1,y0,y1,z0,z1));
                    fig[n]->draw(*c);
                    n++;
                }

                if(s.compare("putsphere") == 0){
                    int xc,yc,zc,raio;
                    ss >> xc >> yc >> zc >> raio >> r >> g >> b >> a;
                    fig.push_back(new putSphere(xc,yc,zc,raio,r,g,b,a));
                    fig[n]->draw(*c);
                    n++;
                }
                if(s.compare("cutsphere") == 0){
                    int xc,yc,zc,raio;
                    ss >> xc >> yc >> zc >> raio;
                    fig.push_back(new cutSphere(xc,yc,zc,raio));
                    fig[n]->draw(*c);
                    n++;
                }

                if(s.compare("putellipsoid") == 0){
                    int xc,yc,zc,rx,ry,rz;
                    ss >> xc >> yc >> zc >> rx >> ry >> rz >> r >> g >> b >> a;
                    fig.push_back(new putEllipsoid(xc,yc,zc,rx,ry,rz,r,g,b,a));
                    fig[n]->draw(*c);
                    n++;
                }
                if(s.compare("cutellipsoid") == 0){
                    int xc,yc,zc,rx,ry,rz;
                    ss >> xc >> yc >> zc >> rx >> ry >> rz;
                    fig.push_back(new cutEllipsoid(xc,yc,zc,rx,ry,rz));
                    fig[n]->draw(*c);
                    n++;
                }

                ss.clear();
            }

            c -> writeOFF("testando.off");


        return 0;

    }

