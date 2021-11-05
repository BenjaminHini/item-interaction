#include"Mur.h"


Mur::Mur(std::string nom,std::string couleur,Coords coord,double longueur,double largeur, size_t taille)
:Objet{nom, couleur, coord, 0, taille, 'M'}, m_longueur{longueur}, m_largeur{largeur} , m_rec{longueur, largeur, coord.getX(), coord.getY()}
{}

Mur::Mur()
{
  m_rec.setTLX(0);
  m_rec.setTLY(0);
  m_rec.setLa(0);
  m_rec.setLo(0);
  m_longueur=0;
  m_largeur=0;
  m_nom=" ";
  m_couleur=" ";
  m_coord.setX(0);
  m_coord.setY(0);
  m_attache.clear();
  m_rot=0;
  m_taille=0;
  m_type='M';
}

void Mur::afficher(Svgfile& svgout)
{
    svgout.addRectangle(m_coord.getX(), m_coord.getY(), m_longueur, m_largeur,{0,0}, m_couleur);
}

/*void Mur::afficherNom(Svgfile svgout)const
{
    svgout.addText(m_coord.getX()+m_longueur/2-m_nom.size()/2, m_coord.getY()+m_largeur/2, m_nom, "yellow");
}
*/
Rectangle* Mur::getRec()
{
    return& m_rec;
}

void Mur::setLo(double longueur)
{
    m_longueur=longueur;
}

void Mur::setLa(double largeur)
{
    m_largeur=largeur;
}

void Mur::setCoords(Coords coord)
{
    m_coord=coord;
}

double Mur::getLargeur()const
{
    return m_largeur;
}

double Mur::getLongueur()const
{
    return m_longueur;
}
void Mur::ajouterAttache(std::string nom,std::string couleur,
                          double rot,std::string pdaSource,double distance,std::string cote,double longueur,double largeur, size_t taille)
{

    Bloc *n=nullptr;
    n=new Bloc;
    if(n==nullptr)
    {
        std::cout<<"error";
        exit(0);
    }

    n->setTaille(taille);
    n->setNom(nom);
    n->setCouleur(couleur);
    n->setRot(rot);
    n->setForme(new Rectangle);
    n->getForme()->setLa(largeur);//
    n->getForme()->setLo(longueur);//
    n->getPda()->setRotB(&m_rot);
    n->getPda()->setCote(cote);
    n->getPda()->setLaB(m_rec.getLa());
    n->getPda()->setLoB(m_rec.getLo());
    n->getPda()->setNom(pdaSource);
    n->getPda()->setTLX(m_rec.getpTLX());
    n->getPda()->setTLY(m_rec.getpTLY());
    n->calculeVecteur();

    n->getPda()->translation(distance, false);

    m_attache.push_back(n);
}


void Mur::afficherNom(Svgfile& svgout)
{
    svgout.addText(m_coord.getX()+m_longueur/2-(m_nom.size()), m_coord.getY()+m_largeur/2.2, m_nom, "yellow");
}

void Mur::afficherVecteur(Svgfile& svgout)
{

}
