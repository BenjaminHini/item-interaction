#include"Bloc.h"

Bloc::Bloc(std::string nom ,std::string couleur ,Coords coord,Forme*forme,Pda pda,double rot, size_t taille)
:Objet{nom, couleur, coord, rot, taille, 'B'}, m_forme{forme}, m_pointa{pda}
{}

Bloc::Bloc()
{
  m_nom=" ";
  m_couleur=" ";
  m_coord.setX(0);
  m_coord.setY(0);
  m_attache.clear();
  m_rot=0;
  m_type='B';
  m_pointa.setNom(" ");
  m_pointa.getCoords()->setX(0);
  m_pointa.getCoords()->setY(0);
}

void Bloc::afficher(Svgfile& svgout)
{
   init();
   svgout.addRectangle(m_forme->getTLX(),m_forme->getTLY(),m_forme->getLo(),m_forme->getLa(),{m_forme->getTLX(),m_forme->getTLY()},m_couleur,m_rot);

}

void Bloc::translation(double pourcentage,bool add)
{
    m_pointa.translation(pourcentage,add);
    initall();
}

Pda* Bloc::getPda()
{
    return &m_pointa;
}

Forme* Bloc::getForme()
{
    return m_forme;
}

void Bloc::setForme(Forme*forme)
{
    m_forme=forme;
}

void Bloc::calculeVecteur()
{
    if(m_pointa.getCote()=="Haut")
    {
        m_pointa.getVec()->getPd()->setX(*(m_pointa.getTLX()));//
        m_pointa.getVec()->getPd()->setY(*(m_pointa.getTLY()));
        m_pointa.getVec()->setdX(cos((*(m_pointa.getRotB()))*(3.14159265/180))*m_pointa.getLoB());
        m_pointa.getVec()->setdY(sin((*(m_pointa.getRotB()))*(3.14159265/180))*m_pointa.getLoB());
    }

    if(m_pointa.getCote()=="Gauche")
    {
        m_pointa.getVec()->getPd()->setX(*(m_pointa.getTLX()));
        m_pointa.getVec()->getPd()->setY(*(m_pointa.getTLY()));
        m_pointa.getVec()->setdY(cos((*(m_pointa.getRotB()))*(3.14159265/180))*m_pointa.getLaB());
        m_pointa.getVec()->setdX((-sin((*(m_pointa.getRotB()))*(3.14159265/180)))*m_pointa.getLaB());
    }

    if(m_pointa.getCote()=="Bas")
    {
        m_pointa.getVec()->getPd()->setX((*(m_pointa.getTLX()))-(sin((*(m_pointa.getRotB()))*(3.14159265/180))*m_pointa.getLaB()));
        m_pointa.getVec()->getPd()->setY((*(m_pointa.getTLY()))+(cos((*(m_pointa.getRotB()))*(3.14159265/180))*m_pointa.getLaB()));
        m_pointa.getVec()->setdX(cos((*(m_pointa.getRotB()))*(3.14159265/180))*m_pointa.getLoB());
        m_pointa.getVec()->setdY(sin((*(m_pointa.getRotB()))*(3.14159265/180))*m_pointa.getLoB());
    }

    if(m_pointa.getCote()=="Droite")
    {
        m_pointa.getVec()->getPd()->setX((*(m_pointa.getTLX()))+(cos((*(m_pointa.getRotB()))*(3.14159265/180))*m_pointa.getLoB()));
        m_pointa.getVec()->getPd()->setY((*(m_pointa.getTLY()))+(sin((*(m_pointa.getRotB()))*(3.14159265/180))*m_pointa.getLoB()));
        m_pointa.getVec()->setdY(cos((*(m_pointa.getRotB()))*(3.14159265/180))*m_pointa.getLaB());
        m_pointa.getVec()->setdX((-sin((*(m_pointa.getRotB()))*(3.14159265/180)))*m_pointa.getLaB());
    }


}

void Bloc::rotation(double angle,bool add)
{
    if(add)
        m_rot+=angle;
    else
        m_rot=angle;
    initall();
    if(m_attache.size()==0)
        return;

    for(size_t i=0;i<m_attache.size();++i )
        m_attache[i]->rotation(angle,add);
}


