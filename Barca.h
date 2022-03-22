#ifndef BARCA_H
#define BARCA_H
#include "Personaje.h"


class Barca
{
public:
    Barca();
    ~Barca();
    void agregarPersonaje(const string&);
    void elminarPersonaje(const string&);
    bool hayEspacio();
    bool sePuedeMover();
private:
    vector<string>barca;

};

#endif // BARCA_H
