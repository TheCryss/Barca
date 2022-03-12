/**
Archivo: Orilla.cpp
Autores:
Carlos Hernandez
Susana
Jose Luis
Fecha creacion: 2022/02/07
Fecha ultima modificacion: 2022/02/07
licencia: GNU-GPL
*/
#include "Orilla.h"
#include <stdio.h>

Orilla::Orilla() : Lugar()
{
  this->estaBarca = false;
  this->barca = nullptr;
}

Orilla::Orilla(string nombre, int capacidad) : Lugar(nombre, capacidad)
{
  this->estaBarca = false;
  this->barca = nullptr;
}

Orilla::~Orilla()
{
  if (barca)
  {
    delete barca;
    barca = nullptr;
  }
}

Barca *Orilla::getbarca()
{
  if (barca)
  {
    return this->barca;
  }
  else
  {
    return nullptr;
  }
}

bool Orilla::getEstaBarca()
{
  return this->estaBarca;
}

void Orilla::setEstaBarca(bool estado)
{
  this->estaBarca = estado;
}

void Orilla::vincularBarca(Barca *barca)
{
  this->barca = barca;
  setEstaBarca(true);
}

void Orilla::desvincularBarca()
{
  setEstaBarca(false);
}

bool Orilla::moverPersonaje(string primeraLetra)
{
  int personajeAMover = buscarPorLetra(primeraLetra);

  // Si no encontro al individuo retornamos false
  if (personajeAMover == -1)
  {
    return false;
  }
  // Si no existe una barca vinculada singinifica que la barca esta al otro lado del rio
  if (!getEstaBarca())
  {
    throw personajes[personajeAMover]->getNombre() + " no puede saltar al rio ";
  }
  // Agregamos el personaje a la barca
  if (barca->agregarPersonajeBooleano(personajes[personajeAMover]))
  {
    // Borramos el personaje de este lugar
    personajes.erase(personajes.begin() + personajeAMover);
    return true;
  }
  else
  {
    // Significa que la barca ya esta llena
    throw(string) "La barca esta llena... No se puede subir nadie más";
  }
}

string Orilla::imprimirLugar(Barca *barca)
{
  if (getNombre() == "Izquierda" || getNombre() == "IZQUIERDA" || getNombre() == "izquierda")
  {
    return getNombre();
  }
  else
  {
    if (barca->getPosicion() == 1)
    {
      string aux = "\t\t" + getNombre();
      return aux;
    }
    else
    {
      string aux = "\t" + getNombre();
      return aux;
    }
  }
}