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

    //-----------------------Main Labels--------------------------------imagenes-----------

    botellaLabel = new QLabel(this);
    QPixmap imagen0(":/Images/botella_1"); // Carga la imagen del archivo de recursos images.qrc
    botellaLabel->setPixmap(imagen0.scaled(200,180,Qt::KeepAspectRatio));
    botellaLabel->setGeometry(50, 100, 500, 500);

    alarma_stopBotella = new QLabel(this);
    QPixmap alarma1(":/Alarms/botella_0.png");
    alarma_stopBotella->setPixmap(alarma1.scaled(100,100,Qt::KeepAspectRatio));
    alarma_stopBotella->setGeometry(900, 0, 100, 100);

    alarma_stopLata = new QLabel(this);
    QPixmap alarma2(":/Alarms/lata_0.png");
    alarma_stopLata->setPixmap(alarma2.scaled(100,100,Qt::KeepAspectRatio));
    alarma_stopLata->setGeometry(1050, 0, 100, 100);

    alarmaBottleFilled = new QLabel(this);
    QPixmap alarma3(":/Alarms/botellas_almacen_0.png");
    alarmaBottleFilled->setPixmap(alarma3.scaled(100,100,Qt::KeepAspectRatio));
    alarmaBottleFilled->setGeometry(900, 120, 100, 100);

    alarmaCanFilled = new QLabel(this);
    QPixmap alarma4(":/Alarms/latas_almacen_0.png");
    alarmaCanFilled->setPixmap(alarma4.scaled(100,100,Qt::KeepAspectRatio));
    alarmaCanFilled->setGeometry(1050, 120, 100, 100);


    //-----------------------------------------------------------------------------------

    reset1 = new QPushButton("RESET Bottles", this);
    reset1->setGeometry(10,100,120,70);
    connect(reset1, SIGNAL(clicked(bool)), this, SLOT(reset_timer1()));

    stop1 = new QPushButton("STOP Bottles", this);
    stop1->setGeometry(10,0,120,70);
    connect(stop1, SIGNAL(clicked(bool)), this, SLOT(stop_timer1()));
    connect(stop1, SIGNAL(clicked(bool)), this, SLOT(alarma_stopBotellas()));

    continuar1 = new QPushButton("Continue Bottles", this);
    continuar1->setGeometry(140, 100, 120,70);
    connect(continuar1, SIGNAL(clicked(bool)), this, SLOT(continue_timer1()));

    almacen1 = new QPushButton("ALMACEN B", this);
    almacen1->setGeometry(140, 0, 120, 70);
    connect(almacen1, SIGNAL(clicked(bool)), this, SLOT(almacenarBotellas()));


    labelBotellasLlenadas = new QLabel("Botellas Llenadas: 0", this);
    labelBotellasLlenadas->setGeometry(10, 170, 150, 20);

    labelBotellasAlmacen = new QLabel("Botellas en Almacén: 0", this);
                           labelBotellasAlmacen->setGeometry(140, 170, 150, 20);
    barra=new QProgressBar{this};
    barra->setRange(0,30);
    barra->setValue(0);
    barra->setGeometry(280,10,30,200);
    barra->setOrientation(Qt::Vertical);

    connect(this, &BottleFill::setValue, barra, &QProgressBar::setValue);





    //LATAS

    lataLabel = new QLabel(this);
    QPixmap imagenA(":/Images/lata_1.png");
    lataLabel->setPixmap(imagenA.scaled(200,130,Qt::KeepAspectRatio));
    lataLabel->setGeometry(550, 140, 500, 500);


    reset2 = new QPushButton("RESET L", this);
    reset2->setGeometry(500,100,120,70);
    connect(reset2, SIGNAL(clicked(bool)), this, SLOT(reset_timer2()));

    stop2 = new QPushButton("STOP L", this);
    stop2->setGeometry(500,0,120,70);
    connect(stop2, SIGNAL(clicked(bool)), this, SLOT(stop_timer2()));
    connect(stop2, SIGNAL(clicked(bool)),this, SLOT(alarma_stopLatas()));

    continuar2 = new QPushButton("Continue L", this);
    continuar2->setGeometry(650, 100, 120,70);
    connect(continuar2, SIGNAL(clicked(bool)), this, SLOT(continue_timer2()));

    almacen2 = new QPushButton("ALMACEN L", this);
    almacen2->setGeometry(650, 0, 120, 70);
    connect(almacen2, SIGNAL(clicked(bool)), this, SLOT(almacenarLatas()));


    labelLatasLlenadas = new QLabel("latas Llenadas: 0", this);
    labelLatasLlenadas->setGeometry(510, 170, 150, 20);

    labelLatasAlmacen = new QLabel("latas en Almacén: 0", this);
                        labelLatasAlmacen->setGeometry(640, 170, 150, 20);
    barra1=new QProgressBar{this};
    barra1->setRange(0,30);
    barra1->setValue(0);
    barra1->setGeometry(800,10,30,200);
    barra1->setOrientation(Qt::Vertical);
    connect(this, &BottleFill::setValue1, barra1, &QProgressBar::setValue);


}

