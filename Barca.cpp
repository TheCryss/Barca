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

bool Barca::vincularOrillaDerecha(Orilla *orilla)
{
  // Vincular el parametro al atributo orillaDerecha
  this->orillaDerecha = orilla;
  setEstaDerecha(true);
  // Vincular la barca a la orilla derecha
  orillaDerecha->vincularBarca(this);

  // Desvincular la orilla izquierda del atriuto orillaIzquierda
  if (orillaIzquierda)
  {
    desvincularOrillaIzquierda();
    // Desvincular la barca de la orilla izquierda
    orillaIzquierda->desvincularBarca();
  }

  return true;
}

bool Barca::vincularOrillaIzquierda(Orilla *orilla)
{
  // Vincular el parametro al atributo orillaIzquierda
  this->orillaIzquierda = orilla;
  setEstaIzquierda(true);
  // Vincular la barca a la orilla Izquierda
  orillaIzquierda->vincularBarca(this);

  // Desvincular la orilla derecha del atriuto orillaDerecha
  if (orillaDerecha)
  {
    desvincularOrillaDerecha();
    // Desvincular la barca de la orilla Derecha
    orillaDerecha->desvincularBarca();
  }

  return true;
}

void Barca::setEstaDerecha(bool estado)
{
  this->estaDerecha = estado;
}

void Barca::setEstaIzquierda(bool estado)
{
  this->estaIzquierda = estado;
}

// ? no se
void Barca::moverBarca(bool verificarConductor)
{
  // Se verifica que el conductor se encuentre en la barca a no ser que el parametro verificarConductor sea falso
  if (!this->existePersonajeConNombre("Robot") && verificarConductor)
  {
    throw "No hay ningun Robot subido en la barca. La barca no se mueve sola!!!";
  }
  // Se cambia la posicion de la barca y se redefinen los vecinos dependiendo de donde este situado
  if (this->estaIzquierda)
  {
    vincularOrillaDerecha(orillaDerecha);
    setPosicion(pos + 1);
  }
  else
  {
    vincularOrillaIzquierda(orillaIzquierda);
    setPosicion(pos - 1);
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
  // Vemos a cual orilla esta vinculada
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

void Barca::imprimirLugar()
{
  string tab = "";
  int auxPos = getPosicion();
  for (int i = 0; i < auxPos; i++)
  {
    tab += "\t";
  }
  cout << tab << getNombre() << " " << getPosicion();
}