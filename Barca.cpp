/**
Archivo: Barca.cpp
Autor: Carlos Hernandez
Fecha creacion: 2022/02/07
Fecha ultima modificacion: 2022/02/07
licencia: GNU-GPL
*/
#include "Barca.h"
#include <stdio.h>

Barca::Barca(string nombre, int capacidad) : Lugar(nombre, capacidad)
{
  this->estaDerecha = false;
  this->estaIzquierda = false;
  this->orillaDerecha = nullptr;
  this->orillaIzquierda = nullptr;
}

Barca::~Barca()
{
  if(orillaDerecha){
    delete orillaDerecha;
    orillaDerecha = nullptr;
  }
  if (orillaIzquierda)
  {
    delete orillaIzquierda;
    orillaIzquierda = nullptr;
  }
}

Orilla* Barca::getOrillaDerecha(){
  if(orillaDerecha){
    return this->orillaDerecha;
  }else{
    return nullptr;
  }
}

Orilla *Barca::getOrillaIzquierda()
{
  if (orillaIzquierda)
  {
    return this->orillaIzquierda;
  }
  else
  {
    return nullptr;
  }
}

bool Barca::getEstaDerecha(){
  return this->estaDerecha;
}

bool Barca::getEstaIzquierda()
{
  return this->estaIzquierda;
}

bool Barca::vincularOrillaDerecha(Orilla *orilla){
  this->orillaDerecha = orilla;
  setEstaDerecha(true);
  orillaDerecha->vincularBarca(this);

  this->orillaIzquierda = nullptr;
  setEstaIzquierda(false);
  orillaIzquierda->desvincularBarca();
}

bool Barca::vincularOrillaIzquierda(Orilla *orilla)
{
  this->orillaIzquierda = orilla;
  setEstaIzquierda(true);
  orillaIzquierda->vincularBarca(this);

  this->orillaDerecha = nullptr;
  setEstaDerecha(false);
  orillaDerecha->desvincularBarca();
}

void Barca::setEstaDerecha(bool estado){
  this->estaDerecha = estado;
}

void Barca::setEstaIzquierda(bool estado)
{
  this->estaIzquierda = estado;
}

// ? no se
void Barca::moverBarca(array<Lugar *, 4> *mapa, bool verificarConductor = true){
  // Se verifica que el conductor se encuentre en la barca a no ser que el parametro verificarConductor sea falso
  if(!this->existePersonajeConNombre("Robot") && verificarConductor){
    throw "No hay ningun Robot subido en la barca. La barca no se mueve sola!!!";

    // Despues se barca la posicion de la barca en el mapa
    swap((*mapa)[1],(*mapa)[2]);

    // Se redefinen los vecinos en Barca
    if(this->estaIzquierda){
      vincularOrillaDerecha(orillaDerecha);
    }else{
      vincularOrillaIzquierda(orillaIzquierda); 
    }
  }
}
