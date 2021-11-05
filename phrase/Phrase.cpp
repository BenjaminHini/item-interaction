#include"Phrase.h"
#include "../sauvegarde/sauvegarde.h"
#include<fstream>

///prend un string et le découpe en un vecteur de string en le séparant a chaque "séparateur"
std::vector<std::string> DecoupeurdePhrase(const std::string& temoin, char separateur)
{
    int nbmot=0, j=0;
    std::vector<std::string> vec;
    vec.clear();
    for(size_t i=0;i<temoin.size(); ++i)//trouve la taille du vecteur
        if(temoin[i]==separateur)
            nbmot++;
    for(int i=0;i<nbmot+1;++i)//coupe la phrase et remplit le vecteur
    {
        vec.push_back(temoin.substr(j, temoin.find(separateur, j)-j));
        j=temoin.find(separateur,j)+1;
    }
  return vec;//renvoie le vecteur
}
///recupère la phrase découpée et appelle des fonctions pour réaliser des actions
void analyseur(std::string& mmr,std::string &mmrfich, std::string &fichScript,std::vector<std::string> vec,Objet&Obj, bool &id, bool &ruler,int &script)
{
    if(Commandes(vec, Obj, mmrfich,id,ruler, script, fichScript))//commandes de bases
        return;
    int nbmot=0;
    for(size_t i=0;i<vec[0].size();++i)//regarde si le premier mot est de la forme a.b.c
        if(vec[0][i]=='.')
            nbmot++;
    if(nbmot!=0)//si c'est le cas le découpe et rajoute sa découpe au début du vecteur
    {
        std::vector<std::string> p1=DecoupeurdePhrase(vec[0], '.');
        vec.erase(vec.begin());
        for(size_t i=0;i<p1.size(); ++i)
            vec.insert(vec.begin()+i, p1[i]);
    }
    if(vec[0][0]=='@')//change la valeur de la mémoire si besoin
    {
        mmr=vec[0].substr(1, vec[0].size());
        vec[0]=mmr;//enlève la @
    }
    else
        vec.insert(vec.begin(), mmr);//met la mémoire en première position du vecteur

    if(vec.size()==1)//pour permettre de juste changer la mémoire
        return;
    Rechercher(vec, Obj.getAttache(), Obj);
}
///appelé par analyseur, effectue les actions de base(exit, load/reload...)
bool Commandes(const std::vector<std::string>& oui, Objet& obj, std::string& mmrfich, bool &id, bool &ruler, int &script, std::string &fichScript)
{
    switch(Check(oui[0]))
    {
    case -1: ///pas une commande
        return false;
        break;
    case 0:///exit
        remove("store.rom");
        exit(0);
        break;
    case 1:///load
        {
            mmrfich=oui[1];
            std::ifstream fs{mmrfich};
            if(!fs)
            {
                std::cout<<"probleme fichier\n";
                break;
            }
            Objet f;
            remplir(f, fs, true, 1);
            obj=f;
            fs.close();
            break;
        }
    case 2:///reload
        {
            std::ifstream fs{mmrfich};
            if(!fs)
            {
                std::cout<<"probleme fichier\n";
                break;
            }
            Objet f;
            remplir(f, fs, true, 1);
            obj=f;
            fs.close();
            break;
        }
    case 3:///ids
        id=true;
        break;
    case 4:///noids
        id=false;
        break;
    case 5:///rulers
        ruler=true;
        break;
    case 6:///norulers
        ruler=false;
        break;
    case 7:///store
        {
            std::ofstream ofs{"store.rom"};
            if(!ofs)
            {
                std::cout<<"réessayez\n";
                break;
            }
            sauvegarder(obj, ofs, 1);
            ofs.close();
            break;
        }
    case 8:///restore
        {
            std::ifstream ifs{"store.rom"};
            if(!ifs)
            {
                std::cout<<"erreur\n";
                break;
            }
            Objet j;
            remplir(j, ifs, true, 1);
            obj=j;
            ifs.close();
            break;
        }
    case 9:///save
        {
            std::ofstream ofs{oui[1]};
            if(!ofs)
            {
                std::cout<<"probleme ouverture fichier\n";
                break;
            }
            sauvegarder(obj, ofs, 1);
            ofs.close();
            break;
        }
    case 10:///script
        {
            std::ifstream ifs{oui[1]};//vérifie si le fichier éxiste
            if(ifs)
            {
                fichScript=oui[1];
                script=1;
            }
            else
                std::cout<<"probleme ouverture fichier\n";
            ifs.close();
            break;
        }
    case 11:///fin du script
        script=-1;
        break;
    }
    return true;
}
///appelé par Commandes, vérifie si l'utilisateur veut effectuer une action de base
int Check(const std::string& a)
{
    std::vector<std::string>cmd{"exit", "load", "reload", "ids", "noids","rulers"
                                ,"norulers", "store", "restore", "save", "script", "endscript"};

    for(size_t i=0;i<cmd.size();++i)
        if(a==cmd[i])
            return i;
    return -1;
}

