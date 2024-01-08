#include "envios.h"

Envios::Envios(QWidget *parent):QWidget(parent)
{
    barra= new QProgressBar{this};
    barra->setRange(0,100);
    barra->setValue(0);
    barra->setGeometry(600,10,200,30);
    barra->setOrientation(Qt::Horizontal);

}

Envios::~Envios()
{

}
