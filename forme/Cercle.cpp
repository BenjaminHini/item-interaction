#include"Cercle.h"

Cercle::Cercle(double rayon,Coords centre )
{
    m_rayon=rayon;
    m_centre=centre;
}

Cercle::Cercle()
{
    m_rayon=0;
    m_centre.setX(0);
    m_centre.setY(0);
}

double Cercle::getRayon()
{
  return m_rayon;
}

void Cercle::setRayon(double rayon)
{
   m_rayon=rayon;
}

Coords* Cercle::getCentre()
{
    return &m_centre;
}
