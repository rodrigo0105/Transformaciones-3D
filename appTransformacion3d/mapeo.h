#ifndef MAPEO_H
#define MAPEO_H
#include <math.h>
class Mapeo
{
   float XWmin,YWmin,XWmax,YWmax;//VENTANA O MUNDO REAL
   int  XPVmin,YPVmin,XPVmax,YPVmax;//PUERTO DE VISION

   public:
    void ventana(float WX1,float WY1,float WX2,float WY2);

    void puerto(int VX1,int VY1,int VX2,int VY2);
                          // & = referencia, dir. de memoria de la variable
    void mapear(int X,int Y,int &XT, int &YT,int L,int M);
};
#endif // MAPEO_H
