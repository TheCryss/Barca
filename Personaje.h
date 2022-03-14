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
#include <vector>
using namespace std;

class Personaje
{
  // Atributos
protected:
  string nombre;
  string comando;
  vector<Personaje *> personajesQueCome;
  bool estaVivo;

public:
  // Constructor
  Personaje(string nombre, string comando);
  // Destructor
  virtual ~Personaje();
  // Getters
  virtual string getNombre();
  virtual vector<Personaje *> getPersonajesQueCome();
  virtual bool getEstaVivo();
  virtual string getComando();
  // Setters
  virtual void setNombre(string nombre);
  virtual void setEstaVivo(bool estado);
  virtual void setComando(string comando);
  // Funciones
  virtual void agregarPersonajeQueCome(Personaje *personajeQueCome);
  /*
    puedeComer : retorna true si el atributo nombre del personaje pasado por parametro coincide con el atributo personajeQueCome del personaje actual
  */
  virtual bool puedeComer(Personaje *personaje);
};

#endif