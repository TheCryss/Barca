/*
Archivo: Jugador.h
Autores:
Carlos Hernandez
Susana
Jose Luis
Fecha creacion: 2022/02/07
Fecha ultima modificacion: 2022/02/07
licencia: GNU-GPL
*/

/**
Clase: Jugador
Responsabilidad: representa al jugador humano en el juego, es el objeto que tiene acceso a la consola, muestra el estado del juego y ejecuta las órdenes que recibe desde afuera
Relaciones:
- conoce a todos los Lugares por medio de un array de punteros a Jugador (mapa)
*/

#ifndef _JUGADOR_H_
#define _JUGADOR_H_

#include "Personaje.h"
#include "Barca.h"
#include "Orilla.h"

#include <time.h>
#include <array>
#include <string>

class Jugador
{
  // Atributos
protected:
  Orilla *orillaIzquierda;
  Orilla *orillaDerecha;
  Barca *barca;
  int totalPersonajes;

public:
  /*
    Constructor
  */
  Jugador(Barca *barca, Orilla *orillaIzquierda, Orilla *orillaDerecha);
  /*
    Destructor
  */
  virtual ~Jugador();
  /*
    jugar inicia el juego y tomar el control del programa.
  */
  virtual void jugar();
  /*
    mostrarJuego imprime en consola el estado actual del juego
  */
  virtual void mostrarJuego();

  /*
    recibirEntrada recibe por consola los comandos a ejecutar
  */
  virtual void recibirEntrada();

  /*
    reiniciar permite regresar todos los lugares e individuos al estado inicial
  */
  virtual void reiniciar();

  /*
    comprobarEstadoDelJuego determinar despues de cada movimiento si se ganó o se perdió
  */
  virtual bool comprobarEstadoDelJuego();
  /*
    menuDespuesDeGanarOPerder muestra las opciones de reiniciar o salir
    cuando se gana o pierde
  */
  virtual void menuDespuesDeGanarOPerder();
  /*
    recibirUnCaracter recibe la entrada por consola
  */
  virtual string recibirUnCaracter();
};

#endif