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
        sculptor *s;

        std::ifstream fin("C:/Users/Ricardo Varela/Documents/escultorabstrato/steste.txt");

        (fin.is_open());{
            string linha;
            while (getline(fin, linha)) {

                if (linha.find("dim") != std::string::npos) {


                    std::istringstream linhaEmStream(linha);

                    int x, y, z;
                    linhaEmStream >> x >> y >> z;
                    cout << "Dimensões: " << x << " " << y << " " << z << endl;

                    s = new sculptor(x, y, z);
                }

                if (linha.find("putbox") != std::string::npos) {


                    std::istringstream StreamLinha(linha);

                    cout << "Putbox" << endl;
                    int x0, x1, y0, y1, z0, z1, r, g, b;
                    float a;

                    StreamLinha >> x0 >> x1 >> y0 >> y1 >> z0 >> z1 >> r >> g >> b >> a;
                    putBox pb(x0,x1,y0,y1,z0,z1, r, g, b, a);
                    pb.draw(*s);
                }

                if (linha.find("cutbox") != std::string::npos) {


                    std::istringstream SLinha(linha);

                    cout << "Cutbox" << endl;
                    int x0, x1, y0, y1, z0, z1;

                    SLinha >> x0 >> x1 >> y0 >> y1 >> z0 >> z1;
                    cutBox cb(x0,x1,y0,y1,z0,z1);
                    cb.draw(*s);
                }

                if (linha.find("putvoxel") != std::string::npos) {


                    std::istringstream SLinha(linha);

                    cout << "Putvoxel" << endl;
                    int x0, y0, z0, r, g, b;
                    float a;

                    SLinha >> x0 >> y0 >> z0 >> r >> g >> b >> a;
                    putVoxel pv(x0,y0,z0, r, g, b, a);
                    pv.draw(*s);
                }

                if (linha.find("cutvoxel") != std::string::npos) {

                    std::istringstream SLinha(linha);

                    cout << "Cutvoxel" << endl;
                    int x0, y0, z0, r, g, b;
                    float a;

                    SLinha >> x0 >> y0 >> z0 >> r >> g >> b >> a;
                    putVoxel cv(x0,y0,z0, r, g, b, a);
                    cv.draw(*s);
                }

                if (linha.find("cutsphere") != std::string::npos) {

                    std::istringstream SLinha(linha);

                    cout << "Cutsphere" << endl;
                    int x0, y0, z0, raio;


                    SLinha >> x0 >> y0 >> z0 >> raio;
                    cutSphere cs(x0, y0, z0, raio);
                    cs.draw(*s);
                }

                if (linha.find("putsphere") != std::string::npos) {

                    std::istringstream Slinha(linha);

                    cout << "Putsphere" << endl;
                    int x0, y0, z0, raio, r, g, b;
                    float a;

                    Slinha >> x0 >> y0 >> z0 >> raio >> r >> g >> b >> a;
                    putSphere ps(x0, y0, z0, raio, r, g, b, a);
                    ps.draw(*s);
                }

                if (linha.find("cutellipsoid") != std::string::npos) {


                    std::istringstream linhaEmStream(linha);

                    cout << "Cutellipsoid" << endl;
                    int x0, y0, z0, rx, ry, rz;

                    linhaEmStream >> x0 >> y0 >> z0 >> rx >> ry >> rz;
                    cutEllipsoid ce(x0, y0, z0, rx, ry, rz);
                    ce.draw(*s);
                }

                if (linha.find("cutellipsoid") != std::string::npos) {


                    std::istringstream Slinha(linha);

                    cout << "Cutellipsoid" << endl;
                    int x0, y0, z0, rx, ry, rz, r, g, b;
                    float a;

                    Slinha >> x0 >> y0 >> z0 >> rx >> ry >> rz >> r >> g >> b >> a;
                    putEllipsoid pe(x0, y0, z0, rx, ry, rz, r, g, b, a);
                    pe.draw(*s);
                }

            }
            fin.close();
        }

        s-> writeOFF("C:/Users/Ricardo Varela/Documents/escultorabstrato");

        cout << "arquivo foi gerado!" << endl;

    }

