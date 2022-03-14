/**
Archivo: Personaje.cpp
Autores:
Carlos Andrés Hernández
<carlos.hernandez.agudelo@correounivalle.edu.co >
Susana Valencia Bravo <susana.valencia@correounivalle.edu.co>
Jose Luis Hincapie Bucheli <jose.bucheli@correounivalle.edu.co>
Sebastian Quintero Ramírez <sebastian.quintero.ramirez@correounivalle.edu.co>
Jose Antonio Fernandez <jose.antonio.fernandez@correounivalle.edu.co>
Fecha creacion: 2022/02/07
Fecha ultima modificacion: 2022/02/07
licencia: GNU-GPL
*/
#include "Personaje.h"
#include <stdio.h>

/*
  Si se pasa el nombre y personajeQueCome por parametro los asignamos a los atributos de la clase, mientras que el atirbuto estaVivo por defecto es verdadero
*/
Personaje::Personaje(string nombre, string comando) : nombre(nombre), comando(comando), estaVivo(true)
{
  if(comando.size()>2)
  {
    string aux;
    aux.push_back(getNombre().at(0));
    setComando(aux);
  }
}

/*
  Destructor, que debido a que la clase no tiene relaciones como es la de *conoce* , no haremos nada  en el constructor
*/
Personaje::~Personaje()
{
  for (Personaje *personaje : personajesQueCome)
  {
    if(personaje){
      delete personaje;
      personaje = nullptr;
    }
  }
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
vector <Personaje*> Personaje::getPersonajesQueCome()
{
  return this->personajesQueCome;
}

/*
  Obtener el valor del atributo estaVivo
*/
bool Personaje::getEstaVivo()
{
  return this->estaVivo;
}

/*
  Obtener el valor del atributo comando
*/
string Personaje::getComando()
{
  return this->comando;
}

/*
  Asignar un valor al atritbuto nombre
*/
void Personaje::setNombre(string nombre)
{
  this->nombre = nombre;
}

/*
  Asignar un personaje al vector personajesQueCome
*/
void Personaje::agregarPersonajeQueCome(Personaje *personajeQueCome)
{
  personajesQueCome.push_back(personajeQueCome);
}

/*
  Asignar un valor al atritbuto estado
*/
void Personaje::setEstaVivo(bool estado)
{
  this->estaVivo = estado;
}

/*
  Asignar un valor al atritbuto comando
*/
void Personaje::setComando(string comando)
{
  this->comando = comando;
}

/*
  Verififcar si el personaje puede comer o no, dado otro personaje pasado por parametro, y viendo que ambos esten en la misma posicion
*/
bool Personaje::puedeComer(Personaje *personaje)
{
  for(Personaje* personajeVector : personajesQueCome){
    if (personaje->getNombre() == personajeVector->getNombre())
    {
      personajeVector->setEstaVivo(false);
      return true;
    }
  }
  return false;
}