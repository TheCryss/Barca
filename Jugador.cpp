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
  totalPersonajes = orillaIzquierda->numeroDePersonajes();
}

Jugador::~Jugador()
{
  if (orillaIzquierda)
  {
    delete orillaIzquierda;
    orillaIzquierda = nullptr;
  }
  if (orillaDerecha)
  {
    delete orillaDerecha;
    orillaDerecha = nullptr;
  }
  if (barca)
  {
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

  // Se muestran los lugares
  // Se muestra orilla izquierda
  orillaIzquierda->imprimirLugar();

  barca->imprimirLugar();

  orillaDerecha->imprimirLugar();

  cout << endl;

  // Se muestran los individuos de cada lugar

  orillaIzquierda->imprimirPersonajes();
  orillaDerecha->imprimirPersonajes();
  barca->imprimirPersonajes();

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

void Jugador::recibirEntrada()
{
  string orden = recibirUnCaracter();
  if (orden == "B")
    barca->moverBarca(orillaIzquierda,orillaDerecha,true);

  else if (orden == "S")
    exit(0);

  else if (orden == "J")
    reiniciar();

  else
  {
    // realizar el movimiento de un personaje
    if (barca->moverPersonaje(orden))
    {
      return;
    }
    if (orillaIzquierda->moverPersonaje(orden))
    {
      return;
    }
    if (orillaDerecha->moverPersonaje(orden))
    {
      return;
    }
    throw "No hay ningun personaje que empiece con la letra " + orden;
  }
}

void Jugador::reiniciar()
{
  // regresa todos los individuos a la orilla izquierda
  barca->moverATodos(orillaIzquierda);
  orillaDerecha->moverATodos(orillaIzquierda);

  // regresa la barca al lado de la orilla izquierda
  if (barca->getPosicion() == 2)
  {
    barca->moverBarca(orillaIzquierda,orillaDerecha,false);
  }
}

bool Jugador::comprobarEstadoDelJuego()
{
  // se verifica si algun individuo ha podido comerse a otro

  // Para Derecha
  Personaje *personajeMuerto = orillaDerecha->algunPersonajeHaSidoComido();
  // throw "Personaje muerto : " + personajeMuerto->getNombre() + " ";
  if (personajeMuerto)
  {
    mostrarJuego();

    // Mensaje
    cout << "Se murio el " << personajeMuerto->getNombre() << endl;
    cout << endl;

    menuDespuesDeGanarOPerder();
  }

  // Para Izquierda
  personajeMuerto = orillaIzquierda->algunPersonajeHaSidoComido();
  // throw "Personaje muerto : " + personajeMuerto->getNombre() + " ";
  if (personajeMuerto)
  {
    mostrarJuego();

    // Mensaje
    cout << "Se murio el " << personajeMuerto->getNombre();

    menuDespuesDeGanarOPerder();
  }

  // Para Barca
  personajeMuerto = barca->algunPersonajeHaSidoComido();
  // throw "Personaje muerto : " + personajeMuerto->getNombre() + " ";
  if (personajeMuerto)
  {
    mostrarJuego();

    // Mensaje
    cout << "Se murio el " << personajeMuerto->getNombre();

    menuDespuesDeGanarOPerder();
  }

  // se verifica que todos los individuos han pasado a la orilla derecha
  if (orillaDerecha->numeroDePersonajes() == totalPersonajes)
  {
    mostrarJuego();
    cout << "HAS GANADO" << endl;
    menuDespuesDeGanarOPerder();
  }

  return true;
}

void Jugador::menuDespuesDeGanarOPerder()
{
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