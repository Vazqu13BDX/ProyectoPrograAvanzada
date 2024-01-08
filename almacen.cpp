#include "almacen.h"
#include <QtWidgets>


Almacen::Almacen(QWidget *parent):QWidget(parent)
{
    informacionL= new QLabel("Almacen de Latas");
    informacionL->setGeometry(10,100,100,100);
    barra= new QProgressBar{this};
    barra->setRange(0,60);
    barra->setValue(0);
    barra->setGeometry(10,30,30,200);
    barra->setOrientation(Qt::Vertical);


    informacionL1= new QLabel("Almacen de Botellas");
    informacionL1->setGeometry(220,100,100,100);
    barra1= new QProgressBar{this};
    barra1->setRange(0,20);
    barra1->setValue(0);
    barra1->setGeometry(200,30,30,200);
    barra1->setOrientation(Qt::Vertical);




}
Almacen::~Almacen()
{

}
