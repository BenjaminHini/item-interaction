#ifndef COORDS_H_INCLUDED
#define COORDS_H_INCLUDED

class Coords
{
private:
    double m_x,m_y;
public:
    Coords(double, double);
    Coords();
    ~Coords()=default;
    double getX() const;
    double getY() const;
    void setX(double);
    void setY(double);
    friend Coords operator+(Coords, Coords);
    friend Coords operator-(Coords, Coords);
};

#endif // COORDS_H_INCLUDED
