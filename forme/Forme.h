#ifndef FORME_H_INCLUDED
#define FORME_H_INCLUDED
#include"../svg/svgfile.h"
#include"../outil_math/PointDencrage.h"
#include <iostream>

class Forme
{
public:
    Forme();
    virtual ~Forme()=default;
    virtual void afficher(Svgfile&,Pda,double);
    virtual void affichernom(Svgfile&) const;
    virtual double getLa();
    virtual double getLo();
    virtual double getTLX();
    virtual double getTLY();
    virtual double*getpTLX();
    virtual double*getpTLY();
    virtual void setLa(double);
    virtual void setLo(double);
    virtual void setTLX(double);
    virtual void setTLY(double);
    virtual void setRayon(double);
    virtual double getRayon();
    virtual Coords*getCentre();
};

#endif // FORME_H_INCLUDED
