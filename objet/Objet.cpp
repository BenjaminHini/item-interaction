#include"Objet.h"
#include"Mur.h"
#include "../svg/svgfile.h"

Objet::Objet(std::string nom,std::string couleur,Coords coord,double rot, size_t taille, char type)
{
    m_nom=nom;
    m_couleur=couleur;
    m_coord=coord;
    m_attache.clear();
    m_rot=rot;
    m_taille=taille;
    m_type=type;
}

Objet::Objet()
{
  m_nom=" ";
  m_couleur=" ";
  m_coord.setX(0);
  m_coord.setY(0);
  m_attache.clear();
  m_rot=0;
  m_taille=0;
  m_type=0;
}
char Objet::getType()const
{
    return m_type;
}
std::string Objet::getNom()const
{
    return m_nom;
}

std::vector<Objet*> Objet::getAttache()const
{
    return m_attache;
}

void Objet::setCouleur(std::string couleur)
{
    m_couleur=couleur;
}

Pda* Objet::getPda()
{
  return 0;
}

void Objet::setNom(std::string nom)
{
    m_nom=nom;
}

void Objet::setRot(double rot)
{
    m_rot=rot;
}
double Objet::getRot()const
{
    return m_rot;
}
Forme *Objet::getForme()
{
    return nullptr;
}
Coords Objet::getCoord()
{

    return m_coord;
}
std::string Objet::getCouleur()const
{
    return m_couleur;
}
void Objet::afficherNom(Svgfile& svgout)
{

}

void Objet::affichertout(Svgfile &svgout, bool id, bool ruler)
{
    afficher(svgout);
    if(m_attache.size()==0)
    {
        if(id)
            afficherNom(svgout);
        if(ruler)
            afficherVecteur(svgout);
        return;
    }

     for(size_t i=0;i<m_attache.size();++i )
     {
         m_attache[i]->affichertout(svgout, id, ruler);
     }

     if(id)
        afficherNom(svgout);
     if(ruler)
        afficherVecteur(svgout);
}

double Objet::getLargeur()const
{
    return 0;
}
double Objet::getLongueur()const
{
    return 0;
}
void Objet::afficher(Svgfile& svgout)
{

}

void Objet::afficherVecteur(Svgfile& svgout)
{

}

void Objet::rotation(double angle,bool add)
{


}

void Objet::translation(double pourcentage,bool add)
{


}

 void Objet::ajouterAttache(std::string nom,std::string couleur,
                                  double rot,std::string pdaSource,double dist ,std::string cote,double lgr,double lrgr, size_t taille)
{

}

void Objet::ajouterAttache(std::string nom,std::string couleur,double longueur,double largeur,Coords coord, size_t taille)
{

    Mur *n=nullptr;
    n=new Mur;
    if(n==nullptr)
    {
        std::cout<<"error";
        exit(0);
    }
    n->setTaille(taille);
    n->setNom(nom);
    n->setCouleur(couleur);
    n->setRot(0);
    n->getRec()->setLa(largeur);
    n->getRec()->setLo(longueur);
    n->setLo(longueur);
    n->setLa(largeur);
    n->setCoords(coord);
    n->getRec()->setTLX(coord.getX());
    n->getRec()->setTLY(coord.getY());
    m_attache.push_back(n);
}

size_t Objet::getTaille()const
{
    return m_taille;
}

void Objet::setTaille(size_t a)
{
    m_taille=a;
}

void Objet::initall()
{

}
void Objet::comparNom(std::vector<std::string>&comp)
 {
    comp.push_back(m_nom);

    if(m_attache.size()==0)
        return ;

    for(size_t i=0;i<m_attache.size();++i )
    {
      m_attache[i]->comparNom(comp);
    }

    return ;

 }


 double Objet::getLa()
{
  return 0;
}

double Objet::getLo()
{
return 0;
}
