/*
Archivo: Personaje.h
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

/**
Clase: Personaje
Responsabilidad: Modelar un personaje en el juego, con atributos como el nombre, el personaje que come o si esta vivo. Con esta clase representaremos al Robot, al Conejo, la Lechuga y al Zorro, y realmente a cualquier otro personaje que se quiera implementar.
Relaciones:
- Contiene a Personaje : A través de un vector de punteros a la clase Personaje
*/

#ifndef _LECHUGA_H_
#define _LECHUGA_H_
#include "Personaje.h"

using namespace std;

class Lechuga : public Personaje
{
  // Atributos
protected:

public:
  // Constructor : Si el comando es mayor a dos letras pasara a valer la primera letra del nombre
  Lechuga(string nombre, string comando, QPushButton* boton, QLabel *etiqueta, string url);
  // Destructor
  virtual ~Lechuga();
  // Cosas de QT
  virtual void imprimirImagen();
  virtual void handleButton();

};

#endif
