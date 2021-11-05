#include <iostream>
#include <vector>
#include"objet/Objet.h"
#include"svg/svgfile.h"
#include "phrase/Phrase.h"
#include"util/util.h"
int main()
{
    bool id=false,ruler=false;
    int script=0;
    Objet L;
    std::string fichScript="";
    std::string mmr="";
    std::string mmrfich="";
    std::string phr;
    do
    {
        if(script==1)//lance un script
            util::startAutoCin(fichScript,50);
        script=0;
        std::cout<<mmr<<">";
        std::getline(std::cin, phr);
        analyseur(mmr, mmrfich, fichScript, DecoupeurdePhrase(phr), L, id, ruler, script);
        Svgfile svgout;
        L.affichertout(svgout, id, ruler);
        if(script==-1)//termine le script
            util::stopAutoCin();
    }while(1);
    return 0;
}
