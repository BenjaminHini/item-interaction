#ifndef VECTEUR_H_INCLUDED
#define VECTEUR_H_INCLUDED
#include <iostream>
#include"Coords.h"

class Vecteur
{
    private:
    double m_dX,m_dY;
    Coords m_pointDepart;

    public:
        Vecteur(double,double,Coords);
        Vecteur();
        ~Vecteur()=default;
        void setdX(double);
        void setdY(double);
        void setPd(Coords);
        double getdX();
        double getdY();
        Coords* getPd();

       void CalculValeurs(double,double,double);
};

#endif // VECTEUR_H_INCLUDED
