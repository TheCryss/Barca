/**
Archivo: main.cpp
Autor: Carlos Hernandez
Fecha creacion: 2022/02/07
Fecha ultima modificacion: 2022/02/07
licencia: GNU-GPL
*/

/**
Historia: Queremos alojar los promedios de n estudiante, para luego mostrarlos
*/

#include "Personaje.h"
#include "Juego.h"
#include <string>

// Funcion main
int main()
{
  Juego miJuego;
  Personaje p;

  cout << miJuego.personajes.size() << endl;
  return 0;
}
