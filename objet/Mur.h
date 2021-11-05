#ifndef MUR_H_INCLUDED
#define MUR_H_INCLUDED
#include"Objet.h"
#include"Bloc.h"
#include"../forme/Rectangle.h"


class Mur: public Objet
{
  private:
    double m_longueur,m_largeur;
    Rectangle m_rec;
  public:
    Mur(std::string,std::string,Coords,double,double, size_t);
    Mur();
    ~Mur()=default;
    virtual void afficher(Svgfile&);
    virtual void afficherVecteur(Svgfile&);
    virtual void afficherNom(Svgfile&);
    virtual void ajouterAttache(std::string nom,std::string couleur,
                                  double rot,std::string pdaSource,double dist,std::string cote,double,double, size_t);
    virtual double getLongueur()const;
    virtual double getLargeur()const;
    Rectangle* getRec();
    void setCoords(Coords);
    void setLo(double);
    void setLa(double);
};
#endif // MUR_H_INCLUDED
