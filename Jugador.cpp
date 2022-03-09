/**
Archivo: Jugador.cpp
Autores:
Carlos Hernandez
Susana
Jose Luis
Fecha creacion: 2022/02/07
Fecha ultima modificacion: 2022/02/07
licencia: GNU-GPL
*/
#include "Jugador.h"

Jugador::Jugador(Barca *barca, Orilla *orillaIzquierda, Orilla *orillaDerecha) : barca(barca), orillaIzquierda(orillaIzquierda), orillaDerecha(orillaDerecha)
{
}

Jugador::~Jugador()
{
  if(orillaIzquierda){
    delete orillaIzquierda;
    orillaIzquierda = nullptr;
  }
  if(orillaDerecha){
    delete orillaDerecha;
    orillaDerecha = nullptr;
  }
  if(barca){
    delete barca;
    barca = nullptr;
  }
}

// void Jugador::jugar()
// {
//   do
//   {
//     mostrarJuego();

//     while (true)
//     {
//       // Recibe entradas hasta que sea valida
//       try
//       {
//         recibirEntrada();
//         break;
//       }
//       catch (string mensaje)
//       {
//         cout << mensaje << endl;
//       }
//     }
//   } while (comprobarEstadoDelJuego());
// }

void Jugador::mostrarJuego()
{
  // Limpiar la consoa
  cout << "\033c";
  // ! Mirar otra forma de hacerlo

  cout << "\033[1;44;38;2;255;155;0mJUEGO LA BARCA\033[0m" << endl;
  cout << "El juego consiste en pasar todos los personajes de un lado del rio al otro." << endl
       << endl;
  cout << "Para mover un personaje presione la primera letra de su nombre. Para mover la Barca presione \033[1;36mB\033[0m. Para salir presione la letra \033[1;36mS\033[0m, para reiniciar el juego presione la letra \033[1;36mJ\033[0m." << endl;
  cout << "Recuerde: la Barca solamente se moverá si hay un \033[1;36mRobot\033[0m en ella." << endl;
  cout << "\033[38;2;255;0;0m!Tenga cuidado!\033[0m si un individuo se come a otro, pierde! " << endl
       << endl;

  // Se muestran los lugares
  // Se muestra orilla izquierda
  string tab = "\t";
  int auxPos = orillaIzquierda->getPosicion();
  for(int i = 0; i<auxPos*1 ; i++){
    tab+=tab;
  }
  cout << tab << orillaIzquierda->getNombre();

  // Se muestra barca
  tab = "\t";
  auxPos = barca->getPosicion();
  for (int i = 0; i < auxPos*1; i++)
  {
    tab += tab;
  }
  cout << tab << barca->getNombre();

  // Se muestra orilla derecha
  tab = "\t";
  auxPos = orillaDerecha->getPosicion();
  for (int i = 0; i < auxPos*1; i++)
  {
    tab += tab;
  }
  cout << tab << orillaDerecha->getNombre();

  cout << endl;

  // Se muestran los individuos de cada lugar

  // Personajes de Izquierda
  for(Personaje* personaje : *orillaIzquierda->getPersonajes()){
    string tab = "\t";
    int auxPos = orillaIzquierda->getPosicion();
    for (int i = 0; i < auxPos*1; i++)
    {
      tab += tab ;
    }
    cout << tab << personaje->getNombre() << endl;
  }

  // Personajes de Barca
  for (Personaje *personaje : *barca->getPersonajes())
  {
    string tab = "\t";
    int auxPos = barca->getPosicion();
    for (int i = 0; i < auxPos*1; i++)
    {
      tab += tab;
    }
    cout << tab << personaje->getNombre() << endl;
  }

  // Personajes de Derecha
  for (Personaje *personaje : *orillaDerecha->getPersonajes())
  {
    string tab = "\t";
    int auxPos = orillaDerecha->getPosicion();
    for (int i = 0; i < auxPos*1; i++)
    {
      tab += tab;
    }
    cout << tab << personaje->getNombre() << endl;
  }
  cout << endl;
}
