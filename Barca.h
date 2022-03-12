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
  Orilla *getOrillaIzquierda();
  Orilla *getOrillaDerecha();
  bool getEstaIzquierda();
  bool getEstaDerecha();
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
  Eliminar la relacion de la clase Barca a la clase Orilla por medio del puntero, para que así ya no apunte a la orilla derecha si no a un puntero nulo, además de setear el atributo estaOrillaDerecha a false
  */
  void desvincularOrillaDerecha();
  /*
  Eliminar la relacion de la clase Barca a la clase Orilla por medio del puntero, para que así ya no apunte a la orilla izquierda si no a un puntero nulo, además de setear el atributo estaOrillaIzquierda a false
  */
  void desvincularOrillaIzquierda();
  /*
    moverBarca recibe el mapa del juego (un array) e intercambia su posicion en él, así como tambien cambia las relaciones conoce de las orillas, para que estas sepan si estan enlazadas o no a la barca y cambia a sus atributos, para saber en que orilla esta la barca.
  */
  void moverBarca(Orilla *orillaIzquierda, Orilla *orillaDerecha, bool verificarConductor = true);
  /*
    Lo que hace es pasar el personaje que esta dentro del vector personajes cuyo nombre empieze con la primera letra pasada por parametro a la orilla que este enlazada la barca en ese momento
  */
  virtual bool moverPersonaje(string primeraLetra);

  // virtual string imprimirLugar();
};

#endif