/**
Archivo: Orilla.cpp
Autor: Carlos Hernandez
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

Lugar *Orilla::getbarca()
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

bool Orilla::vincularBarca(Lugar *barca)
{
  this->barca = barca;
  setEstaBarca(true);
  return true;
}

bool Orilla::desvincularBarca()
{
  if (barca)
  {
    delete barca;
    barca = nullptr;
    setEstaBarca(false);
  }
  return true;
}

bool Orilla::moverPersonajeABarca(string primeraLetra)
{
  int personajeAMover = buscarPorLetra(primeraLetra);

  // Si no encontro al individuo retornamos false
  if (personajeAMover == -1)
  {
    return false;
  }
  // Si no existe una barca vinculada singinifica que la barca esta al otro lado del rio
  if (!barca)
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
    throw(string) "La barca esta llena... Intentalo de nuevo";
  }
}