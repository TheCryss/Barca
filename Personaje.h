/*
Archivo: Personaje.h
Autores:
Carlos Hernandez
Susana
Jose Luis
Fecha creacion: 2022/02/07
Fecha ultima modificacion: 2022/02/07
licencia: GNU-GPL
*/

/**
Clase: Personaje
Responsabilidad: Modelar un personaje en el juego, con atributos como el nombre, el personaje que come o si esta vivo. Con esta clase representaremos al Robot, al Conejo, la Lechuga y al Zorro, y realmente a cualquier otro personaje que se quiera implementar.
Relaciones: Ninguna
*/

#ifndef _PERSONAJE_H_
#define _PERSONAJE_H_
#include <iostream>
using namespace std;

class Personaje
{
  // Atributos
protected:
  string nombre;
  string personajeQueCome;
  bool estaVivo;

public:
  // Constructor
  /*
    Tenemos dos constructores, para que así existan dos maneras de intanciar un objeto de la clase Personaje
  */
  Personaje(string nombre, string personajeQueCome="");
  Personaje();
  // Destructor
  virtual ~Personaje();
  // Getters
  virtual string getNombre();
  virtual string getPersonajeQueCome();
  virtual bool getEstaVivo();
  // Setters
  virtual void setNombre(string nombre);
  virtual void setPersonajeQueCome(string personajeQueCome);
  virtual void setEstaVivo(bool estado);
  // Funciones
  /*
    puedeComer : retorna true si el atributo nombre del personaje pasado por parametro coincide con el atributo personajeQueCome del personaje actual
  */
  virtual bool puedeComer(Personaje *personaje);
};

#endif