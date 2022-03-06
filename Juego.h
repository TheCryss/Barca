/*
Archivo: Juego.h
Autor: Carlos Hernandez
Fecha creacion: 2022/02/07
Fecha ultima modificacion: 2022/02/07
licencia: GNU-GPL
*/

/**
Clase: Juego
Responsabilidad: Esta clase servira para almacenar un vector de estudiantes (los cuales llevan dentro un promedio)
*/

#ifndef _JUEGO_H_
#define _JUEGO_H_
#include <iostream>
#include <vector>
#include "Personaje.h"
using namespace std;

class Juego
{
  // Atributos
private:
public:
  vector <Personaje*> personajes;
  // Constructor
  Juego();
  // Destructor
  virtual ~Juego();
  // Funciones
};

#endif