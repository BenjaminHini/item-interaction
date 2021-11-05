#ifndef PHRASE_H_INCLUDED
#define PHRASE_H_INCLUDED


#include "../objet/Objet.h"

std::vector<std::string> DecoupeurdePhrase(const std::string&, char separateur=' ');
void analyseur(std::string &,std::string&,std::string&, std::vector<std::string>, Objet&, bool&, bool&,int&);
bool Commandes(const std::vector<std::string>&, Objet&, std::string&, bool&, bool&,int&,std::string&);
int Check(const std::string&);
void Rechercher( std::vector<std::string>&,const std::vector<Objet*>&, Objet&);
void ParcourirArbre( std::vector<std::string>&,const std::vector<Objet*>&, std::vector<Objet*>&, bool &encore, unsigned int stade=0);
void Action(const std::vector<std::string>&,const std::vector<Objet*>&, const std::vector<Objet*>&, Objet&);
void Collision(const std::vector<Objet*>&,const std::vector<Objet*>&,double valfin,Objet&,bool,double);
void Collisionrot(const std::vector<Objet*>&,const std::vector<Objet*>&,double ,Objet&,bool,double);
bool colliParcourVecObjet(Objet*,Objet*,bool, std::vector<std::string>&);
bool colliParcourCible(Objet*,Objet*,bool, std::vector<std::string>&);
bool TexteComp(std::vector<std::string>&,std::string);
bool TexteComp2(Objet*,Objet*);
#endif // PHRASE_H_INCLUDED
