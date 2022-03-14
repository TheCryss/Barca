/**
Archivo: Jugador.cpp
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
#include "Jugador.h"

Jugador::Jugador(Barca *barca, Orilla *orillaIzquierda, Orilla *orillaDerecha) : barca(barca)
{
  totalPersonajes = orillaIzquierda->numeroDePersonajes();
  mapa.push_back(orillaIzquierda);
  mapa.push_back(barca);
  mapa.push_back(orillaDerecha);
}

Jugador::~Jugador()
{
  for (Lugar *lugar : mapa)
  {
    if (lugar)
    {
      delete lugar;
      lugar = nullptr;
    }
  }
  mapa.clear();
  // if (orillaIzquierda)
  // {
  //   delete orillaIzquierda;
  //   orillaIzquierda = nullptr;
  // }
  // if (orillaDerecha)
  // {
  //   delete orillaDerecha;
  //   orillaDerecha = nullptr;
  // }
  if (barca)
  {
    delete barca;
    barca = nullptr;
  }
}

void Jugador::mostrarJuego()
{
  // Limpiar la consoa
  cout << "\033c";

  cout << textoRojo "JUEGO LA BARCA" << endl;

  cout << textoGris "El juego consiste en pasar todos los personajes del rio al otro lado.... INSERTE MENSAJES" << endl;

  cout << endl;
  cout << endl;

  // Se muestran los lugares
  for (Lugar *lugar : mapa)
  {
    if (lugar->getNombre() == "Barca")
    {
      cout << textoSubrayadoAzul << lugar->imprimirLugar();
    }
    if (lugar->getNombre() == "Izquierda")
    {
      cout << textoSubrayadoPurpura << lugar->imprimirLugar();
    }
    if (lugar->getNombre() == "Derecha")
    {
      cout << textoSubrayadoVerde << lugar->imprimirLugar();
    }
  }

  cout << endl;
  cout << endl;

  // Se muestran los personajes de cada lugar
  for (Lugar *lugar : mapa)
  {
    for (Personaje *personaje : *lugar->getPersonajes())
    {
      if(personaje->getEstaVivo()==false){
        cout << textoSubrayadoRojo << lugar->imprimirPersonaje(personaje) << endl;
      }
      else if (personaje->getNombre() == "Robot")
      {
        cout << textoVerde << lugar->imprimirPersonaje(personaje) << endl;
      }
      else
      {
        cout << textoMarron << lugar->imprimirPersonaje(personaje) << endl;
      }
    }
  }

  cout << endl;
}

void Jugador::jugar()
{
  do
  {
    mostrarJuego();
    while (true) // Recibir las entradas hasta que sea valida
    {
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

string Jugador::recibirUnCaracter()
{
  string orden = "";
  cout << textoGris " Ingrese una orden: ";
  getline(cin, orden);

  if (orden.size() == 0)
    throw(string) " ¡No ha ingresado ninguna orden! ";

  if (orden.size() > 2)
    throw(string) " ¡Solo puedes ingresar dos letras como maximo! ";

  // Pasamos la orden a mayuscula
  for (int i = 0; i < orden.length(); i++)
  {
    // Y cambiar cada letra por su representación
    // mayúscula
    orden[i] = toupper(orden[i]);
  }
  // orden = toupper(orden); // se convierte la orden de minúscula a mayúscula

  return orden;
}

void Jugador::recibirEntrada()
{
  string orden = recibirUnCaracter();
  if (orden == "B")
    barca->moverBarca(&mapa);

  else if (orden == "S")
    exit(0);

  else if (orden == "J")
    reiniciar();

  else
  {
    // Realizar el movimiento de un personaje
    for (Lugar *lugar : mapa)
    {
      if (lugar->moverPersonaje(orden))
      {
        return;
      }
    }
    throw "No hay ningun personaje que tenga como comando: " + orden;
  }
}

void Jugador::reiniciar()
{
  // regresa todos los individuos a la orilla izquierda
  for (Lugar *lugar : mapa)
  {
    if (!(lugar->getNombre() == "Izquierda"))
    {
      lugar->moverATodos(mapa[0]);
    }
  }

  // Arreglar relaciones y posiciones
  mapa[0]->vincularVecino(barca);
  barca->vincularVecino(mapa[0]);
  barca->setPosicion(1);
  mapa[2]->desvincularVecino();

  // Ponemos a todos los personajes vivos
  for(Lugar* lugar : mapa){
    for(Personaje* personaje : *lugar->getPersonajes()){
      personaje->setEstaVivo(true);
    }
  }

}

bool Jugador::comprobarEstadoDelJuego()
{
  // Verifica que nadie este muerto
  for (Lugar *lugar : mapa)
  {
    for (Personaje *personaje : *lugar->getPersonajes())
    {
      if (personaje->getEstaVivo() == false)
      {
        mostrarJuego();
        // Mensaje
        // Texto obligatorio
        cout << textoRojo "PERDISTE" << endl;
        // Texto alternativo
        cout << textoRojo "El personaje " << personaje->getNombre() << " esta muerto, debido a que salto al agua. " << endl;
        menuDespuesDeGanarOPerder();
      }
    }
  }

  // se verifica si algun individuo ha podido comerse a otro
  for (Lugar *lugar : mapa)
  {
    Personaje *personajeMuerto = lugar->algunPersonajeHaSidoComido();
    if (personajeMuerto)
    {
      mostrarJuego();

      // Mensaje
      // Texto obligatorio
      cout << textoRojo "PERDISTE" << endl;
      // Texto alternativo
      cout << textoRojo "Se murio el " << personajeMuerto->getNombre() << endl;

      menuDespuesDeGanarOPerder();
    }
  }

  // se verifica que todos los individuos han pasado a la orilla derecha
  if (mapa[2]->numeroDePersonajes() == totalPersonajes)
  {
    mostrarJuego();
    // Texto obligatorio
    cout << "GANASTE" << endl;
    menuDespuesDeGanarOPerder();
  }

  return true;
}

void Jugador::menuDespuesDeGanarOPerder()
{
  cout << endl;
  cout << textoGris "Para salir del juego presione la letra " << textoAzul "S" << textoGris " para reiniciar presione la letra " << textoAzul "J" << endl;
  cout << endl;

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