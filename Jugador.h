/*
Archivo: Jugador.h
Autores:
Carlos Andrés Hernández
<carlos.hernandez.agudelo@correounivalle.edu.co >
Susana Valencia Bravo <susana.valencia@correounivalle.edu.co>
Jose Luis Hincapie Bucheli <jose.bucheli@correounivalle.edu.co>
Sebastian Quintero Ramírez <sebastian.quintero.ramirez@correounivalle.edu.co>
Jose Antonio Fernandez <jose.antonio.fernandez@correounivalle.edu.co>se Luis
Fecha creacion: 2022/02/07
Fecha ultima modificacion: 2022/02/07
licencia: GNU-GPL
*/

/**
Clase: Jugador
Responsabilidad: representa al jugador humano en el juego, es el objeto que tiene acceso a la consola, muestra el estado del juego y ejecuta las órdenes que recibe desde afuera
Relaciones:
- conoce a Orilla y a Barca por medio de punteros
*/

#ifndef _JUGADOR_H_
#define _JUGADOR_H_


// Para los colores
#define textoSubrayadoAzul "\e[4;34m"
#define textoSubrayadoPurpura "\e[4;35m"
#define textoSubrayadoVerde "\e[4;32m"
#define textoSubrayadoRojo "\e[4;31m"
#define textoVerde "\e[0;32m"
#define textoRojo "\e[0;31m"
#define textoMarron "\e[0;33m"
#define textoAzul "\e[0;34m"
#define textoPurpura "\e[0;35m"
#define textoGris "\e[0;3m"

#include "Personaje.h"
#include "Barca.h"
#include "Orilla.h"
#include "Lugar.h"

#include <time.h>
#include <string>

class Jugador
{
  // Atributos
protected:
  vector <Lugar*> mapa;
  // Orilla *orillaIzquierda;
  // Orilla *orillaDerecha;
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