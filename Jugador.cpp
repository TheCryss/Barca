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

Jugador::Jugador(array<Lugar *, 4> *mapa, Barca *barca, Orilla *orillaIzquierda, Orilla *orillaDerecha) : mapa(mapa), barca(barca), orillaIzquierda(orillaIzquierda), orillaDerecha(orillaDerecha)
{
  consoleRowSize = (*mapa)[0]->numeroDePersonajes();
}

Jugador::~Jugador()
{
  for (Lugar *lugar : *mapa)
  {
    if (lugar)
    {
      delete lugar;
      lugar = nullptr;
    }
  }
}

void Jugador::jugar()
{
  do
  {
    mostrarJuego();

    while (true)
    {
      // Recibe entradas hasta que sea valida
      try
      {
        recibirEntrada();
        break;
      }
      catch (string mensaje)
      {
        cout << mensaje << endl;
      }
    }
  } while (comprobarEstadoDelJuego());
}

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
  for (Lugar *lugar : *mapa)
  {
    string nombre = lugar->getNombre();
    if (lugar == barca)
    {
      cout << "| \033[1;38;2;210;105;30m" + nombre + "\033[0m" + string(consoleColumnSize - nombre.size(), ' ');
    }
    else
    {
      cout << "| \033[1;38;2;185;255;0m" + nombre + "\033[0m" + string(consoleColumnSize - nombre.size(), ' ');
    }
  }
  cout << "|" << endl;

  // Se muestran los individuos de cada lugar
  for (int j = 0; j < consoleRowSize; j++)
  {
    for (int i = 0; i < (*mapa).size(); i++)
    {
      Personaje *personaje = (*mapa)[i]->getPersonajePorIndice(j);
      if (personaje)
      {
        string nombre = personaje->getNombre();
        cout << "| " << nombre << string(consoleColumnSize - nombre.size(), ' ');
      }
      else
      {
        cout << "| " << string(consoleColumnSize, ' ');
      }
    }
    cout << "|" << endl;
  }
  cout << endl;
}

void Jugador::recibirEntrada()
{
  string orden = recibirUnCaracter();

  if (orden == "B")
  {
    barca->moverBarca(mapa);
  }
  else if (orden == "S")
  {
    exit(0);
  }
  else if (orden == "J")
  {
    reiniciar();
  }
  else
  {
    // realizar el movimiento de un personaje
    for (int i = 0; i < (*mapa).size(); i++)
    {
      if ((*mapa)[i]->moverPersonaje(orden))
        return;
    }
    throw "No hay ningun personaje que empiece con la letra " + orden;
  }
}

void Jugador::reiniciar()
{
  // Regresa todos los personajes a la orilla izquierda
  for (int i = 1; i < (*mapa).size(); i++)
  {
    (*mapa)[i]->moverATodos(orillaIzquierda);
  }
  // regresa la barca al lado de la orilla izquierda
  if ((*mapa)[2] == barca)
  {
    barca->moverBarca(mapa, false);
  }
}

bool Jugador::comprobarEstadoDelJuego(){
  // se verifica si algun individuo ha podido comerse a otro
  for(int i = 0; i < (*mapa).size();i++){
    Personaje *personajeMuerto = (*mapa)[i]->algunPersonajeHaSidoComido();
    if(personajeMuerto){
      mostrarJuego();

      // Mostramos el mesaje
      srand(time(NULL)); //[Instrucción que inicializa el generador de números aleatorios]
      int year = rand() % 10;
      cout << string((personajeMuerto->getNombre().size() + 7) / 2, ' ') + "\033[3mR.I.P." << endl;
      cout << "\033[4;38;2;150;150;150m-- \u2620  " + personajeMuerto->getNombre() + " \u2620  --\033[0m" << endl;
      cout << string((personajeMuerto->getNombre().size() + 3) / 2, ' ') + "200" << year << "-2020\n" << endl;
      cout << "\033[1;38;2;255;0;0m¡¡HAS PERDIDO!! \033[0m\n" << endl;

      menuDespuesDeGanarOPerder();
    }
  }

  // se verifica que todos los individuos han pasado a la orilla derecha
  int totalDeIndividuos = consoleRowSize;
  if(orillaDerecha->numeroDePersonajes()==totalDeIndividuos){
    mostrarJuego();
    cout << "\033[1;38;2;0;255;0m¡¡HAS GANADO!!\033[0m\n" << endl;
    menuDespuesDeGanarOPerder();
  }
  return true;
}

void Jugador::menuDespuesDeGanarOPerder(){
  cout << "Para salir del juego presione la letra \033[1;36mS\033[0m, para reiniciar presione la letra \033[1;36mJ\033[0m." << endl;

  string orden;
  try
  {
    orden = recibirUnCaracter();
  }
  catch (string mensaje)
  {
    exit(0);
  }

  if (orden == "S")
    exit(0);
  else if (orden == "J")
    reiniciar();
  else
    exit(0);
}

string Jugador::recibirUnCaracter(){
  string orden = "";
  cout << "Ingrese una orden: \033[1;38;2;61;242;234m";
  getline(cin, orden);
  cout << "\033[0m";

  if (orden.size() == 0)
    throw(string) "¡No ha ingresado ninguna orden!";

  if (orden.size() > 1)
    throw(string) "¡Solo puedes ingresar una letra!";

  orden[0] = toupper(orden[0]); // se convierte la orden de minúscula a mayúscula

  return orden;
}