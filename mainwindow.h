#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Zorro.h"
#include "Conejo.h"
#include "Lechuga.h"
#include "Robot.h"
#include "Barca.h"
#include <map>
#include "ui_mainwindow.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    bool cazar(int&,int&);

public slots:
    void handleButtonF();
    void handleButtonB();
    void handleButtonR();
    void handleButtonL();
    void changePlaceF();
    void changePlaceB();
    void changePlaceR();
    void changePlaceL();


private:
QPushButton *Conejo = new QPushButton;
QPushButton *Zorro = new QPushButton;
QPushButton *Lechuga = new QPushButton;
QPushButton *Robot = new QPushButton;

//map<int, string> posiciones;
int c=0;
int z=0;
int r=0;
int l=0;
Barca barca;

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