void Bloc::ajouterAttache(std::string nom,std::string couleur,
                          double rot,std::string pdaSource,double dist,std::string cote,double longueur,double largeur, size_t taille)
{
    Bloc *n=new Bloc;
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
    n->getPda()->setLaB(m_forme->getLa());
    n->getPda()->setLoB(m_forme->getLo());
    n->getPda()->setNom(pdaSource);
    n->getPda()->setTLX(m_forme->getpTLX());
    n->getPda()->setTLY(m_forme->getpTLY());
    n->getPda()->setPourcent(dist);
    n->init();

    n->getPda()->translation(dist, false);
    /*if(cote=="Haut")
    {
        if(pdaDest=="tl")
        n->m_pointa.translation(0,false);
        if(pdaDest=="tc")
        n->m_pointa.translation(50,false);
        if(pdaDest=="tr")
        n->m_pointa.translation(100,false);
    }

       if(cote=="Bas")
    {
        if(pdaDest=="bl")
         n->m_pointa.translation(0,false);
        if(pdaDest=="bc")
        n->m_pointa.translation(50,false);
        if(pdaDest=="br")
        n->m_pointa.translation(100,false);
    }

       if(cote=="Gauche")
    {
        if(pdaDest=="tl")
         n->m_pointa.translation(0,false);
        if(pdaDest=="ml")
        n->m_pointa.translation(50,false);
        if(pdaDest=="bl")
        n->m_pointa.translation(100,false);
    }

       if(cote=="Droite")
    {
        if(pdaDest=="tr")
         n->m_pointa.translation(0,false);
        if(pdaDest=="mr")
        n->m_pointa.translation(50,false);
        if(pdaDest=="br")
        n->m_pointa.translation(100,false);
    }*/
    m_attache.push_back(n);
}

void Bloc::init()
{
  calculeVecteur();

   m_pointa.getCoords()->setX(m_pointa.getVec()->getPd()->getX()+(m_pointa.getVec()->getdX()*(m_pointa.getPourcent()/100)) );
   m_pointa.getCoords()->setY(m_pointa.getVec()->getPd()->getY()+(m_pointa.getVec()->getdY()*(m_pointa.getPourcent()/100)) );

      if(m_pointa.getNom()=="tl")
  {
    m_forme->setTLX(m_pointa.getCoords()->getX());
    m_forme->setTLY(m_pointa.getCoords()->getY());
  }

  if(m_pointa.getNom()=="tc")
  {
    m_forme->setTLX(m_pointa.getCoords()->getX()- (cos(m_rot*(3.14159265/180))*(m_forme->getLo()/2)));
    m_forme->setTLY(m_pointa.getCoords()->getY()- (sin(m_rot*(3.14159265/180))*(m_forme->getLo()/2)));
  }

  if(m_pointa.getNom()=="tr")
  {
    m_forme->setTLX(m_pointa.getCoords()->getX()- (cos(m_rot*(3.14159265/180))*m_forme->getLo()));
    m_forme->setTLY(m_pointa.getCoords()->getY()- (sin(m_rot*(3.14159265/180))*m_forme->getLo()));
  }

  if(m_pointa.getNom()=="ml")
  {
    m_forme->setTLX(m_pointa.getCoords()->getX()+ (sin(m_rot*(3.14159265/180))*(m_forme->getLa()/2)));
    m_forme->setTLY(m_pointa.getCoords()->getY()- (cos(m_rot*(3.14159265/180))*(m_forme->getLa()/2)));
  }
  if(m_pointa.getNom()=="mc")
  {
    m_forme->setTLX(m_pointa.getCoords()->getX()- (cos(m_rot*(3.14159265/180))*(m_forme->getLo()/2))+ (sin(m_rot*(3.14159265/180))*(m_forme->getLa()/2)));
    m_forme->setTLY(m_pointa.getCoords()->getY()- (sin(m_rot*(3.14159265/180))*(m_forme->getLo()/2))- (cos(m_rot*(3.14159265/180))*(m_forme->getLa()/2)));
  }
  if(m_pointa.getNom()=="mr")
  {
    m_forme->setTLX(m_pointa.getCoords()->getX()- (cos(m_rot*(3.14159265/180))*m_forme->getLo())+ (sin(m_rot*(3.14159265/180))*(m_forme->getLa()/2)));
    m_forme->setTLY(m_pointa.getCoords()->getY()- (sin(m_rot*(3.14159265/180))*m_forme->getLo())- (cos(m_rot*(3.14159265/180))*(m_forme->getLa()/2)));
  }
  if(m_pointa.getNom()=="bl")
  {
    m_forme->setTLX(m_pointa.getCoords()->getX()+ (sin(m_rot*(3.14159265/180))*m_forme->getLa()));
    m_forme->setTLY(m_pointa.getCoords()->getY()- (cos(m_rot*(3.14159265/180))*m_forme->getLa()));
  }
  if(m_pointa.getNom()=="bc")
  {
    m_forme->setTLX(m_pointa.getCoords()->getX()- (cos(m_rot*(3.14159265/180))*(m_forme->getLo()/2))+ (sin(m_rot*(3.14159265/180))*m_forme->getLa()));
    m_forme->setTLY(m_pointa.getCoords()->getY()- (sin(m_rot*(3.14159265/180))*(m_forme->getLo()/2))- (cos(m_rot*(3.14159265/180))*m_forme->getLa()));
  }
  if(m_pointa.getNom()=="br")
  {
    m_forme->setTLX(m_pointa.getCoords()->getX()- (cos(m_rot*(3.14159265/180))*m_forme->getLo())+ (sin(m_rot*(3.14159265/180))*m_forme->getLa()));
    m_forme->setTLY(m_pointa.getCoords()->getY()- (sin(m_rot*(3.14159265/180))*m_forme->getLo())- (cos(m_rot*(3.14159265/180))*m_forme->getLa()));
  }
}

