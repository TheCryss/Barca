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

  if (barca)
  {
    delete barca;
    barca = nullptr;
  }
}

bool Jugador::getEstaJuegoIniciado()
{
  return estaJuegoIniciado;
}

void Jugador::setEstaJuegoIniciado(bool estado)
{
  estaJuegoIniciado = estado;
}

void Jugador::inicio()
{

  system("cls");
  cout << textoPurpura "Bienvenido al Juego de La Barca \nA continuación veras las opciones que puedes elegir, por favor digite la opción que desea" << endl;
  cout << endl;
  cout << endl;

  bool estado = true;

  while (estado)
  {
    string orden = "";
    cout << textoGris "Jugar : 1 \nSalir : 0 \n\nOpcion: ";
    getline(cin, orden);

    if (orden == "1")
    {
      estado = false;
      jugar();
    }
    else if (orden == "0")
    {
      estado = false;
      exit(0);
    }
    else
    {
      cout << textoPurpura "Ingrese un valor valido" << endl;
    }
  }
}

void Jugador::personalizado()
{
  system("cls");
  cout << textoRojo "Bienvenido al modo personalizado, por favor lea atentamente y digite lo que se le pida, gracias. " << endl;

  // Borramos los personajes de los lugares que estan actualmente
  for (Lugar *lugar : mapa)
  {
    for (Personaje *personaje : lugar->getPersonajes())
    {
      if (personaje)
      {
        delete personaje;
        personaje = nullptr;
      }
    }
    lugar->getPersonajes().clear();
  }

  // Creamos y añadimos los guadianes
  string aux;
  string aux2;
  int numero;

  cout << "Digite el numero de guardianes en el juego: ";
  getline(cin, aux);
  numero = stoi(aux);

  for (int i = 0; i < numero; i++)
  {
    system("cls");
    cout << "¿Cual será el nombre del guardian? : ";
    getline(cin, aux);
    cout << "¿Cual será el comando del guardian " << aux << " ?";
    getline(cin, aux2);
    // Creamos el guardian y lo agregamos en cada lugar como guardian, a demás de almaenarlo en la izquierda
    Personaje *personaje = new Personaje(aux, aux2);
    mapa[0]->agregarPersonaje(personaje);
    for (Lugar *lugar : mapa)
    {
      lugar->agregarGuardian(personaje);
    }
    delete personaje;
    personaje = nullptr;
  }

  // Creamos y añadimos los personajes
  system("cls");
  cout << "Digite el numero de personajes en el juego: ";
  getline(cin, aux);
  numero = stoi(aux);

  for (int i = 0; i < numero; i++)
  {
    system("cls");
    cout << "¿Cual será el nombre del personaje? : ";
    getline(cin, aux);
    cout << "¿Cual será el comando del personaje " << aux << " ?";
    getline(cin, aux2);
    // Creamos el personaje y lo almacenamos en la izquierda
    Personaje *personaje = new Personaje(aux, aux2);
    mapa[0]->agregarPersonaje(personaje);
    delete personaje;
    personaje = nullptr;
  }

  // Creamos las relaciones entre personajes (quien come a quien)
  for (Personaje *personaje : mapa[0]->getPersonajes())
  {
    bool esGuardian = false;
    for (Personaje *guardian : mapa[0]->getGuardianes())
    {
      if (personaje->getNombre() == guardian->getNombre())
      {
        esGuardian = true;
      }
    }
    if (!esGuardian)
    {
      bool estado = true;
      while (estado)
      {
        system("cls");
        cout << "¿Desea agregar un personaje que come para el personaje" << personaje->getNombre() << " ? (S/N): ";
        getline(cin, aux);

        // Pasamos aux a mayuscula
        for (int i = 0; i < aux.length(); i++)
        {
          aux[i] = toupper(aux[i]);
        }

        // Decidimos que hacer con la relacion
        if (aux == "N")
        {
          estado = false;
        }
        else if (aux == "S")
        {
          cout << "Posibles Personajes: " << endl;
          for (Personaje *personajeAux : mapa[0]->getPersonajes())
          {
            if (personajeAux->getNombre() != personaje->getNombre())
            {
              for (Personaje *guardian : mapa[0]->getGuardianes())
              {
                if (personajeAux->getNombre() != guardian->getNombre())
                {
                  cout << personajeAux->getNombre() << endl;
                }
              }
            }
          }
          cout << endl;
          bool estadoAux = true;
          while (true)
          {
            cout << " ¿Digite el nombre del personaje que comera? : ";
            getline(cin, aux2);
            if (mapa[0]->existePersonajeConNombre(aux2))
            {
              bool estado2 = true;
              for (Personaje *guardian : mapa[0]->getGuardianes())
              {
                if (aux2 == guardian->getNombre())
                {
                  cout << "El nombre coincide con un guardian, esa relacion no es posible" << endl;
                  estado2 = false;
                }
              }
              for (Personaje *personajeV : mapa[0]->getPersonajes())
              {
                if (aux2 == personajeV->getNombre())
                {
                  cout << "El nombre coincide con el nombre del mismo personaje, en que piensas" << endl;
                  aux2 = false;
                }
              }
              if (estado2)
              {
                personaje->agregarPersonajeQueCome(mapa[0]->buscarPorNombre(aux2));
                estadoAux = false;
              }
            }
            else
            {
              cout << "¡No existe ese nombre! " << endl;
            }
          }
        }
        else
        {
          cout << "Digite una opcion valida";
        }
      }
    }
  }
}

