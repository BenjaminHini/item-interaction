#ifndef CERCLE_H_INCLUDED
#define CERCLE_H_INCLUDED
#include"../outil_math/Coords.h"
#include"Forme.h"
#include <iostream>

class Cercle : public Forme
{
    protected:
        double m_rayon;
        Coords m_centre;

    public:
        Cercle(double,Coords);
        Cercle();
        virtual ~Cercle()=default;
        virtual void setRayon(double);
        virtual double getRayon();
        virtual Coords*getCentre();

};

#endif // CERCLE_H_INCLUDED
