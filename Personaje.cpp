/**
Archivo: Personaje.cpp
Autor: Carlos Hernandez
Fecha creacion: 2022/02/07
Fecha ultima modificacion: 2022/02/07
licencia: GNU-GPL
*/
#include "Personaje.h"
#include <stdio.h>

Personaje::Personaje() : nombre(""), personajeQueCome(""), estaVivo(true)
{
}

Personaje::Personaje(string nombre, string personajeQueCome) : estaVivo(true)
{
  this->nombre = nombre;
  this->personajeQueCome = personajeQueCome;
}

Personaje::~Personaje()
{
}

string Personaje::getNombre()
{
  return this->nombre;
}

string Personaje::getPersonajeQueCome()
{
  return this->personajeQueCome;
}

bool Personaje::getEstaVivo()
{
  return this->estaVivo;
}

void Personaje::setNombre(string nombre)
{
  this->nombre = nombre;
}

void Personaje::setPersonajeQueCome(string personajeQueCome)
{
  this->personajeQueCome = personajeQueCome;
}

void Personaje::setEstaVivo(bool estado)
{
  this->estaVivo = estado;
}

bool Personaje::puedeComer(Personaje *personaje)
{
  if (personaje->getNombre() == getPersonajeQueCome())
  {
    return true;
  }
  return false;
}