void Bloc::initall()
{
    init();

    if(m_attache.size()==0)
        return;

    for(size_t i=0;i<m_attache.size();++i )
        m_attache[i]->initall();
}

void Bloc::afficherVecteur(Svgfile& svgout)
{
    svgout.addLine(m_pointa.getVec()->getPd()->getX()
                   ,m_pointa.getVec()->getPd()->getY()
                   ,m_pointa.getVec()->getPd()->getX()+m_pointa.getVec()->getdX()
                   ,m_pointa.getVec()->getPd()->getY()+m_pointa.getVec()->getdY(),"red");

    svgout.addTriangle(m_pointa.getVec()->getPd()->getX()+(m_pointa.getVec()->getdX()*0.96)
                   ,m_pointa.getVec()->getPd()->getY()+(m_pointa.getVec()->getdY()*0.96)
                   ,m_pointa.getVec()->getPd()->getX()+m_pointa.getVec()->getdX()
                   ,m_pointa.getVec()->getPd()->getY()+m_pointa.getVec()->getdY(),"red");


}

void Bloc::afficherNom(Svgfile& svgout)
{
    svgout.addText(m_forme->getTLX()+(sin(m_rot*(3.14159265/180))*(m_forme->getLa()/2))+(cos(m_rot*(3.14159265/180))*(m_forme->getLo()/2))-(m_nom.size()),
                   m_forme->getTLY()+(cos(m_rot*(3.14159265/180))*(m_forme->getLa()/2))+(sin(m_rot*(3.14159265/180))*(m_forme->getLo()/2))+2, m_nom, "yellow");

}

Coords Bloc::getCoord()
{
    Coords a;

    if(( m_rot>=0 && m_rot<90 )|| (m_rot<=-270 && m_rot>-360 ))
    {
        a={m_forme->getTLX()-(sin(m_rot*(3.14159265/180))*m_forme->getLa()),m_forme->getTLY()};
    }

    if((m_rot>=90 && m_rot<180 )|| (m_rot<=-180 && m_rot>-270))
    {
         a= {m_forme->getTLX()-abs((sin(m_rot*(3.14159265/180))*m_forme->getLa()))-abs((cos(m_rot*(3.14159265/180))*m_forme->getLo()))
         ,m_forme->getTLY()-(abs((cos(m_rot*(3.14159265/180))*m_forme->getLa())))};
    }

    if((m_rot>=180 && m_rot<270 )|| (m_rot<=-90 && m_rot>-180))
    {
         a= {m_forme->getTLX()-(abs((cos(m_rot*(3.14159265/180))*m_forme->getLa())))
         ,m_forme->getTLY()-abs((sin(m_rot*(3.14159265/180))*m_forme->getLo()))-abs((cos(m_rot*(3.14159265/180))*m_forme->getLa()))};
    }

    if((m_rot>=270 && m_rot<360 )|| ( m_rot<=0 && m_rot>-90 ))
    {
          a= {m_forme->getTLX(),m_forme->getTLY()+(sin(m_rot*(3.14159265/180))*m_forme->getLo())};
    }

         return a;
}

double Bloc::getLa()
{
    return abs((cos(m_rot*(3.14159265/180))*m_forme->getLa()))+abs((m_forme->getLo()*sin(m_rot*(3.14159265/180)))) ;
}

double Bloc::getLo()
{
    return abs((cos(m_rot*(3.14159265/180))*m_forme->getLo()))+abs((m_forme->getLa()*sin(m_rot*(3.14159265/180)))) ;
}
