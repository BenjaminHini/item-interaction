#include "Coords.h"

Coords::Coords(double x, double y)
{
    m_x=x;
    m_y=y;
}

Coords::Coords()
{
    m_x=0;
    m_y=0;
}

double Coords::getX() const
{
    return m_x;
}

double Coords::getY() const
{
    return m_y;
}

void Coords::setX(double x)
{
    m_x=x;
}

void Coords::setY(double y)
{
    m_y=y;
}

Coords operator+(Coords a, Coords b)
{
    return{a.m_x+b.m_x, a.m_y+b.m_y};
}

Coords operator-(Coords a, Coords b)
{
    return{a.m_x-b.m_x, a.m_y-b.m_y};
}
