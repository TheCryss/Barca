/*
Archivo: Orilla.h
Autor: Carlos Hernandez
Fecha creacion: 2022/02/07
Fecha ultima modificacion: 2022/02/07
licencia: GNU-GPL
*/

/**
Clase: Barca
Responsabilidad: Esta clase derivada de Lugar servira para hacer lo que hace su clase Padre (alamacenar personajes) y además poder hacer funciones con estos, como moverlos a la barca
Relaciones:
- es parecido a un Lugar
*/

#ifndef _BARCA_H_
#define _BARCA_H_

#include "Lugar.h"
#include "Orilla.h"
#include <array>

class Barca : public Lugar
{
  // Atributos
private:
  Orilla *orillaIzquierda;
  Orilla *orillaDerecha;
  bool estaIzquierda;
  bool estaDerecha;

public:
  // Constructor
  Barca(string nombre = "Barca", int capacidad = 2);
  // Destructor
  virtual ~Barca();
  // Getters
  Orilla *getOrillaIzquierda();
  Orilla *getOrillaDerecha();
  bool getEstaIzquierda();
  bool getEstaDerecha();
  // Setters
  void setEstaIzquierda(bool estado);
  void setEstaDerecha(bool estado);
  // Metodos
  void moverBarca(array<Lugar *, 4> *mapa, bool verificarConductor = true);
  bool vincularOrillaIzquierda(Orilla *orilla);
  bool vincularOrillaDerecha(Orilla *orilla);
  bool desvincularOrillaIzquierda();
  bool desvincularOrillaDerecha();
  bool moverBarca(string primeraLetra);
  void moverIndividuoAOrillaCercana(string primeraLetra);
};

#endif