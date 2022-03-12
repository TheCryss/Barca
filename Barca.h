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
  Orilla *orillaIzquierda;
  Orilla *orillaDerecha;

  bool estaIzquierda;
  bool estaDerecha;

public:
  // Constructor
  Barca(string nombre = "Barca", int capacidad = 2);
  Barca();
  // Destructor
  virtual ~Barca();
  // Getters
  bool getEstaIzquierda();
  bool getEstaDerecha();
  Orilla *getOrillaDerecha();
  Orilla *getOrillaIzquierda();
  // Setters
  void setEstaIzquierda(bool estado);
  void setEstaDerecha(bool estado);
  // Metodos
  /*
    Asignar al atributo orillaIzquieda de la clase Barca un puntero de la clase Orilla pasado por parametro, y a su vez setear el atributo estaOrillaIzquierda  a true.
  */
  void vincularOrillaIzquierda(Orilla *orilla);
  /*
  Asignar al atributo orillaDerecha de la clase Barca un puntero de la clase Orilla pasado por parametro, y a su vez setear el atributo estaOrillaDerecha  a true.
  */
  void vincularOrillaDerecha(Orilla *orilla);
  /*
    Eliminamos la realcion con la orilla derecha
  */
  void desvincularOrillaDerecha();
  /*
    Eliminamos la realcion con la orilla izquierda
  */
  void desvincularOrillaIzquierda();
  /*
    moverBarca recibe la orillaIzquierda, la orillaDerecha y un parametro que nos servira para sabe si tenemos que verificar si esa el Robot o no para mover la barca, y lo que hara es mover la barca en una posicion u otra enlazandose con la orilla izquierda o la orilla derecha
  */
  void moverBarca(Orilla *orillaIzquierda, Orilla *orillaDerecha, bool verificarConductor = true);
  /*
    Lo que hace es pasar el personaje que esta dentro del vector personajes cuyo nombre empieze con la primera letra pasada por parametro a la orilla que este enlazada la barca en ese momento
  */
  virtual bool moverPersonaje(string primeraLetra);
};

#endif