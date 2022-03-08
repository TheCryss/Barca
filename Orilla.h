/*
Archivo: Orilla.h
Autor: Carlos Hernandez
Fecha creacion: 2022/02/07
Fecha ultima modificacion: 2022/02/07
licencia: GNU-GPL
*/

/**
Clase: Orilla
Responsabilidad: Esta clase derivada de Lugar servira para hacer lo que hace su clase Padre (alamacenar personajes) y además poder hacer funciones con estos, como moverlos a la barca
Relaciones:
*/

#ifndef _ORILLA_H_
#define _ORILLA_H_

#include "Lugar.h"

class Orilla : public Lugar
{
  // Atributos
private:
  Lugar *barca;
  bool estaBarca;

public:
  // Constructor
  Orilla(string nombre, int capacidad);
  Orilla();
  // Destructor
  virtual ~Orilla();
  // Getters
  Lugar* getbarca();
  bool getEstaBarca();
  // Setters
  void setEstaBarca(bool estado);
  // Metodos
  bool vincularBarca(Lugar* barca);
  bool desvincularBarca();
  bool moverPersonajeABarca(string primeraLetra);
};

#endif