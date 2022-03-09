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

#include "Barca.h"
#include "Lugar.h"


class Barca;
class Orilla : public Lugar
{
  // Atributos
private:
  Barca *barca;
  bool estaBarca;

public:
  // Constructor
  /*
    Tenemos dos constructores, para que así existan dos maneras de intanciar un objeto de la clase Orilla
  */
  Orilla(string nombre, int capacidad = -1);
  Orilla();
  // Destructor
  virtual ~Orilla();
  // Getters
  Barca *getbarca();
  bool getEstaBarca();
  // Setters
  void setEstaBarca(bool estado);
  // Metodos
  /*
    Asignar al atributo barca de la clase Orilla un puntero de la clase Barca pasado por parametro, y a su vez setear el atributo estaBarca a true.
  */
  void vincularBarca(Barca *barca);
  /*
    Eliminar la relacion de la clase Orilla a la clase Barca por medio del puntero, para que así ya no apunte a la barca si no a un puntero nulo, además de setear el atributo estaBarca a false
  */
  void desvincularBarca();
  /*
    Mover al personaje cuyo nombre empiece por la primera letra pasada por paramtero. Este personaje se mueve del vector personajes de la clase Orilla al vector de personajes de la clase Barca, siempre y cuando la relación con la Barca por medio del atributo no sea nula, pues si es nula significa que la barca esta en la otra orilla
  */
  bool moverPersonaje(string primeraLetra);
};

#endif