#ifndef OBJET_H_INCLUDED
#define OBJET_H_INCLUDED
#include "../forme/Forme.h"
#include"../outil_math/Coords.h"
#include"../outil_math/PointDencrage.h"
#include"../svg/svgfile.h"
#include <iostream>
#include <string>
#include <vector>

class Objet
{
   protected:
    size_t m_taille;
    Coords m_coord;
    std::string m_nom;
    std::string m_couleur;
    std::vector<Objet*> m_attache;
    double m_rot;
    char m_type;

    public:
    Objet(std::string,std::string,Coords,double,size_t, char);
    Objet();
    virtual ~Objet()=default;
    virtual void afficher(Svgfile&);
    virtual void afficherNom(Svgfile&);
    virtual void afficherVecteur(Svgfile&);
    void affichertout(Svgfile&, bool id, bool ruler);
    virtual void rotation(double,bool);
    virtual void translation(double,bool);
    virtual Pda*getPda();
    virtual double getLargeur()const;
    virtual double getLongueur()const;
    virtual Forme*getForme();
    std::string getCouleur()const;
    std::string getNom() const;
    std::vector<Objet*> getAttache() const;
    virtual Coords getCoord();
    double getRot()const;
    size_t getTaille()const;
    char getType()const;
    void setTaille(size_t);
    void setNom(std::string);
    void setCouleur(std::string);
    void setRot(double);
    void comparNom(std::vector<std::string>&comp);
    virtual void initall();
    virtual void ajouterAttache(std::string nom,std::string couleur,double longueur,double largeur,Coords coord, size_t);
    virtual void ajouterAttache(std::string nom,std::string couleur,
                                  double rot,std::string pdaSource,double dist,std::string cote,double,double, size_t);
    virtual double getLa();
    virtual double getLo();

};


#endif // OBJET_H_INCLUDED
