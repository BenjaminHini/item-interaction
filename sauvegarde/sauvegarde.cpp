#include "sauvegarde.h"
#include "../objet/Objet.h"
#include "../outil_math/Coords.h"

bool remplir(Objet& oui, std::ifstream& ifs, bool bien, int prems)
{
    Coords a;
    double x,y;
    char mur;
    std::string nom, clr, Pda1, cote;
    double lgr, lrgr, rot, distance;
    size_t vecSize;
    if(prems==1)
    {
        ifs >> vecSize;
        oui.setTaille(vecSize);
    }
    if(oui.getTaille()==0)
        return false;

    ifs>>vecSize;
    ifs>>mur;
    if(mur=='M')
    {
        ifs>>x;
        ifs>>y;
        a.setX(x);
        a.setY(y);
    }
    ifs>>nom;
    ifs>>lgr;
    ifs>>lrgr;
    ifs>>clr;
    if(mur=='M')
        oui.ajouterAttache(nom, clr, lgr, lrgr,a, vecSize);
    else
    {
        ifs>>rot;
        ifs>>Pda1;
        ifs>>distance;
        ifs>>cote;
        oui.ajouterAttache(nom, clr, rot, Pda1,distance, cote, lgr, lrgr, vecSize);
    }
    if(bien==true)
        for(size_t i=0; i<oui.getTaille(); ++i)
        {
            if(!ifs.fail() && bien==false)
                bien=remplir(oui, ifs, false);
            if(!ifs.fail() && bien==true)
            {
                if(i<oui.getAttache().size())
                    bien=remplir(*oui.getAttache()[i], ifs);
                else
                {
                    i--;
                    bien=false;
                }
            }
        }
    return true;
}


void sauvegarder(Objet& a, std::ofstream &ofs, int prems)
{
    if(prems==1)
        ofs<<a.getTaille()<<std::endl;
    else
    {
        ofs<<a.getTaille()<<" "<<a.getType()<<" ";
    }

        switch(a.getType())
        {
        case 'M':
            ofs<<a.getCoord().getX()<<" "<<a.getCoord().getY()<<" "
               <<a.getNom()<<" "<<a.getLongueur()<<" "<<a.getLargeur()<<" "<<a.getCouleur()<<std::endl;
            break;
        case 'B':
            ofs<<a.getNom()<<" "<<a.getForme()->getLo()<<" "<<a.getForme()->getLa()<<" "
               <<a.getCouleur()<<" "<<a.getRot()<<" "<<a.getPda()->getNom()<<" "<<a.getPda()->getPourcent()<<" "
               <<a.getPda()->getCote()<<std::endl;
            break;
        }
    for(size_t i=0; i<a.getTaille(); ++i)
        sauvegarder(*a.getAttache()[i], ofs);
    return;
}
