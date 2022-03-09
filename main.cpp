/**
Archivo: main.cpp
Autores:
Carlos Hernandez
Susana
Jose Luis
Fecha creacion: 2022/02/07
Fecha ultima modificacion: 2022/02/07
licencia: GNU-GPL
*/

/**
Historia: Queremos alojar los promedios de n estudiante, para luego mostrarlos
*/

#include "Personaje.h"
#include "Barca.h"
#include "Orilla.h"
#include "Jugador.h"
#include "Lugar.h"

#include <string>

// Funcion main
int main()
{
  // defino el mapa del juego, un array de 4 posiciones, y creo los objetos de su interior
  Orilla orillaIzquierda("IZQUIERDA");
  Barca barca; // El conductor y la capacidad de la barca se puede cambiar con el constructor.
  Lugar tramoDelRio;
  Orilla orillaDerecha("DERECHA");
  array<Lugar *, 4> mapa = {&orillaIzquierda, &barca, &tramoDelRio, &orillaDerecha};


  // defino los vecinos, es una simplificacion al uso del array mapa[4]
  orillaIzquierda.vincularBarca(&barca);
  barca.vincularOrillaIzquierda(&orillaIzquierda);


  // creo los objetos individuos del juego
  // Personaje robot("R2D2", "Robot");
  Personaje robot("Robot");
  Personaje zorro("Zorro");
  // Personaje conejo("Willy", "Conejo");
  Personaje conejo("Conejo");
  Personaje lechuga("Lechuga");

  // Personaje matias("Matias", "Conejo");
  // Personaje C3PO("C3PO", "Robot");
  // **EL NOMBRE DE LOS INDIVIDUOS TIENE QUE COMENZAR CON MAYÚSCULA**

  // defino la dieta de los individuos
  zorro.setPersonajeQueCome("Conejo");
  conejo.setPersonajeQueCome("Lechuga");
  // matias.agregarAlimentacion("Lechuga");


  // agrego los individuos al mapa
  // orillaIzquierda.agregarPersonajes((vector<Personaje *>){&robot, &zorro, &conejo, &lechuga, &matias, &C3PO});

  vector<Personaje *> auxPersonajes = {&robot, &zorro, &conejo, &lechuga} ;orillaIzquierda.agregarPersonajes(auxPersonajes);

  // inicio el juego y le cedo el control al Jugador
  Jugador laBarca(&mapa, &barca, &orillaIzquierda, &orillaDerecha);
  laBarca.jugar();

  return 0;
}
