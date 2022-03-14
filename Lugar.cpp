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

Lugar::Lugar(int pos, string nombre, int capacidad) : estaGuardian(false), nombre(nombre), capacidad(capacidad), pos(pos), vecino(nullptr), estaVecino(false)
{
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
  if (vecino)
  {
    delete vecino;
    vecino == nullptr;
  }
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

int Lugar::getPosicion()
{
  return pos;
}

bool Lugar::getEstaVecino()
{
  return estaVecino;
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

void Lugar::setPosicion(int pos)
{
  this->pos = pos;
}

void Lugar::setEstaVecino(bool estado)
{
  this->estaVecino = estado;
}

bool Lugar::agregarPersonaje(Personaje *personaje)
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
  setEstaGuardian(false);
  lugarDestino->agregarPersonajes(personajes);
  // Limpiamos los personajes del vector actual
  for (Personaje* personaje : personajes)
  {
    if (personaje)
    {
      personaje = nullptr;
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
        return personajes[j];
      }
    }
    // se realiza la verificacion para las individuos por debajo en el vector
    for (int j = i + 1; j < numeroDePersonajes(); j++)
    {
      if (personajes[i]->puedeComer(personajes[j]))
      {
        return personajes[j];
      }
    }
  }
  // Si nadie pudo comer...
  return nullptr;
}

void Lugar::vincularVecino(Lugar *vecino)
{
  this->vecino = vecino;
  setEstaVecino(true);
}

void Lugar::desvincularVecino()
{
  if (vecino)
  {
    vecino = nullptr;
  }
  setEstaVecino(false);
}

int Lugar::buscarPorComando(string comando)
{
  // busca un individuo y compara su letra inicial con primeraLetra
  int index = 0;
  for (Personaje *personaje : personajes)
  {
    if (personaje->getComando() == comando)
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

bool Lugar::moverPersonaje(string comando)
{
  int indicePersonajeAMover = buscarPorComando(comando);

  // Si no encontro al personaje
  if (indicePersonajeAMover == -1)
  {
    return false;
  }

  // Si no hay ningun vecino significa que el personaje murio al tirarse al agua
  if (!getEstaVecino())
  {
    personajes[indicePersonajeAMover]->setEstaVivo(false);
    // Retornamos true para que el programa pueda seguir (debido a que se movio, pero al agua) y así nos aparezca que se muro el personaje
    return true;
    // throw personajes[indicePersonajeAMover]->getNombre() + " no puede saltar al rio"
  }
  else
  {
    // Agregamos un personaje al Lugar vecino
    if (vecino->agregarPersonaje(personajes[indicePersonajeAMover]))
    {
      // Borramos el personaje de este lugar
      personajes.erase(personajes.begin() + indicePersonajeAMover);
      return true;
    }
    else
    {
      // si la barca esta ocupada con 2 objetos
      throw(string) " La barca esta llena... Intentalo de nuevo ";
    }
  }
}

// string Lugar::imprimirLugar()
// {
//   string tab = "";
//   int auxPos = getPosicion();
//   for (int i = 0; i < auxPos; i++)
//   {
//     tab += "\t";
//   }
//   tab += getNombre();
//   return tab;
// }

string Lugar::imprimirPersonaje(Personaje *personaje)
{
  string tab = "";
  int auxPos = getPosicion();
  if (auxPos == 0)
  {
    return personaje->getNombre();
  }
  else if (auxPos == 1)
  {
    tab += "\t\t" + personaje->getNombre();
  }
  else if (auxPos == 2)
  {
    tab += "\t\t\t" + personaje->getNombre();
  }
  else
  {
    tab += "\t\t\t\t" + personaje->getNombre();
  }
  return tab;
}