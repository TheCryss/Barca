/**
Archivo: Lugar.cpp
Autores:
Carlos Hernandez
Susana
Jose Luis
Fecha creacion: 2022/02/07
Fecha ultima modificacion: 2022/02/07
licencia: GNU-GPL
*/
#include "Lugar.h"
#include <stdio.h>

Lugar::Lugar() : nombre(""), capacidad(-1), estaGuardian(false)
{
}

Lugar::Lugar(string nombre, int capacidad) : estaGuardian(false)
{
  this->nombre = nombre;
  this->capacidad = capacidad;
}

int Lugar::numeroDePersonajes()
{
  return personajes.size();
}

Lugar::~Lugar()
{
  for (int indexPersonaje = 0; indexPersonaje < numeroDePersonajes(); indexPersonaje++)
  {
    if (personajes[indexPersonaje])
    {
      delete personajes[indexPersonaje];
      personajes[indexPersonaje] = nullptr;
    }
  }
  personajes.clear();
}

string Lugar::getNombre()
{
  return nombre;
}

vector<Personaje *> *Lugar::getPersonajes()
{
  return &personajes;
}

int Lugar::getCapacidad()
{
  return capacidad;
}

string Lugar::getGuardian()
{
  return guardian;
}

bool Lugar::getEstaGuardian()
{
  return estaGuardian;
}

void Lugar::setNombre(string nombre)
{
  this->nombre = nombre;
}

void Lugar::setCapacidad(int capacidad)
{
  this->capacidad = capacidad;
}

void Lugar::setEstaGuardian(bool estado)
{
  this->estaGuardian = estado;
}

void Lugar::agregarPersonaje(Personaje *personaje)
{
  if (numeroDePersonajes() < getCapacidad() || getCapacidad() == -1)
  {
    personajes.push_back(personaje);
    // Una vez agregado el personaje verificamos si ese personaje es o no es guardian, para setearlo en el atributo estGuardian de la clase
    verificarGuardian();
  }
}

bool Lugar::agregarPersonajeBooleano(Personaje *personaje)
{
  if (numeroDePersonajes() < getCapacidad() || getCapacidad() == -1)
  {
    personajes.push_back(personaje);
    // Una vez agregado el personaje verificamos si ese personaje es o no es guardian, para setearlo en el atributo estGuardian de la clase
    verificarGuardian();
    return true;
  }
  return false;
}

bool Lugar::agregarPersonajes(vector<Personaje *> personajes)
{
  if (numeroDePersonajes() + personajes.size() < getCapacidad() || getCapacidad() == -1)
  {
    // Agregamos el vector de individuos
    for (Personaje *personaje : personajes)
    {
      agregarPersonaje(personaje);
    }
    return true;
  }
  else
  {
    return false;
  }
}

Personaje *Lugar::getPersonajePorIndice(int indice)
{
  if (indice >= 0 && indice < numeroDePersonajes())
  {
    return personajes[indice];
  }
  else
  {
    return nullptr;
  }
}

bool Lugar::existePersonajeConNombre(string nombre)
{
  // Busca un nombre en el vector de personajes
  for (Personaje *personaje : personajes)
  {
    if (personaje->getNombre() == nombre)
    {
      return true;
    }
  }
  return false;
}

void Lugar::moverATodos(Lugar *lugarDestino)
{
  lugarDestino->agregarPersonajes(personajes);
  // Limpiamos los personajes del vector actual
  for (int indexPersonaje = 0; indexPersonaje < numeroDePersonajes(); indexPersonaje++)
  {
    if (personajes[indexPersonaje])
    {
      delete personajes[indexPersonaje];
      personajes[indexPersonaje] = nullptr;
    }
  }
  //
  personajes.clear();
}

void Lugar::verificarGuardian()
{
  bool aux = false;
  for (Personaje *personaje : personajes)
  {
    if (personaje->getNombre() == getGuardian())
    {
      setEstaGuardian(true);
      aux = true;
    }
  }
  if (aux == false)
  {
    setEstaGuardian(false);
  }
}

Personaje *Lugar::algunPersonajeHaSidoComido()
{
  verificarGuardian();
  // Verificar si esta el robot
  if (getEstaGuardian())
  {
    return nullptr;
  }

  // Si no esta el robot pasa por cada individuo a ver si pudo comer
  for (int i = 0; i < numeroDePersonajes(); i++)
  {
    // se realiza la verificacion para las individuos por encima en el vector
    for (int j = 0; j <= i - 1; j++)
    {
      if (personajes[i]->puedeComer(personajes[j]))
      {
        personajes[j]->setEstaVivo(false);
        return personajes[j];
      }
    }
    // se realiza la verificacion para las individuos por debajo en el vector
    for (int j = i + 1; j < numeroDePersonajes(); j++)
    {
      if (personajes[i]->puedeComer(personajes[j]))
      {
        personajes[j]->setEstaVivo(false);
        return personajes[j];
      }
    }
  }
  // Si nadie pudo comer...
  return nullptr;
}

int Lugar::buscarPorLetra(string primeraLetra)
{
  // busca un individuo y compara su letra inicial con primeraLetra
  int index = 0;
  for (Personaje *personaje : personajes)
  {
    if (personaje->getNombre()[0] == primeraLetra[0])
    {
      return index;
    }
    else
    {
      index += 1;
    }
  }
  return -1;
}

bool Lugar::moverPersonaje(string primeraLetra)
{
}

void Lugar::vincularBarca(Lugar *barca)
{
}

void Lugar::desvincularBarca()
{
}