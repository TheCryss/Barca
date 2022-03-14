/*
Archivo: Lugar.h
Autores:
Carlos Hernandez
Susana
Jose Luis
Fecha creacion: 2022/02/07
Fecha ultima modificacion: 2022/02/07
licencia: GNU-GPL
*/

/**
Clase: Lugar
Responsabilidad: Ser la clase padre de otras como Lugar y Barca. Además permite modelar un lugar, el cual contiene personajes por medio de un vector de punteros a un objeto de clase Personaje. Con esta clase podremos saber que personaje a sido comido, poder mover los personajes de un lugar a otro, verificar si esta el guarian (Robot) para hacer determinadas acciones o no, y demás metodos que involucre principalmente a Personajes.
Relaciones:
- Conoce a Personaje usando un vector de punteros a la clase
*/

#ifndef _LUGAR_H_
#define _LUGAR_H_

#include "Personaje.h"
#include <iostream>
using namespace std;
#include <vector>

class Lugar
{
  // Atributos
protected:
  vector<Personaje *> personajes;
  Lugar *vecino;
  bool estaVecino;
  string nombre;
  int capacidad;
  const string guardian = "Robot";
  bool estaGuardian;
  int pos;

public:
  // Constructor
  Lugar(int pos, string nombre, int capacidad);
  // Destructor
  virtual ~Lugar();
  // Getters
  virtual string getNombre();
  virtual vector<Personaje *> *getPersonajes();
  virtual int getCapacidad();
  virtual string getGuardian();
  virtual bool getEstaGuardian();
  virtual int getPosicion();
  virtual bool getEstaVecino();
  // Setters
  virtual void setNombre(string nombre);
  virtual void setCapacidad(int capacidad);
  virtual void setEstaGuardian(bool estado);
  virtual void setPosicion(int pos);
  virtual void setEstaVecino(bool estado);
  // Funciones
  /*
    Saber el numero de punteros a Personajes que hay en el vectore personajes
  */
  virtual int numeroDePersonajes();
  // /*
  //   Agregar un puntero de Personaje al vector personajes
  // */
  // virtual void agregarPersonaje(Personaje *personaje);
  /*
    Agregar un puntero de Personaje al vector personajes, con la diferencia de que si es posible (la capacidad no es excedida) retorna true, pero si no es posible (la capacidad es excedida) retorna true
  */
  virtual bool agregarPersonaje(Personaje *personaje);
  /*
    Agregar varios personajes al vector personajes, si es posible (la capcidad no es excedida) retorna true, si no es posible (la capacidad es excedida) retorna false
  */
  virtual bool agregarPersonajes(vector<Personaje *> personajes);
  /*
    Obtener el puntero a Personaje del vector personajes por medio del indice pasado por parametro : personajes[indice]
  */
  virtual Personaje *getPersonajePorIndice(int indice);
  /*
    Saber si dentro del vector personajes existe un personaje con el nombre pasado por parametro
  */
  virtual bool existePersonajeConNombre(string nombre);
  /*
    Mover a todos los personajes del vector a otro vector del lugar pasado por parametro y limpiar el vector del objeto actual, tanto a las relaciones como al vector en sí mismo
  */
  virtual void moverATodos(Lugar *lugarDestino);
  /*
    Verifica si el guardian esta o no esta en el vector personajes, en caso de estarlo setea el atributo estGuardian a true, en caso contrario setea el mismo atributo a false
  */
  virtual void verificarGuardian();
  /*
      Verificar si algun personaje dentro del vector Personajes ha sido comido, teniendo en cuenta que si el guardian esta en el Lugar nadie podrá ser comido ni podra comer. En caso de que el guardian no este se hace un for para recorrer a cada personaje, y dentro de este for se hacen a su vez otros dos ciclos for, uno para verificar los personajes por encima del personaje actual del vector, y otro para verificarlo por debajo.

    « : Por debajo
    » : Por encima
    £ : Actual

      Zorro     Conejo    Robot     Lechuga     Conejo    Zorro
      «           «        £          »           »         »

  */
  virtual Personaje *algunPersonajeHaSidoComido();
  /*
    Retornar -1 si no se encontro ningun Personaje dentro del vector cuyo nombre empiece con la primera letra pasado por parametro. Si lo encuentra, retorna el indice donde se encuentra el personaje dentro del vector.
  */
  virtual int buscarPorComando(string comando);

  /*
    Metodo para mover un personaje el cual solo retorna true pues son las clases hijas que van a definir realmente el metodo, pues este cambia si la clase es Barca u Orilla
  */
  virtual bool moverPersonaje(string comando);

  /*
    Imprimir el lugar dependiendo de la posicion de este. Supiendo que posicion=n, entonces pondra n tabs antes de mostrar el nombre del lugar
  */
  virtual string imprimirLugar() = 0;

  /*
    Imprimir el personaje dependiendo de la posicion del lugar en donde este personaje, por lo que pondra un numero determinado de tabs antes de imprimir el nombre del personaje
  */
  virtual string imprimirPersonaje(Personaje *personaje);

  virtual void vincularVecino(Lugar *vecino);
  virtual void desvincularVecino();
};

#endif