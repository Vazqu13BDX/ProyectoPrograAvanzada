#include "bottlefill.h"
#include <iostream>

using namespace std;

BottleFill::BottleFill(QWidget *parent)
    : QWidget(parent)
{

    timer1 = new QTimer{this};
    connect(timer1, SIGNAL(timeout()),this, SLOT(bottle_process()));
    timer1->setInterval(2000);
    timer1->start();

    timer2 = new QTimer{this};
    connect(timer2, SIGNAL(timeout()),this, SLOT(can_process()));
    timer2->setInterval(1000);
    timer2->start();

/*
    barra = new QProgressBar{this};
    barra->setRange(0, 4);
    barra->setValue(0);
    barra->setGeometry(10, 10, 180, 30);*/

 //Botellas

    botellaLabel = new QLabel(this);

    // Carga la imagen
    QPixmap imagen0("C:/Users/juani/Documents/Programacion Avanzada/ProyectoProgramacionAvanzada/Botellas_Label (1).png");
    botellaLabel->setPixmap(imagen0.scaled(200,180,Qt::KeepAspectRatio));
    botellaLabel->setGeometry(0, 100, 500, 500);


    reset1 = new QPushButton("RESET Bottles", this);
    reset1->setGeometry(10,100,100,40);
    connect(reset1, SIGNAL(clicked(bool)), this, SLOT(reset_timer1()));

    stop1 = new QPushButton("STOP Bottles", this);
    stop1->setGeometry(10,0,80,90);
    connect(stop1, SIGNAL(clicked(bool)), this, SLOT(stop_timer1()));

    continuar1 = new QPushButton("Continue Bottles", this);
    continuar1->setGeometry(130, 100, 120,70);
    connect(continuar1, SIGNAL(clicked(bool)), this, SLOT(continue_timer1()));

    almacen1 = new QPushButton("ALMACEN B", this);
    almacen1->setGeometry(140, 0, 80, 80);
    connect(almacen1, SIGNAL(clicked(bool)), this, SLOT(almacen_func1()));


    labelBotellasLlenadas = new QLabel("Botellas Llenadas: 0", this);
    labelBotellasLlenadas->setGeometry(10, 170, 150, 20);

    labelBotellasAlmacen = new QLabel("Botellas en Almacén: 0", this);
    labelBotellasAlmacen->setGeometry(140, 170, 150, 20);



    //LATAS

    lataLabel = new QLabel(this);
    QPixmap imagenA("C:/Users/juani/Documents/Programacion Avanzada/ProyectoProgramacionAvanzada/Lata_Label/Lata_Label/6.png");
    lataLabel->setPixmap(imagenA.scaled(200,130,Qt::KeepAspectRatio));
    lataLabel->setGeometry(550, 140, 500, 500);


    reset2 = new QPushButton("RESET L", this);
    reset2->setGeometry(500,100,100,40);
    connect(reset2, SIGNAL(clicked(bool)), this, SLOT(reset_timer2()));

    stop2 = new QPushButton("STOP L", this);
    stop2->setGeometry(500,0,80,90);
    connect(stop2, SIGNAL(clicked(bool)), this, SLOT(stop_timer2()));

    continuar2 = new QPushButton("Continue L", this);
    continuar2->setGeometry(650, 100, 70,70);
    connect(continuar2, SIGNAL(clicked(bool)), this, SLOT(continue_timer2()));

    almacen2 = new QPushButton("ALMACEN L", this);
    almacen2->setGeometry(650, 0, 80, 80);
    connect(almacen2, SIGNAL(clicked(bool)), this, SLOT(almacen_func2()));


    labelLatasLlenadas = new QLabel("latas Llenadas: 0", this);
    labelLatasLlenadas->setGeometry(510, 170, 150, 20);

    labelLatasAlmacen = new QLabel("latas en Almacén: 0", this);
    labelLatasAlmacen->setGeometry(640, 170, 150, 20);

}

BottleFill::~BottleFill()
{

}

void BottleFill::can_process()
{
    qInfo() << "can time event called";
    contador2++;
    //barra->setValue(contador2);
    can_filler();
}

void BottleFill::bottle_process()
{
    contador1++;
    bottle_filler();
}

void BottleFill::reset_timer1()
{
    contador1 = 0;
    botellas = 0;
    timer1->start();
}

void BottleFill::stop_timer1()
{
    timer1->stop();
}

void BottleFill::continue_timer1()
{
    timer1->start();
}

void BottleFill::almacen_func1()
{
    if(botellas==3)
    {
    botellas_almacen++;
        reset_timer1();
    }
    else
    {
    qInfo() << "Kamara papi no hay nada todavia";
    }
    labelBotellasAlmacen->setText("Botellas en Almacen: " + QString::number(botellas_almacen));

}

