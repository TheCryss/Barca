/**
Archivo: main.cpp
Autores:
Carlos Andrés Hernández
<carlos.hernandez.agudelo@correounivalle.edu.co >
Susana Valencia Bravo <susana.valencia@correounivalle.edu.co>
Jose Luis Hincapie Bucheli <jose.bucheli@correounivalle.edu.co>
Sebastian Quintero Ramírez <sebastian.quintero.ramirez@correounivalle.edu.co>
Jose Antonio Fernandez <jose.antonio.fernandez@correounivalle.edu.co>
Fecha creacion: 2022/02/07
Fecha ultima modificacion: 2022/02/07
licencia: GNU-GPL
*/

/**
Historia: Queremos alojar los promedios de n estudiante, para luego mostrarlos
*/

#include "Personaje.h"
#include "Orilla.h"
#include "Jugador.h"
#include "Lugar.h"

#include <string>

// Funcion main
int main()
{
  Orilla orillaIzquierda(0, "Izquierda");
  Barca barca;
  Orilla orillaDerecha(3, "Derecha");

  barca.vincularVecino(&orillaIzquierda);
  orillaIzquierda.vincularVecino(&barca);

  Personaje robot("Robot", "R");
  Personaje zorro("Zorro", "Z");
  Personaje conejo("Conejo", "C");
  Personaje lechuga("Lechuga", "LE");

  // Personaje zorro2("Zorro2", "Z2");

  zorro.agregarPersonajeQueCome(&conejo);
  conejo.agregarPersonajeQueCome(&lechuga);

  vector<Personaje *> personajes = {&robot, &zorro, &conejo, &lechuga};
  // vector<Personaje *> personajes = {&robot, &zorro, &zorro2};

  orillaIzquierda.agregarPersonajes(personajes);

  Jugador miJuego(&barca, &orillaIzquierda, &orillaDerecha);

  miJuego.jugar();

  return 0;
}