void Jugador::mostrarJuego()
{
  // Limpiar la consoa
  // cout << "\033c";
  system("cls");

  cout << textoRojo "LA BARCA" << endl;
  cout << textoPurpura "Tu mision es pasar a cada uno de los personajes al lado derecho, sin que ninguno muera" << endl;
  cout << endl;
  cout << textoPurpura "Aquellos personajes en verde son " << textoVerde "guardianes" << textoPurpura ", los que estan en naranja son " << textoMarron "personajes normales" << endl;
  cout << textoPurpura "Recuerde que la barca solo se movera si hay un" << textoVerde " guardian dentro" << endl;
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
    for (Personaje *personaje : lugar->getPersonajes())
    {
      bool aux = true;
      if (!personaje->getEstaVivo())
      {
        cout << textoSubrayadoRojo << lugar->imprimirPersonaje(personaje) << endl;
        aux = false;
      }
      else
      {
        for (Personaje *guardian : barca->getGuardianes())
        {
          if (personaje->getNombre() == guardian->getNombre())
          {
            cout << textoVerde << lugar->imprimirPersonaje(personaje) << endl;
            aux = false;
          }
        }
      }
      if (aux == true)
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

string Jugador::recibirCaracteres()
{
  string orden = "";
  cout << textoGris " Ingrese una orden: ";
  getline(cin, orden);

  if (orden.size() == 0)
    throw(string) textoPurpura " ¡No ha ingresado ninguna orden! ";

  if (orden.size() > 2)
    throw(string) textoPurpura " ¡Solo puedes ingresar dos letras como maximo! ";

  // Pasamos la orden a mayuscula
  for (int i = 0; i < orden.length(); i++)
  {
    orden[i] = toupper(orden[i]);
  }

  return orden;
}

void Jugador::recibirEntrada()
{
  string orden = recibirCaracteres();
  if (orden == "B")
  {
    barca->moverBarca(&mapa);
  }
  else if (!getEstaJuegoIniciado())
  {
    if (orden == "S")
    {
      exit(0);
    }
    else if (orden == "J")
    {
      reiniciar();
    }
  }
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
    throw textoPurpura "No hay ningun personaje que tenga como comando: " + orden;
  }
}

void Jugador::reiniciar()
{
  setEstaJuegoIniciado(true);
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
  for (Lugar *lugar : mapa)
  {
    for (Personaje *personaje : lugar->getPersonajes())
    {
      personaje->setEstaVivo(true);
    }
  }
}

bool Jugador::comprobarEstadoDelJuego()
{
  // Verifica que nadie este muerto
  for (Lugar *lugar : mapa)
  {
    for (Personaje *personaje : lugar->getPersonajes())
    {
      if (personaje->getEstaVivo() == false)
      {
        setEstaJuegoIniciado(false);
        mostrarJuego();
        // Mensaje
        // Texto obligatorio
        cout << textoRojo "PERDISTE" << endl;
        // Texto alternativo
        cout << textoPurpura "El personaje " << textoRojo << personaje->getNombre() << textoPurpura " salto al algua, que desgracia... " << endl;
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
      setEstaJuegoIniciado(false);
      mostrarJuego();
      // Mensaje
      // Texto obligatorio
      cout << textoRojo "PERDISTE" << endl;
      // Texto alternativo
      cout << textoPurpura "El personaje " << textoRojo << personajeMuerto->getNombre() << textoPurpura " ha sido cruelmente devorado..." << endl;

      menuDespuesDeGanarOPerder();
    }
  }

  // se verifica que todos los individuos han pasado a la orilla derecha
  if (mapa[2]->numeroDePersonajes() == totalPersonajes)
  {
    setEstaJuegoIniciado(false);
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
  cout << textoPurpura "Para salir del juego presione la letra " << textoAzul "S" << textoPurpura " para reiniciar presione la letra " << textoAzul "J" << endl;
  cout << endl;

  string orden;
  try
  {
    orden = recibirCaracteres();
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