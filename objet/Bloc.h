#ifndef BLOC_H_INCLUDED
#define BLOC_H_INCLUDED
#include"../forme/Forme.h"
#include"../forme/Rectangle.h"
#include"../outil_math/PointDencrage.h"
#include"../svg/svgfile.h"
#include"Objet.h"
#include<cmath>

class Bloc: public Objet
{
  private:
      Forme*m_forme;
      Pda m_pointa;
  public:
      Bloc(std::string,std::string,Coords,Forme*,Pda,double, size_t);
      Bloc();
     ~Bloc()=default;
      virtual void afficherNom(Svgfile&);
      virtual void afficherVecteur(Svgfile&);
      virtual void afficher( Svgfile&);
      virtual void ajouterAttache(std::string nom,std::string couleur,
                                  double rot,std::string pdaSource,double dist,std::string cote,double,double, size_t);
      virtual void translation(double,bool);
      virtual void rotation(double,bool);
      void calculeVecteur();
      void setForme(Forme*);
      void init();
      virtual Pda*getPda();
      Forme*getForme();
      virtual Coords getCoord();
      virtual double getLa();
      virtual double getLo();
      virtual void initall();
};
#endif // BLOC_H_INCLUDED
