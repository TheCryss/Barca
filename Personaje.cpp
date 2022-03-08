/**
Archivo: Personaje.cpp
Autores:
Carlos Hernandez
Susana
Jose Luis
Fecha creacion: 2022/02/07
Fecha ultima modificacion: 2022/02/07
licencia: GNU-GPL
*/
#include "Personaje.h"
#include <stdio.h>

/*
  Si no se pasa nada por parametro al momento de instanciar personaje, inicializaremos el atributo nombre y personajeQueCome como vacío, por otra parte el atributo estaVivo por defecto sera verdadero
*/
Personaje::Personaje() : nombre(""), personajeQueCome(""), estaVivo(true)
{
}

/*
  Si se pasa el nombre y personajeQueCome por parametro los asignamos a los atributos de la clase, mientras que el atirbuto estaVivo por defecto es verdadero
*/
Personaje::Personaje(string nombre, string personajeQueCome) : estaVivo(true)
{
  this->nombre = nombre;
  this->personajeQueCome = personajeQueCome;
}

/*
  Destructor, que debido a que la clase no tiene relaciones como es la de *conoce* , no haremos nada  en el constructor
*/
Personaje::~Personaje()
{
}

/*
  Obtener el valor del atributo nombre
*/
string Personaje::getNombre()
{
  return this->nombre;
}

/*
  Obtener el valor del atributo personajeQueCome
*/
string Personaje::getPersonajeQueCome()
{
  return this->personajeQueCome;
}

/*
  Obtener el valor del atributo estaVivo
*/
bool Personaje::getEstaVivo()
{
  return this->estaVivo;
}

/*
  Asignar un valor al atritbuto nombre
*/
void Personaje::setNombre(string nombre)
{
  this->nombre = nombre;
}

/*
  Asignar un valor al atritbuto personajeQueCome
*/
void Personaje::setPersonajeQueCome(string personajeQueCome)
{
  this->personajeQueCome = personajeQueCome;
}

/*
  Asignar un valor al atritbuto estado
*/
void Personaje::setEstaVivo(bool estado)
{
  this->estaVivo = estado;
}

/*
  Verififcar si el personaje puede comer o no, dado otro personaje pasado por parametro
*/
bool Personaje::puedeComer(Personaje *personaje)
{
  if (personaje->getNombre() == getPersonajeQueCome())
  {
    return true;
  }
  return false;
}