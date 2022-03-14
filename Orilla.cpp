/**
Archivo: Orilla.cpp
Autores:
Carlos Hernandez
Susana
Jose Luis
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
    return getNombre();
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