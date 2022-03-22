#include "Barca.h"

Barca::Barca()
{
}

Barca::~Barca()
{
    /*
    for (int i = 0; i < barca.size(); i++)
      {
        if (barca[i])
        {
          delete barca[i];
          barca[i] = nullptr;
        }
      }*/
}
void Barca::agregarPersonaje(const string&personaje)
{
    if(barca.size()>=2)
    {
       cout<<"La barca esta llena"<<endl;
    } else
    {
       barca.push_back(personaje);
       cout<<"Se Agrego, Barca size: "<<barca.size()<<endl;
    }
}

void Barca::elminarPersonaje(const string &personaje)
{

    for(int i = 0; i<barca.size();i++)
    {
        if(barca[i]==personaje)
        barca.erase(barca.begin()+i);
        cout<<"Se elimino, Barca size: "<<barca.size()<<endl;
        break;
    }
}
bool Barca::hayEspacio()
{
    if(barca.size()<2)
    {
        return true;
    } else
    {
        return false;
    }
}

bool Barca::sePuedeMover()
{
    for(const string &personaje : barca)
    {
        if(personaje=="Robot")
        {
            return true;
            break;
        }else
        {
            return false;
        }
    }


    return false;
}

