#include "almacen_botellas.h"

Almacen::Almacen(QWidget *parent)
    : QWidget{parent}
{

    almacen_background = new QLabel(this);
    QPixmap imagenFondo(":/Images/Fondo_Almacen.png"); // Carga la imagen del archivo de recursos images.qrc
    almacen_background->setPixmap(imagenFondo.scaled(1536,864,Qt::KeepAspectRatio));
    almacen_background->setGeometry(0,0, 1536, 864);

    caja1 = new QLabel(this);
    QPixmap imagenCaja1(":/Images/Cajas_0.png"); // Carga la imagen del archivo de recursos images.qrc
    caja1->setPixmap(imagenCaja1.scaled(170,170,Qt::KeepAspectRatio));
    caja1->setGeometry(480,90, 200, 200);

    caja2 = new QLabel(this);
    QPixmap imagenCaja2(":/Images/Cajas_0.png"); // Carga la imagen del archivo de recursos images.qrc
    caja2->setPixmap(imagenCaja2.scaled(170,170,Qt::KeepAspectRatio));
    caja2->setGeometry(660,90, 200, 200);

    caja3 = new QLabel(this);
    QPixmap imagenCaja3(":/Images/Cajas_0.png"); // Carga la imagen del archivo de recursos images.qrc
    caja3->setPixmap(imagenCaja3.scaled(170,170,Qt::KeepAspectRatio));
    caja3->setGeometry(840,90, 200, 200);

    caja4 = new QLabel(this);
    QPixmap imagenCaja4(":/Images/Cajas_0.png"); // Carga la imagen del archivo de recursos images.qrc
    caja4->setPixmap(imagenCaja4.scaled(170,170,Qt::KeepAspectRatio));
    caja4->setGeometry(480,300, 200, 200);

    caja5 = new QLabel(this);
    QPixmap imagenCaja5(":/Images/Cajas_0.png"); // Carga la imagen del archivo de recursos images.qrc
    caja5->setPixmap(imagenCaja5.scaled(170,170,Qt::KeepAspectRatio));
    caja5->setGeometry(660,300, 200, 200);

    caja6 = new QLabel(this);
    QPixmap imagenCaja6(":/Images/Cajas_0.png"); // Carga la imagen del archivo de recursos images.qrc
    caja6->setPixmap(imagenCaja6.scaled(170,170,Qt::KeepAspectRatio));
    caja6->setGeometry(840,300, 200, 200);

    caja7 = new QLabel(this);
    QPixmap imagenCaja7(":/Images/Cajas_0.png"); // Carga la imagen del archivo de recursos images.qrc
    caja7->setPixmap(imagenCaja7.scaled(170,170,Qt::KeepAspectRatio));
    caja7->setGeometry(480,510, 200, 200);

    caja8 = new QLabel(this);
    QPixmap imagenCaja8(":/Images/Cajas_0.png"); // Carga la imagen del archivo de recursos images.qrc
    caja8->setPixmap(imagenCaja8.scaled(170,170,Qt::KeepAspectRatio));
    caja8->setGeometry(660,510, 200, 200);

    caja9 = new QLabel(this);
    QPixmap imagenCaja9(":/Images/Cajas_0.png"); // Carga la imagen del archivo de recursos images.qrc
    caja9->setPixmap(imagenCaja9.scaled(170,170,Qt::KeepAspectRatio));
    caja9->setGeometry(840,510, 200, 200);

    counterBottleReceiver();


}

void Almacen::counterBottleReceiver(int value)
{
    qInfo() << "Almacen:" << value;

    if(value==1)
    {
        QPixmap imagenCaja1(":/Images/Cajas_1.png");
        caja1->setPixmap(imagenCaja1.scaled(170,170,Qt::KeepAspectRatio));
        caja1->setGeometry(180,920, 200, 200);
    }
    else if(value==2)
    {
        QPixmap imagenCaja2(":/Images/Cajas_1.png");
        caja2->setPixmap(imagenCaja2.scaled(170,170,Qt::KeepAspectRatio));
        caja2->setGeometry(660,90, 200, 200);
    }
}