BottleFill::~BottleFill()
{
}

void BottleFill::can_process()
{
    //qInfo() << "can time event called";
    contador2++;
   // barra->setValue(contador2);
    can_filler();
}

void BottleFill::bottle_process()
{
    contador1++;
   // barra1->setValue(contador++);
    bottle_filler();
}

void BottleFill::reset_timer1()
{
    contador1 = 0;
    botellas = 0;

    QPixmap alarma3(":/Alarms/botellas_almacen_0.png");
    alarmaBottleFilled->setPixmap(alarma3.scaled(100,100,Qt::KeepAspectRatio));
    alarmaBottleFilled->setGeometry(900, 120, 100, 100);

    timer1->start();
}

void BottleFill::stop_timer1()
{
    timer1->stop();

}

void BottleFill::continue_timer1()
{
    timer1->start();

    QPixmap alarma(":/Alarms/botella_0.png");
    alarma_stopBotella->setPixmap(alarma.scaled(100,100,Qt::KeepAspectRatio));
    alarma_stopBotella->setGeometry(900, 0, 100, 100);
}


void BottleFill::bottle_filler()
{
    if (contador1 == 1) {
        QPixmap imagen(":/Images/botella_2.png");
        botellaLabel->setPixmap(imagen.scaled(200,180,Qt::KeepAspectRatio));
        botellaLabel->setGeometry(50, 100, 500, 500);
    } else if (contador1 == 2) {
        QPixmap imagen(":/Images/botella_3.png");
        botellaLabel->setPixmap(imagen.scaled(200,180,Qt::KeepAspectRatio));
        botellaLabel->setGeometry(50, 100, 500, 500);
    } else if (contador1 == 3) {
        QPixmap imagen(":/Images/botella_4.png");
        botellaLabel->setPixmap(imagen.scaled(200,180,Qt::KeepAspectRatio));
        botellaLabel->setGeometry(50, 100, 500, 500);
    } else if (contador1 == 4) {
        QPixmap imagen(":/Images/botella_5.png");
        botellaLabel->setPixmap(imagen.scaled(200,180,Qt::KeepAspectRatio));
        botellaLabel->setGeometry(50, 100, 500, 500);
    }else if (contador1 == 5) {
        QPixmap imagen(":/Images/botella_6.png");
        botellaLabel->setPixmap(imagen.scaled(200,180,Qt::KeepAspectRatio));
        botellaLabel->setGeometry(50, 100, 500, 500);
    }else if (contador1 == 6) {
        QPixmap imagen(":/Images/botella_1.png");
        botellaLabel->setPixmap(imagen.scaled(200,180,Qt::KeepAspectRatio));
        botellaLabel->setGeometry(50, 100, 500, 500);
    }


    if(contador1 == 6)
    {
        botellas++;
        //qInfo() << "botellas llenadas: " << botellas;
        contador1 = 0;
        labelBotellasLlenadas->setText("Botellas Llenadas: " + QString::number(botellas));

    }

    if(botellas == 3)
    {
        timer1->stop();

        QPixmap alarma3(":/Alarms/botellas_almacen_1.png");
        alarmaBottleFilled->setPixmap(alarma3.scaled(100,100,Qt::KeepAspectRatio));
        alarmaBottleFilled->setGeometry(900, 120, 100, 100);

        qInfo() << "Se ha completado todo un paquete de botellas";
        qInfo() << "Desea pasarlas al almacen?";
    }
}

