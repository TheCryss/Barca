/**
Archivo: Barca.cpp
Autores:
Carlos Hernandez
Susana
Jose Luis
Fecha creacion: 2022/02/07
Fecha ultima modificacion: 2022/02/07
licencia: GNU-GPL
*/
#include "Barca.h"

Barca::Barca(string nombre, int capacidad) : Lugar(nombre, capacidad)
{
  this->estaDerecha = false;
  this->estaIzquierda = false;
  this->orillaDerecha = nullptr;
  this->orillaIzquierda = nullptr;
  this->pos = 2;
}

Barca::Barca() : Lugar()
{
  this->estaDerecha = false;
  this->estaIzquierda = false;
  this->orillaDerecha = nullptr;
  this->orillaIzquierda = nullptr;
  this->pos = 2;
  this->nombre = "Barca";
  this->capacidad = 2;
}

Barca::~Barca()
{
  if (orillaDerecha)
  {
    delete orillaDerecha;
    orillaDerecha = nullptr;
  }
  if (orillaIzquierda)
  {
    delete orillaIzquierda;
    orillaIzquierda = nullptr;
  }
}

Orilla *Barca::getOrillaDerecha()
{
  if (orillaDerecha)
  {
    return this->orillaDerecha;
  }
  else
  {
    return nullptr;
  }
}

Orilla *Barca::getOrillaIzquierda()
{
  if (orillaIzquierda)
  {
    return this->orillaIzquierda;
  }
  else
  {
    return nullptr;
  }
}

bool Barca::getEstaDerecha()
{
  return this->estaDerecha;
}

bool Barca::getEstaIzquierda()
{
  return this->estaIzquierda;
}

void Barca::desvincularOrillaDerecha()
{
  delete this->orillaDerecha;
  this->orillaDerecha = nullptr;
}

void Barca::desvincularOrillaIzquierda()
{
  delete this->orillaIzquierda;
  this->orillaIzquierda = nullptr;
}

void Barca::vincularOrillaDerecha(Orilla *orilla)
{
  setEstaIzquierda(false);
  setEstaDerecha(true);
  setPosicion(2);
  orillaDerecha = orilla;
}

void Barca::vincularOrillaIzquierda(Orilla *orilla)
{
  setEstaIzquierda(true);
  setEstaDerecha(false);
  setPosicion(1);
  orillaIzquierda = orilla;
}

void Barca::setEstaDerecha(bool estado)
{
  this->estaDerecha = estado;
}

void Barca::setEstaIzquierda(bool estado)
{
  this->estaIzquierda = estado;
}

void Barca::moverBarca(Orilla *orillaIzquierdam, Orilla *orillaDerecha, bool verificarConductor)
{
  // Se verifica que el conductor se encuentre en la barca a no ser que el parametro verificarConductor sea falso
  if (!this->existePersonajeConNombre("Robot") && verificarConductor)
  {
    throw "No hay ningun " + this->guardian + " subido en la barca. La barca no se mueve sola!!!";
  }

  // Se cambia la posicion de la barca y se redefinen los vecinos dependiendo de donde este situado
  if (this->estaIzquierda)
  {
    vincularOrillaDerecha(orillaDerecha);
    orillaDerecha->vincularBarca(this);
    orillaIzquierda->desvincularBarca();
  }
  else
  {
    vincularOrillaIzquierda(orillaIzquierda);
    orillaIzquierda->vincularBarca(this);
    orillaDerecha->desvincularBarca();
  }
}

bool Barca::moverPersonaje(string primeraLetra)
{
  int personajeAMover = buscarPorLetra(primeraLetra);

  // Si no encontro al individuo retornamos false
  if (personajeAMover == -1)
  {
    return false;
  }
  if (getEstaDerecha())
  {
    if (orillaDerecha->agregarPersonajeBooleano(personajes[personajeAMover]))
    {
      personajes.erase(personajes.begin() + personajeAMover);
      return true;
    }
    else
    {
      // Significa que la orilla ya esta llena
      throw(string) "La orilla esta llena... No caben más";
    }
  }
  if (getEstaIzquierda())
  {
    if (orillaIzquierda->agregarPersonajeBooleano(personajes[personajeAMover]))
    {
      personajes.erase(personajes.begin() + personajeAMover);
      return true;
    }
    else
    {
      // Significa que la orilla ya esta llena
      throw(string) "La orilla esta llena... No caben más";
    }
  }
  // Si no esta vinculada a ninguna orilla retornamos false
  return false;
}