void BottleFill::bottle_filler()
{
    if (contador1 == 1) {
    QPixmap imagen1("C:/Users/juani/Documents/Programacion Avanzada/ProyectoProgramacionAvanzada/Botellas_Label/Botellas_Label/1.png");
    botellaLabel->setPixmap(imagen1.scaled(200,180,Qt::KeepAspectRatio));
    botellaLabel->setGeometry(0, 100, 500, 500);
    } else if (contador1 == 2) {
    QPixmap imagen2("C:/Users/juani/Documents/Programacion Avanzada/ProyectoProgramacionAvanzada/Botellas_Label/Botellas_Label/2.png");
    botellaLabel->setPixmap(imagen2.scaled(200,180,Qt::KeepAspectRatio));
    botellaLabel->setGeometry(0, 100, 500, 500);
    } else if (contador1 == 3) {
    QPixmap imagen3("C:/Users/juani/Documents/Programacion Avanzada/ProyectoProgramacionAvanzada/Botellas_Label/Botellas_Label/3.png");
    botellaLabel->setPixmap(imagen3.scaled(200,180,Qt::KeepAspectRatio));
    botellaLabel->setGeometry(0, 100, 500, 500);
    } else if (contador1 == 4) {
    QPixmap imagen3("C:/Users/juani/Documents/Programacion Avanzada/ProyectoProgramacionAvanzada/Botellas_Label/Botellas_Label/4.png");
    botellaLabel->setPixmap(imagen3.scaled(200,180,Qt::KeepAspectRatio));
     botellaLabel->setGeometry(0, 100, 500, 500);
    }else if (contador1 == 5) {
    QPixmap imagen3("C:/Users/juani/Documents/Programacion Avanzada/ProyectoProgramacionAvanzada/Botellas_Label/Botellas_Label/5.png");
    botellaLabel->setPixmap(imagen3.scaled(200,180,Qt::KeepAspectRatio));
    botellaLabel->setGeometry(0, 100, 500, 500);
    }else if (contador1 == 6) {
    QPixmap imagen6("C:/Users/juani/Documents/Programacion Avanzada/ProyectoProgramacionAvanzada/Botellas_Label (1).png");
    botellaLabel->setPixmap(imagen6.scaled(200,180,Qt::KeepAspectRatio));
    botellaLabel->setGeometry(0, 100, 500, 500);
    }


    if(contador1 == 6)
    {
    botellas++;
    qInfo() << "botellas llenadas: " << botellas;
    contador1 = 0;
    labelBotellasLlenadas->setText("Botellas Llenadas: " + QString::number(botellas));

    }

    if(botellas == 3)
    {
    timer1->stop();
    qInfo() << "Se ha completado todo un paquete de botellas";
    qInfo() << "Desea pasarlas al almacen?";
    }
}

//------------------------------------------------LATAS

void BottleFill::can_filler()
{
    if (contador2 == 1) {
    QPixmap imagenB("C:/Users/juani/Documents/Programacion Avanzada/ProyectoProgramacionAvanzada/Lata_Label/Lata_Label/7.png");
    lataLabel->setPixmap(imagenB.scaled(200,130,Qt::KeepAspectRatio));
    lataLabel->setGeometry(550, 140, 500, 500);
    } else if (contador2 == 2) {
    QPixmap imagenC("C:/Users/juani/Documents/Programacion Avanzada/ProyectoProgramacionAvanzada/Lata_Label/Lata_Label/8.png");
    lataLabel->setPixmap(imagenC.scaled(200,130,Qt::KeepAspectRatio));
     lataLabel->setGeometry(550, 140, 500, 500);
    } else if (contador2 == 3) {
    QPixmap imagenD("C:/Users/juani/Documents/Programacion Avanzada/ProyectoProgramacionAvanzada/Lata_Label/Lata_Label/9.png");
    lataLabel->setPixmap(imagenD.scaled(200,130,Qt::KeepAspectRatio));
    lataLabel->setGeometry(550, 140, 500, 500);
    } else if (contador2 == 4) {
    QPixmap imagenE("C:/Users/juani/Documents/Programacion Avanzada/ProyectoProgramacionAvanzada/Lata_Label/Lata_Label/10.png");
    lataLabel->setPixmap(imagenE.scaled(200,130,Qt::KeepAspectRatio));
     lataLabel->setGeometry(550, 140, 500, 500);
    }else if (contador2 == 5) {
    QPixmap imagenF("C:/Users/juani/Documents/Programacion Avanzada/ProyectoProgramacionAvanzada/Lata_Label/Lata_Label/6.png");
    lataLabel->setPixmap(imagenF.scaled(200,130,Qt::KeepAspectRatio));
    lataLabel->setGeometry(550, 140, 500, 500);
    }

    if(contador2 == 5)
    {
    latas++;
    qInfo() << "latas llenadas: " << latas;
    contador2 = 0;
    labelLatasLlenadas->setText("LatasLlenadas: " + QString::number(latas));

    }

    if(latas == 6)
    {
    timer2->stop();
    qInfo() << "Se ha completado todo un paquete de latas";
    qInfo() << "Desea pasarlas al almacen?";
    }
}


void BottleFill::reset_timer2()
{
    contador2 = 0;
    latas = 0;
    timer2->start();
}

void BottleFill::stop_timer2()
{
    timer2->stop();
}

void BottleFill::continue_timer2()
{
    timer2->start();
}

void BottleFill::almacen_func2()
{
    if(latas==6)
    {
    latas_almacen++;
    reset_timer2();
    }
    else
    {
    qInfo() << "Kamara papi no hay nada todavia";
    }
    labelLatasAlmacen->setText("Latas en Almacen: " + QString::number(latas_almacen));

}