//------------------------------------------------LATAS

void BottleFill::can_filler()
{
    if (contador2 == 1) {
        QPixmap imagenB(":/Images/lata_2.png");
        lataLabel->setPixmap(imagenB.scaled(200,130,Qt::KeepAspectRatio));
        lataLabel->setGeometry(550, 140, 500, 500);
    } else if (contador2 == 2) {
        QPixmap imagenC(":/Images/lata_3.png");
        lataLabel->setPixmap(imagenC.scaled(200,130,Qt::KeepAspectRatio));
        lataLabel->setGeometry(550, 140, 500, 500);
    } else if (contador2 == 3) {
        QPixmap imagenD(":/Images/lata_4.png");
        lataLabel->setPixmap(imagenD.scaled(200,130,Qt::KeepAspectRatio));
        lataLabel->setGeometry(550, 140, 500, 500);
    } else if (contador2 == 4) {
        QPixmap imagenE(":/Images/lata_5.png");
        lataLabel->setPixmap(imagenE.scaled(200,130,Qt::KeepAspectRatio));
        lataLabel->setGeometry(550, 140, 500, 500);
    }else if (contador2 == 5) {
        QPixmap imagenF(":/Images/lata_1.png");
        lataLabel->setPixmap(imagenF.scaled(200,130,Qt::KeepAspectRatio));
        lataLabel->setGeometry(550, 140, 500, 500);
    }

    if(contador2 == 5)
    {
        latas++;
        //qInfo() << "latas llenadas: " << latas;
        contador2 = 0;
        labelLatasLlenadas->setText("LatasLlenadas: " + QString::number(latas));

    }

    if(latas == 6)
    {
        timer2->stop();
        QPixmap alarma4(":/Alarms/latas_almacen_1.png");
        alarmaCanFilled->setPixmap(alarma4.scaled(100,100,Qt::KeepAspectRatio));
        alarmaCanFilled->setGeometry(1050, 120, 100, 100);

    }
}


void BottleFill::reset_timer2()
{
    contador2 = 0;
    latas = 0;
    timer2->start();

    QPixmap alarma4(":/Alarms/latas_almacen_0.png");
    alarmaCanFilled->setPixmap(alarma4.scaled(100,100,Qt::KeepAspectRatio));
    alarmaCanFilled->setGeometry(1050, 120, 100, 100);
}

void BottleFill::stop_timer2()
{
    timer2->stop();
}

void BottleFill::continue_timer2()
{
    timer2->start();

    QPixmap alarma2(":/Alarms/lata_0.png");
    alarma_stopLata->setPixmap(alarma2.scaled(100,100,Qt::KeepAspectRatio));
    alarma_stopLata->setGeometry(1050, 0, 100, 100);
}



void BottleFill::almacenarBotellas()
{
    if (botellas == 3)
    {
        botellas_almacen ++;
        reset_timer1();
        barra->setValue(botellas_almacen);

    }
    else
    {
        qInfo() << "Aun no hay suficientes botellas para pasarlas a almacen";

    }
    labelBotellasAlmacen->setText("Botellas en Almacen: " + QString::number(botellas_almacen));
}

void BottleFill::almacenarLatas()
{
    if (latas == 6)
    {
        latas_almacen++;
        reset_timer2();
        barra1->setValue(latas_almacen);
    }
    else
    {
        qInfo() << "Aún no hay suficientes latas para pasarlas a almacen";
    }
    labelLatasAlmacen->setText("Latas en Almacen: " + QString::number(latas_almacen));
}

void BottleFill::alarma_stopBotellas()
{
    QPixmap alarma1(":/Alarms/botella_1.png");
    alarma_stopBotella->setPixmap(alarma1.scaled(100,100,Qt::KeepAspectRatio));
    alarma_stopBotella->setGeometry(900, 0, 100, 100);
}

void BottleFill::alarma_stopLatas()
{
    QPixmap alarma2(":/Alarms/lata_1.png");
    alarma_stopLata->setPixmap(alarma2.scaled(100,100,Qt::KeepAspectRatio));
    alarma_stopLata->setGeometry(1050, 0, 100, 100);
}
