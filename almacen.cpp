#include "almacen.h"
#include <QtWidgets>


Almacen::Almacen(QWidget *parent):QWidget(parent)
{
    QWidget *widget{new QWidget};

    QWidget *superior{new QWidget};
    superior->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    informacionL=new QLabel{"Este es el almacen de la planta de Refrescos"};
    informacionL->setFrameStyle(QFrame::StyledPanel| QFrame::Sunken);
    informacionL->setAlignment(Qt::AlignCenter);

    QWidget *inferior{new QWidget};
    inferior->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);


    QVBoxLayout *organizador{new QVBoxLayout};
    organizador->addWidget(superior);
    organizador->addWidget(informacionL);
    organizador->addWidget(inferior);
    widget->setLayout(organizador);


}
Almacen::~Almacen()
{

}
