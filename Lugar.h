/*
Archivo: Lugar.h
Autor: Carlos Hernandez
Fecha creacion: 2022/02/07
Fecha ultima modificacion: 2022/02/07
licencia: GNU-GPL
*/

/**
Clase: Lugar
Responsabilidad: Esta clase servira para almacenar un vector de estudiantes (los cuales llevan dentro un promedio)
*/

#ifndef _LUGAR_H_
#define _LUGAR_H_

#include "Personaje.h"
#include <iostream>
using namespace std;
#include <vector>;

class Lugar
{
  // Atributos
protected:
  string nombre;
  vector<Personaje *> personajes;
  int capacidad;
  const string guardian = "Robot";
  bool estaGuardian;

public:
  // Constructor
  Lugar(string nombre, int capacidad);
  Lugar();
  // Destructor
  virtual ~Lugar();
  // Getters
  virtual string getNombre();
  virtual vector<Personaje *> *getPersonajes();
  virtual int getCapacidad();
  virtual string getGuardian();
  virtual bool getEstaGuardian();
  // Setters
  virtual void setNombre(string nombre);
  virtual void setCapacidad(int capacidad);
  virtual void setEstaGuardian(bool estado);
  // Funciones
  virtual int numeroDePersonajes();
  virtual void agregarPersonaje(Personaje *personaje);
  virtual void agregarPersonajes(vector<Personaje *> personajes);
  virtual Personaje *getPersonajePorIndice(int indice);
  virtual bool existePersonajeConNombre(string nombre);
  virtual void moverATodos(Lugar *lugarDestino);
  virtual void verificarGuardian();
  virtual Personaje *algunPersonajeASidoComido();
  virtual int buscarPorLetra(string primeraLetra);
};

#endif