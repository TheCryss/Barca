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
Clase: Barca
Responsabilidad: Esta clase derivada de Lugar servira para hacer lo que hace su clase Padre (alamacenar personajes) y además poder hacer funciones con estos, como moverlos a la barca
Relaciones:
- Es parecido a Lugar
- Conoce a Personaje usando un vector de punteros a la clase
- Conoce a Orilla a traves de un puntero a la clase
*/

#ifndef _BARCA_H_
#define _BARCA_H_

#include "Lugar.h"
#include "Orilla.h"

class Orilla;

class Barca : public Lugar
{
  // Atributos
private:

public:
  // Constructor
  Barca(int pos=1, string nombre="Barca", int capacidad=2);
  // Destructor
  virtual ~Barca();
  /*
    moverBarca recibe la orillaIzquierda, la orillaDerecha y un parametro que nos servira para sabe si tenemos que verificar si esa el Robot o no para mover la barca, y lo que hara es mover la barca en una posicion u otra enlazandose con la orilla izquierda o la orilla derecha
  */
  void moverBarca(vector <Lugar*> *mapa, bool verificarConductor = true);

  virtual string imprimirLugar();
};

#endif