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
       cout<<"Se Agrego: "<<personaje<<", Barca size: "<<barca.size()<<endl;
    }
}

void Barca::elminarPersonaje(const string &personaje)
{
    //cout<<personaje<<endl;
    cout<<"-----------------------------------------------------------------------------------"<<endl;
    vector<string>::iterator it;
    it=barca.begin();


    for(int i = 0; i<barca.size();i++)
    {
        if(barca[i]==personaje)
        cout<<"Se selecciono: "<<barca[i]<<" Personaje: "<<personaje<<endl;
        it+=i;
        barca.erase(it) ;
        //cout<<" Elemento que queda: "<<barca.front()<<" Barca size: "<<barca.size()<<endl;

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
    for(string personaje : barca)
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

