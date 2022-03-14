/**
Archivo: Barca.cpp
Autores:
Carlos Hernandez
Susana
Jose Luis
Fecha creacion: 2022/02/07
Fecha ultima modificacion: 2022/02/07
licencia: GNU-GPL
*/
#include "Barca.h"

Barca::Barca(int pos , string nombre , int capacidad ) : Lugar(pos, nombre, capacidad)
{
}

Barca::~Barca()
{
}


void Barca::moverBarca(vector<Lugar *> *mapa, bool verificarConductor)
{
  Lugar *orillaIzquierda = (*mapa)[0];
  Lugar *orillaDerecha = (*mapa)[2];
  // Se verifica que el conductor se encuentre en la barca a no ser que el parametro verificarConductor sea falso
  if (!this->existePersonajeConNombre(getGuardian()) && verificarConductor)
  {
    throw "No hay ningun " + this->guardian + " subido en la barca. La barca no se mueve sola!!!";
  }


  // Se redefinen los vecinos dependiendo de donde este situado y se cambia la posicion de la barca
  if (vecino == orillaIzquierda)
  {
    orillaIzquierda->desvincularVecino();
    this->vincularVecino(orillaDerecha);
    orillaDerecha->vincularVecino(this);
    setPosicion(2);
  }
  else
  {
    orillaDerecha->desvincularVecino();
    this->vincularVecino(orillaIzquierda);
    orillaIzquierda->vincularVecino(this);
    setPosicion(1);
  }
}

string Barca::imprimirLugar()
{
  string tab = "";
  int auxPos = getPosicion();
  for (int i = 0; i < auxPos; i++)
  {
    tab += "\t";
  }
  tab += getNombre();
  return tab;
}
