#ifndef SAUVEGARDE_H_INCLUDED
#define SAUVEGARDE_H_INCLUDED
#include<fstream>
#include"../objet/Objet.h"
bool remplir(Objet &oui, std::ifstream &ifs,bool bien=true,int prems=0);
void sauvegarder(Objet&, std::ofstream&, int prems=0);
#endif // SAUVEGARDE_H_INCLUDED