///appelé par analyseur, trouve le(s) bloc(s) sur lequel l'utilisateur veut effectuer une action
void Rechercher( std::vector<std::string>& vec, const std::vector<Objet*>& vecObj, Objet&Obj)
{
    //cas phrase invalide
    if(vec[vec.size()-2]!="move" && vec[vec.size()-2]!="rotate")//fonctionne en partant du principe que l'action est
    {                                                           //toujours donné en avant-dernière position de la phrase
        for(size_t i=0; i<vec.size(); ++i)
        std::cout<<"phrase invalide\n";
        return;
    }
    std::vector<Objet*> cible;
    bool encore=true;
    ParcourirArbre(vec, vecObj, cible, encore);//cible récupère tous les blocs indiqués par l'utilisateurx
    Action(vec, cible,vecObj, Obj);//effectue l'action demandée par l'utilisateur
}

void ParcourirArbre( std::vector<std::string>&phrase,const std::vector<Objet*>&vecObj, std::vector<Objet*>&cible, bool &encore, unsigned int stade)
{
    if(!encore)//force l'arrêt de la récursivité
        return;
    if(phrase[stade][phrase[stade].size()-2]=='%')//par exemple bot0%2
    {
        unsigned int av=phrase[stade][phrase[stade].size()-3]-48;//valeur avant %
        unsigned int ap=phrase[stade][phrase[stade].size()-1]-48;//valeur après %
        phrase[stade]=phrase[stade].substr(0, phrase[stade].size()-3);//bot0%2->bot
        for(unsigned int i=av; i<=vecObj.size(); i+=ap)
        {
            std::cout<<phrase[stade]<<"="<<vecObj[i-1]->getNom().substr(0,vecObj[i-1]->getNom().size()-1)<<" ";
            if(phrase[stade]==vecObj[i-1]->getNom().substr(0,vecObj[i-1]->getNom().size()-1))
            {
                cible.push_back(vecObj[i-1]);
                std::cout<<i<<" ";
            }
        }
    encore=false;
    return;
    }
    for(size_t i=0; i<vecObj.size();++i)
        if((vecObj[i]->getNom()==phrase[stade]) || (vecObj[i]->getNom().substr(0,vecObj[i]->getNom().size()-1)==phrase[stade]))
        {
            if(stade==phrase.size()-3)//dernier mot avant move/rotate
                cible.push_back(vecObj[i]);
            ParcourirArbre(phrase, vecObj, cible,encore, stade+1);
        }
    for(size_t i=0; i<vecObj.size(); ++i)
        ParcourirArbre(phrase,vecObj[i]->getAttache(), cible,encore,stade);
    return;
}

void Action(const std::vector<std::string>& phrase,const std::vector<Objet*>&cible,const std::vector<Objet*>&vecObj, Objet&Obj )
{
    int valFin=0,b;
    char op=0;
    std::string vlr=phrase[phrase.size()-1];
    //vlr=op+valFin
    if(vlr[0]=='+' || vlr[0]=='-')
    {
        op=vlr[0];
        vlr=vlr.substr(1, vlr.size());
    }
    for(size_t i=0; i<vlr.size(); ++i)
    {
        valFin*=10;
        b=vlr[i]-48;
        valFin+=b;
    }
    for(size_t i=0; i<cible.size(); ++i)
        switch(op)
        {
        case 0:
            if(phrase[phrase.size()-2]=="move")
                Collision(cible,vecObj,valFin,Obj,false,valFin-cible[i]->getPda()->getPourcent());
            if(phrase[phrase.size()-2]=="rotate")
                Collisionrot(cible,vecObj,valFin,Obj,false,valFin-cible[i]->getRot());
            break;
        case '+':
            if(phrase[phrase.size()-2]=="move")
                Collision(cible,vecObj,valFin,Obj,true,valFin-cible[i]->getPda()->getPourcent());
            if(phrase[phrase.size()-2]=="rotate")
                Collisionrot(cible,vecObj,valFin,Obj,true,valFin-cible[i]->getRot());
            break;
        case'-':
            if(phrase[phrase.size()-2]=="move")
                Collision(cible,vecObj,-valFin,Obj,true,valFin-cible[i]->getPda()->getPourcent());
            if(phrase[phrase.size()-2]=="rotate")
                Collisionrot(cible,vecObj,-valFin,Obj,true,valFin-cible[i]->getRot());
            break;
        }
}

