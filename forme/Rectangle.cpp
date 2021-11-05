#include"Rectangle.h"

Rectangle::Rectangle(double longueur,double largeur,double tlX,double tlY)
{
    m_longueur=longueur;
    m_largeur=largeur;
    m_tlX=tlX;
    m_tlY=tlY;
}

Rectangle::Rectangle()
{
    m_longueur=0;
    m_largeur=0;
    m_tlX=0;
    m_tlY=0;
}

void Rectangle::setLa(double largeur)
{
     m_largeur=largeur;
}

void Rectangle::setLo(double longueur)
{
    m_longueur=longueur;
}

void Rectangle::setTLX(double tlX)
{
    m_tlX=tlX;
}

void Rectangle::setTLY(double tlY)
{
    m_tlY=tlY;
}


double Rectangle::getLa()
{
    return m_largeur;
}

double Rectangle::getLo()
{
   return m_longueur;
}

double Rectangle::getTLX()
{
    return m_tlX;
}



double Rectangle::getTLY()
{
    return m_tlY;
}

double*Rectangle::getpTLX()
{
    return &m_tlX;
}

double*Rectangle::getpTLY()
{
    return &m_tlY;
}



