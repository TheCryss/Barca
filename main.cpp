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
  Orilla orillaIzquierda("Izquierda");
  orillaIzquierda.setPosicion(0);
  Barca barca("Barca",2);
  barca.setPosicion(1);
  Orilla orillaDerecha("Derecha");
  orillaDerecha.setPosicion(3);

  Personaje robot("Robot","");
  Personaje zorro("Zorro","Conejo");
  Personaje conejo("Conejo","Lechuga");
  Personaje lechuga("Lechuga","");

  vector <Personaje*> personajes = {&robot,&zorro,&conejo,&lechuga};

  orillaIzquierda.agregarPersonajes(personajes);


  Jugador miJuego(&barca,&orillaIzquierda,&orillaDerecha);

  miJuego.mostrarJuego();


  return 0;
}
