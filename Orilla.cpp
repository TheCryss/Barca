/**
Archivo: Orilla.cpp
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
#include "Orilla.h"
#include <stdio.h>

Orilla::Orilla(int pos, string nombre, int capacidad) : Lugar(pos, nombre, capacidad)
{
}

Orilla::~Orilla()
{
}

string Orilla::imprimirLugar()
{
  if (getNombre() == "Izquierda" || getNombre() == "IZQUIERDA" || getNombre() == "izquierda")
  {
    string aux = getNombre();
    return aux;
  }
  else
  {
    if (!getEstaVecino())
    {
      string aux = "\t\t" + getNombre();
      return aux;
    }
    else
    {
      string aux = "\t" + getNombre();
      return aux;
    }
  }
}