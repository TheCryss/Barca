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
  Personaje lechuga("Lechuga", "L");

  zorro.agregarPersonajeQueCome(&conejo);
  conejo.agregarPersonajeQueCome(&lechuga);

  vector<Personaje *> personajes = {&robot, &zorro, &conejo, &lechuga};

  orillaIzquierda.agregarPersonajes(personajes);

  Jugador miJuego(&barca, &orillaIzquierda, &orillaDerecha);

  miJuego.jugar();

  return 0;
}
