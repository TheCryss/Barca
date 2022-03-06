/*
Archivo: Personaje.h
Autor: Carlos Hernandez
Fecha creacion: 2022/02/07
Fecha ultima modificacion: 2022/02/07
licencia: GNU-GPL
*/

/**
Clase: Personaje
Responsabilidad: Esta clase servira para almacenar un vector de estudiantes (los cuales llevan dentro un promedio)
*/

#ifndef _PERSONAJE_H_
#define _PERSONAJE_H_
#include <iostream>
using namespace std;

class Personaje
{
  // Atributos
protected:
  string nombre;
  string personajeQueCome;
  bool estaVivo;

public:
  // Constructor
  Personaje(string nombre, string personajeQueCome);
  Personaje();
  // Destructor
  virtual ~Personaje();
  // Getters
  virtual string getNombre();
  virtual string getPersonajeQueCome();
  virtual bool getEstaVivo();
  // Sttets
  virtual void setNombre(string nombre);
  virtual void setPersonajeQueCome(string personajeQueCome);
  virtual void setEstaVivo(bool estado);
  // Funciones
  virtual bool puedeComer(Personaje *personaje);
};

#endif