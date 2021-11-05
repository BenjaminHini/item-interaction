#include "PointDencrage.h"


Pda::Pda()
{
    m_coords.setX(0);
    m_coords.setY(0);
    m_LaB=0;
    m_LoB=0;
    m_rotB=0;
    m_tlX=0;
    m_tlY=0;
    m_nom=" ";
    m_cote=" ";
    m_pourcent=0;

}

Pda::Pda(Coords a, std::string b,std::string c,double LaB,double LoB,double*rotB,double*tlX,double*tlY,double pourcent)
{
    m_coords=a;
    m_nom=b;
    m_cote=c;
    m_LaB=LaB;
    m_LoB=LoB;
    m_rotB=rotB;
    m_tlX=tlX;
    m_tlY=tlY;
    m_pourcent=pourcent;

}

Coords* Pda::getCoords()
{
    return &m_coords;
}

std::string Pda::getNom() const
{
    return m_nom;
}

std::string Pda::getCote() const
{
    return m_cote;
}


void Pda::setCoords(Coords a)
{
    m_coords=a;
}

void Pda::setNom(std::string a)
{
    m_nom=a;
}

void Pda::setCote(std::string cote)
{
    m_cote=cote;
}

void Pda::setLaB(double LaB)
{
    m_LaB=LaB;
}

void Pda::setPourcent(double pourcent)
{
    m_pourcent=pourcent;
}


void Pda::setLoB(double LoB)
{
    m_LoB=LoB;
}

void Pda::setRotB(double*rotB)
{
    m_rotB=rotB;
}

void Pda::setTLX(double*tlX)
{
    m_tlX=tlX;
}

void Pda::setTLY(double*tlY)
{
    m_tlY=tlY;
}

void Pda::setVec(Vecteur Vec)
{
    m_vecteur=Vec;
}

Vecteur* Pda::getVec()
{
    return &m_vecteur;
}

double Pda::getLaB()
{
    return m_LaB;
}

double Pda::getLoB()
{
    return m_LoB;
}

double Pda::getPourcent()
{
    return m_pourcent;
}

double* Pda::getRotB()
{
    return m_rotB;
}

double* Pda::getTLX()
{
    return m_tlX;
}

double* Pda::getTLY()
{
    return m_tlY;
}

void Pda::translation(double pourcentage,bool add)
{
    if(add)
      m_pourcent+=pourcentage;
    else
      m_pourcent=pourcentage;

   m_coords.setX(m_vecteur.getPd()->getX()+(m_vecteur.getdX()*(m_pourcent/100)));
   m_coords.setY(m_vecteur.getPd()->getY()+(m_vecteur.getdY()*(m_pourcent/100)));
}


