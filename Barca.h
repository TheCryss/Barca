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
    int buscar(const string&);
    void moverBarca();
    int getPosicion();
    void limpiarBarca();

private:
    vector<string>barca;
    int posicion=0;

};

#endif // BARCA_H
