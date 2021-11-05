#include"Vecteur.h"

Vecteur::Vecteur(double dX,double dY,Coords PointDep)
{
    m_dX=dX;
    m_dY=dY;
    m_pointDepart=PointDep;
}

Vecteur::Vecteur()
{
    m_dX=0;
    m_dY=0;
    m_pointDepart.setX(0);
    m_pointDepart.setY(0);
}

void Vecteur::setdX(double dX)
{
    m_dX=dX;
}

void Vecteur::setdY(double dY)
{
    m_dY=dY;
}


void Vecteur::setPd(Coords pointdep)
{
   m_pointDepart=pointdep;
}

double Vecteur::getdX()
{
    return m_dX;
}

double Vecteur::getdY()
{
    return m_dY;
}

Coords* Vecteur::getPd()
{
    return &m_pointDepart;
}

void Vecteur::CalculValeurs(double longueur,double largeur,double rot)
{

}
