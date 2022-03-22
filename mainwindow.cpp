#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setMinimumSize(size());
    this->setMaximumSize(size());

    class Lechuga *lechuga = new class Lechuga("Lechuga", "L", ui->Lechuga, ui->Lettuce,":/Lettuce.jpg");
    lechuga->imprimirImagen();
    connect(ui->Lechuga, SIGNAL (released()),this, SLOT (handleButtonL()));

    class Conejo *conejo = new class Conejo("Conejo", "C", ui->Conejo, ui->Bunny,":/bunny.png");
    conejo->imprimirImagen();
    connect(ui->Conejo, SIGNAL (released()),this, SLOT (handleButtonB()));

    class Zorro *zorro = new  class Zorro("Zorro", "Z", ui->Lobo, ui->Fox,":/fox.png");
    zorro->imprimirImagen();
    connect(ui->Lobo, SIGNAL (released()),this, SLOT (handleButtonF()));


    class Robot *robot =new class Robot("Robot", "R", ui->Robot, ui->Guardian,"a");
    robot->imprimirImagen();
    connect(ui->Robot, SIGNAL (released()),this, SLOT (handleButtonR()));

}


MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::handleButtonF()
{
    cout<<"Test Move Fox"<<endl;
    if(z==0)
    {
      ui->Fox->move(250,190);
      changePlaceF();
      if(cazar(z,c))
      {
          cout<<"El zorro se comio al conejo"<<endl;
      }

    } else if(z==1)
    {
      ui->Fox->move(80,190);
      changePlaceF();
      if(cazar(z,c))
      {
          cout<<"El zorro se comio al conejo"<<endl;
      }
    }


 //conejo->handleButton();
}

void MainWindow::handleButtonB()
{
    cout<<"Test Move Bunny"<<endl;
    if(c==0)
    {
      ui->Bunny->move(250,100);
      changePlaceB();
      if(cazar(c,l))
      {
          cout<<"El Conejo se comio a la lechuga"<<endl;
      }
      if(cazar(c,z))
      {
          cout<<"El Zorro se comio al Conejo"<<endl;
      }
    } else if(c==1)
    {
      ui->Bunny->move(80,100);
      changePlaceB();
      if(cazar(c,l))
      {
          cout<<"El Conejo se comio a la lechuga"<<endl;
      }
      if(cazar(c,z))
      {
          cout<<"El Zorro se comio al Conejo"<<endl;
      }
    }
}

void MainWindow::changePlaceB()
{
    switch (c)
    {
    case 0:
        c=1;
        break;
    case 1:
        c=0;
        break;
    }

}

void MainWindow::changePlaceF()
{
    switch (z)
    {
    case 0:
        z=1;
        break;
    case 1:
        z=0;
        break;
    }
}

void MainWindow::handleButtonL()
{
    cout<<"Test Move Lechuga"<<endl;
    if(l==0)
    {  
      ui->Lettuce->move(250,280);
      changePlaceL();
      if(cazar(l,c))
      {
          cout<<"El Conejo se comio a la lechuga"<<endl;
      }

    } else if(l==1)
    {
      ui->Lettuce->move(80,280);
      changePlaceL();
      if(cazar(l,c))
      {
          cout<<"El Conejo se comio a la lechuga"<<endl;
      }
    }


    //conejo->handleButton();
}

void MainWindow::handleButtonR()
{
    cout<<"Test Move Robot"<<endl;
    if(r==0)
    {
      ui->Guardian->move(250,390);
      changePlaceR();
      if(cazar(c,l))
      {
          cout<<"El Conejo se comio a la lechuga"<<endl;
      }
      if(cazar(c,z))
      {
          cout<<"El Zorro se comio al Conejo"<<endl;
      }
    } else if(r==1)
    {
      ui->Guardian->move(80,390);
      changePlaceR();
      if(cazar(c,l))
      {
          cout<<"El Conejo se comio a la lechuga"<<endl;
      }
      if(cazar(c,z))
      {
          cout<<"El Zorro se comio al Conejo"<<endl;
      }
    }
    //ui->Bunny->move(250,100);
}

void MainWindow::changePlaceR()
{
    switch (r)
    {
    case 0:
        r=1;
        break;
    case 1:
        r=0;
        break;
    }

}

void MainWindow::changePlaceL()
{
    switch (l)
    {
    case 0:
        l=1;
        break;
    case 1:
        l=0;
        break;
    }
}

bool MainWindow::cazar(int &a, int &b)
{
    if(a==b and a!=r)
    {
      return true;
    }else
    {
        return false;
    }
}
