/*
Archivo: Orilla.h
Autores:
Carlos Hernandez
Susana
Jose Luis
Fecha creacion: 2022/02/07
Fecha ultima modificacion: 2022/02/07
licencia: GNU-GPL
*/

/**
Clase: Orilla
Responsabilidad: Esta clase derivada de Lugar servira para hacer lo que hace su clase Padre (alamacenar personajes) y además poder hacer funciones con estos, como moverlos a la barca.
Relaciones:
- Es parecido a Lugar
- Conoce a Personaje usando un vector de punteros a la clase
- Conoce a Barca a traves de un puntero
*/

#ifndef _ORILLA_H_
#define _ORILLA_H_

#include "Lugar.h"

class Orilla : public Lugar
{
  // Atributos
private:

public:
  // Constructor
  Orilla(int pos, string nombre, int capacidad = -1);
  // Destructor
  virtual ~Orilla();

  virtual string imprimirLugar();
};

#endif