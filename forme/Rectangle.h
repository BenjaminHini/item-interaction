#ifndef RECTANGLE_H_INCLUDED
#define RECTANGLE_H_INCLUDED
#include"Forme.h"
#include"../svg/svgfile.h"
#include"../outil_math/PointDencrage.h"
#include<cmath>

class Rectangle: public Forme
{
    protected:
    double m_longueur,m_largeur,m_tlX,m_tlY;


    public:
    Rectangle(double,double,double,double);
    Rectangle();
    virtual ~Rectangle()=default;
    virtual void setLa(double);
    virtual void setLo(double);
    virtual void setTLX(double);
    virtual void setTLY(double);

    virtual double getLa();
    virtual double getLo();
    virtual double getTLX();
    virtual double getTLY();
    virtual double*getpTLX();
    virtual double*getpTLY();
};

#endif // RECTANGLE_H_INCLUDED
