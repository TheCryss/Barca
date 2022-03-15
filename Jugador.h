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
Responsabilidad: Representa al jugador humano en el juego, es el objeto que tiene acceso a la consola, muestra el estado del juego y ejecuta las órdenes que recibe desde afuera
Relaciones:
- Contiene a Lugar : Por medio de un vector a punteros de la clase Lugar
- Conoce a barca : Con el fin de llamar al metodo propio de la barca (moverBarca)
*/

#ifndef _JUGADOR_H_
#define _JUGADOR_H_

// Definimos los colores que se utilizaran para la consola
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

// #include <time.h>
#include <string>

class Jugador
{
  // Atributos
protected:
  vector<Lugar *> mapa;
  Barca *barca;
  int totalPersonajes;
  bool estaJuegoIniciado = true;

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
    Obtener el valor del atributo estaJuegoIniciado
  */
  virtual bool getEstaJuegoIniciado();
  /*
    Darle un valor al atibuto estaJuegoIniciado
  */
  virtual void setEstaJuegoIniciado(bool estado);
  /*
    Es la funcion que llama a casi todos los demás metodos con el fin de inicar el juego, comprobar el estado del mismo y leer las entradas
  */
  virtual void jugar();
  /*
  */
  virtual void inicio();
  /*
    Imprimir en consola un mensaje inicial del juego, los lugares y los personajes
  */
  virtual void mostrarJuego();
  /*
    recibir la entrada por teclado del usuario, sabiendo que solo puede digitar de una a dos letras, y pasando lo recibido a mayuscula para que el usuario pueda digitar el nombre del personaje tanto en mayuscula como minuscula
  */
  virtual string recibirCaracteres();
  /*
    Determinar que se hace con lo ingresado por el usuario, para mover la barca, reiniciar el juego, salir o mover el personaje, sabiendo que las opciones de salir y reiniciar no se pueden dar mientras el juego este iniciado.
  */
  virtual void recibirEntrada();
  /*
    reiniciar vuelve todo a su estado incial, con las relaciones iniciales, todos los personajes al lado izquierdo y vivos, a demás de que vuelve a setear el estado del juego en true pues si se llego a este punto es porque se perdio y estaba en false
  */
  virtual void reiniciar();

  /*
    comprueba que ningun personaje este muerto (haya saltado al agua), que ningun personaje ha comido a alguno, o que todos los personajes hayan llegado a la derecha, si alguno de esto sucede muestra el menu de ganar o perder correspondiente para salir o reiniciar el juego.
  */
  virtual bool comprobarEstadoDelJuego();
  /*
    Nos muestra las opciones que tenemos de salir o reiniciar el juego, además de recibir lo que el usuario digite por teclado para realizar la accion correspondiente.
  */
  virtual void menuDespuesDeGanarOPerder();
};

#endif