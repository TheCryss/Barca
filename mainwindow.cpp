#include "mainwindow.h"
//#include "Zorro.h"
//#include <QCoreApplication>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Personaje *conejo = new class Conejo("Conejo", "C", ui->Conejo, ui->Bunny,":/bunny.png");
    conejo->imprimirImagen();
    connect(ui->Conejo, SIGNAL (released()),this, SLOT (handleButtonB()));


    Personaje *zorro = new  class Zorro("Zorro", "Z", ui->Lobo, ui->Fox,":/fox.png");
    zorro->imprimirImagen();
    connect(ui->Lobo, SIGNAL (released()),this, SLOT (handleButtonF()));

    Personaje *lechuga = new class Lechuga("Lechuga", "L", ui->Lechuga, ui->Lettuce,":/Lettuce.jpg");
    lechuga->imprimirImagen();
    connect(ui->Lechuga, SIGNAL (released()),this, SLOT (handleButtonL()));

    Personaje *robot = new class Robot("Robot", "R", ui->Robot, ui->Guardian,":/Robot.png");
    robot->imprimirImagen();
    connect(ui->Robot, SIGNAL (released()),this, SLOT (handleButtonR()));


/*
    QPixmap  pix1(":/fox.png");
    ui->Fox->setPixmap(pix1.scaled(100,100,Qt::KeepAspectRatio));
*/
    //connect(ui->Lobo, SIGNAL (released()),this, SLOT (handleButtonX(x)));

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
    } else if(z==1)
    {
      ui->Fox->move(80,190);
      changePlaceF();
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
    } else if(c==1)
    {
      ui->Bunny->move(80,100);
      changePlaceB();
    }
    //ui->Bunny->move(250,100);
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
    } else if(l==1)
    {
      ui->Lettuce->move(80,280);
      changePlaceL();
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
    } else if(r==1)
    {
      ui->Guardian->move(80,390);
      changePlaceR();
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