void Collision(const std::vector<Objet*>&cible,const std::vector<Objet*>&vecObj,double valfin,Objet&Obj,bool type,double De)
{
int dest;
std::vector<std::string> comp;
     if(type==false)
     {
            dest=De;
     }
     else
     {
         dest=valfin;
     }


    for(size_t i=0; i<cible.size(); ++i)
    {
        cible[i]->comparNom(comp);

        if(dest>=0)
        {
             for(int j=0; j<=(dest*10); ++j)
            {
                if(colliParcourCible(&Obj,cible[i],true,comp))
                cible[i]->translation(0.1,true);

            }

                cible[i]->translation(-0.5,true);
        }

                if(dest<0)
        {

             for(int j=0; j>=(dest*10); --j)
            {
                if(colliParcourCible(&Obj,cible[i],true,comp))
                cible[i]->translation(-0.1,true);
            }


                cible[i]->translation(0.5,true);

        }

        comp.clear();

    }
}

void Collisionrot(const std::vector<Objet*>&cible,const std::vector<Objet*>&vecObj,double valfin,Objet&Obj,bool type,double De)
{

  int dest;
  std::vector<std::string> comp;

     if(type==false)
     {
               dest=De;
     }
     else
     {
         dest=valfin;
     }


    for(size_t i=0; i<cible.size(); ++i)
    {
        cible[i]->comparNom(comp);
        if(dest>=0)
        {
             for(int j=0; j<=(dest*10); ++j)
                if(colliParcourCible(&Obj,cible[i],true,comp))
                    cible[i]->rotation(0.1,true);
        }
        cible[i]->rotation(-0.5,true);
        if(dest<0)
        {
            for(int j=0; j>=(dest*10); --j)
                if(colliParcourCible(&Obj,cible[i],true,comp))
                    cible[i]->rotation(-0.1,true);
            cible[i]->translation(0.5,true);
        }
        comp.clear();
    }
}

bool colliParcourVecObjet(Objet*Obj,Objet*Cible,bool verif, std::vector<std::string>&comp)
{
    double a,b;

             if ( Obj->getCoord().getX() <= Cible->getCoord().getX() && Obj->getCoord().getY() <= Cible->getCoord().getY())
            {
                a=Cible->getCoord().getX() - Obj->getCoord().getX() - Obj->getLo();
                b=Cible->getCoord().getX() - Obj->getCoord().getY() - Obj->getLa() ;
            }

             if ( Obj->getCoord().getX() >= Cible->getCoord().getX() && Obj->getCoord().getY() >= Cible->getCoord().getY())
            {
                a=Obj->getCoord().getX() - Cible->getCoord().getX() - Cible->getLo() ;
                b=Obj->getCoord().getY() - Cible->getCoord().getY() - Cible->getLa() ;
            }

            if ( Obj->getCoord().getX()<= Cible->getCoord().getX() && Obj->getCoord().getY() >= Cible->getCoord().getY())
            {
                a=Cible->getCoord().getX() - Obj->getCoord().getX() - Obj->getLo() ;
                b=Obj->getCoord().getY() - Cible->getCoord().getY() - Cible->getLa();
            }

            if ( Obj->getCoord().getX() >= Cible->getCoord().getX() && Obj->getCoord().getY() <= Cible->getCoord().getY())
            {
                a= Obj->getCoord().getX() - Cible->getCoord().getX() - Cible->getLo() ;
                b= Cible->getCoord().getY() - Obj->getCoord().getY() - Obj->getLa();
            }

    if( a<-1   && b<-1  && TexteComp(comp,Obj->getNom()) && TexteComp2(Obj,Cible) )
    {

         return false;
    }

    if(Obj->getAttache().size()==0)
        return verif;
    for(size_t i=0;i<Obj->getAttache().size();++i )
    {
        verif=colliParcourVecObjet((Obj->getAttache())[i],Cible,verif,comp);
        if(verif==false)
            return verif;
    }
    return verif;
}

bool colliParcourCible(Objet*Obj,Objet*Cible,bool verif, std::vector<std::string>&comp)
{
   if(colliParcourVecObjet(Obj,Cible,verif,comp)==false)
       return false;
    if(Cible->getAttache().size()==0)
        return verif;
    for(size_t i=0;i<Cible->getAttache().size();++i )
    {
        verif=colliParcourCible(Obj,(Cible->getAttache())[i],verif,comp);

        if(verif==false)
            return verif;
    }
        return verif;
}

bool TexteComp( std::vector<std::string>&comp,std::string nom)
{
    for(size_t i=0;i<comp.size();++i)
    {

        if(comp[i]==nom)
            return false;
    }

    return true;
}

bool TexteComp2(Objet*Obj,Objet*Cible)
{
    for(size_t i=0;i<Obj->getAttache().size();++i)
    {
        if( (Obj->getAttache())[i]->getNom()==Cible->getNom())
            return false;
    }
    return true;
}
