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
      if (personaje->getNombre() == "Robot")
      {
        cout << textoVerde << lugar->imprimirPersonaje(personaje) << endl;
      }
      else
      {
        cout << textoGris << lugar->imprimirPersonaje(personaje) << endl;
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
  cout << textoGris "Ingrese una orden: ";
  getline(cin, orden);

  if (orden.size() == 0)
    throw(string) "¡No ha ingresado ninguna orden!";

  if (orden.size() > 2)
    throw(string) "¡Solo puedes ingresar dos letras como maximo!";

  orden[0] = toupper(orden[0]); // se convierte la orden de minúscula a mayúscula

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
    throw "No hay ningun personaje que empiece con la letra " + orden;
  }
}

void Jugador::reiniciar()
{
  // regresa todos los individuos a la orilla izquierda
  barca->moverATodos(mapa[0]);
  mapa[2]->moverATodos(mapa[0]);

  // regresa la barca al lado de la orilla izquierda
  if (barca->getPosicion() == 2)
  {
    barca->moverBarca(&mapa, false);
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
        cout << textoRojo "El personaje " << personaje->getNombre() << " esta muerto";
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
      cout << "Se murio el " << personajeMuerto->getNombre();

      menuDespuesDeGanarOPerder();
    }
  }

  // se verifica que todos los individuos han pasado a la orilla derecha
  if (mapa[2]->numeroDePersonajes() == totalPersonajes)
  {
    mostrarJuego();
    cout << "HAS GANADO" << endl;
    menuDespuesDeGanarOPerder();
  }

  return true;
}

void Jugador::menuDespuesDeGanarOPerder()
{
  cout << textoGris "Para salir del juego presione la letra para reiniciar presione la letra " << endl;

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