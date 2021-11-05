#ifndef POINTDENCRAGE_H_INCLUDED
#define POINTDENCRAGE_H_INCLUDED

#include<string>
#include"Vecteur.h"
#include"Coords.h"
#include"../svg/svgfile.h"


class Pda
{
private:
    Coords m_coords;
    std::string m_nom;
    Vecteur m_vecteur;
    std::string m_cote;
    double m_LaB,m_LoB,m_pourcent;
    double* m_rotB,*m_tlX,*m_tlY;
public:
    Pda();
    Pda(Coords, std::string,std::string,double,double,double*,double*,double*,double);
    ~Pda()=default;
    Coords*getCoords() ;
    std::string getNom() const;
    Vecteur* getVec() ;
    std::string getCote()const;
    double getLaB();
    double getLoB();
    double getPourcent();
    double*getRotB();
    double*getTLX();
    double*getTLY();
    void setCoords(Coords);
    void setNom(std::string);
    void setCote(std::string);
    void translation(double,bool);
    void afficherVecteur(Svgfile);
    void setVec(Vecteur);
    void setLaB(double);
    void setLoB(double);
    void setPourcent(double);
    void setRotB(double*);
    void setTLX(double*);
    void setTLY(double*);
};

#endif // POINTDENCRAGE_H_INCLUDED
