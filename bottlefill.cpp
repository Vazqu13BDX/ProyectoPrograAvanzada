#include "bottlefill.h"
#include <iostream>
using namespace std;

BottleFill::BottleFill(QWidget *parent)
    : QWidget(parent)
{

    counter = new Almacen(this);

    timer1 = new QTimer{this};
    connect(timer1, SIGNAL(timeout()),this, SLOT(bottle_process()));
    timer1->setInterval(500);
    timer1->start();

    timer2 = new QTimer{this};
    connect(timer2, SIGNAL(timeout()),this, SLOT(can_process()));
    timer2->setInterval(250);
    timer2->start();

    connect(this, &BottleFill::counterUpdate, counter, Almacen::counterBottleReceiver);


    //-----------------------Main Labels--------------------------------imagenes-----------


    bottleBackground = new QLabel(this);
    QPixmap imagenFondo(":/Images/Fondo_Consola.png"); // Carga la imagen del archivo de recursos images.qrc
    bottleBackground->setPixmap(imagenFondo.scaled(1536,864,Qt::KeepAspectRatio));
    bottleBackground->setGeometry(0,0, 1536, 864);


    botellaLabel = new QLabel(this);
    QPixmap imagen0(":/Images/botella_0.png"); // Carga la imagen del archivo de recursos images.qrc
    botellaLabel->setPixmap(imagen0.scaled(200,180,Qt::KeepAspectRatio));
    botellaLabel->setGeometry(350, 300, 500, 500);

    alarma_stopBotella = new QLabel(this);
    QPixmap alarma1(":/Alarms/botella_0.png");
    alarma_stopBotella->setPixmap(alarma1.scaled(100,100,Qt::KeepAspectRatio));
    alarma_stopBotella->setGeometry(630, 80, 100, 100);

    alarma_stopLata = new QLabel(this);
    QPixmap alarma2(":/Alarms/lata_0.png");
    alarma_stopLata->setPixmap(alarma2.scaled(100,100,Qt::KeepAspectRatio));
    alarma_stopLata->setGeometry (770, 80, 100, 100);

    alarmaBottleFilled = new QLabel(this);
    QPixmap alarma3(":/Alarms/botellas_almacen_0.png");
    alarmaBottleFilled->setPixmap(alarma3.scaled(100,100,Qt::KeepAspectRatio));
    alarmaBottleFilled->setGeometry(630, 230, 100, 100);

    alarmaCanFilled = new QLabel(this);
    QPixmap alarma4(":/Alarms/latas_almacen_0.png");
    alarmaCanFilled->setPixmap(alarma4.scaled(100,100,Qt::KeepAspectRatio));
    alarmaCanFilled->setGeometry(770, 230, 100, 100);



    //-----------------------------------------------------------------------------------

    reset1 = new QPushButton("RESET B", this);
    reset1->setGeometry(130,80,150,100);
    connect(reset1, SIGNAL(clicked(bool)), this, SLOT(reset_timer1()));
    connect(reset1, SIGNAL(clicked(bool)), this, SLOT(alarma_resetBotellas()));

    stop1 = new QPushButton("STOP B", this);
    stop1->setGeometry(320,80,150,100);
    connect(stop1, SIGNAL(clicked(bool)), this, SLOT(stop_timer1()));
    connect(stop1, SIGNAL(clicked(bool)), this, SLOT(alarma_stopBotellas()));


    continuar1 = new QPushButton("CONTINUE B", this);
    continuar1->setGeometry(130, 230, 150,100);
    connect(continuar1, SIGNAL(clicked(bool)), this, SLOT(continue_timer1()));

    almacen1 = new QPushButton("ALMACEN B", this);
    almacen1->setGeometry(320, 230, 150, 100);
    connect(almacen1, SIGNAL(clicked(bool)), this, SLOT(almacenarBotellas()));


    labelBotellasLlenadas = new QLabel("Botellas: 0", this);
    QFont font1 = labelBotellasLlenadas->font();
    font1.setBold(true);
    labelBotellasLlenadas->setFont(font1);
    labelBotellasLlenadas->setGeometry(500, 80, 100, 100);

    labelBotellasLlenadas->setStyleSheet("background-color: white;");




    labelBotellasAlmacen = new QLabel("En Almacen: 0", this);
    QFont font3 = labelBotellasAlmacen->font();
    font3.setBold(true);
    labelBotellasAlmacen->setFont(font3);
    labelBotellasAlmacen->setGeometry(500, 230, 100, 100);

    labelBotellasAlmacen->setStyleSheet("background-color: white;");



    barra=new QProgressBar{this};
    barra->setRange(0,9);
    barra->setValue(0);
    barra->setGeometry(130,440,50,200);
    barra->setOrientation(Qt::Vertical);

    connect(this, &BottleFill::setValue, barra, &QProgressBar::setValue);





    //LATAS

    lataLabel = new QLabel(this);
    QPixmap imagenA(":/Images/lata_0.png");
    lataLabel->setPixmap(imagenA.scaled(200,130,Qt::KeepAspectRatio));
    lataLabel->setGeometry(1000, 300, 500, 500);


    reset2 = new QPushButton("RESET L", this);
    reset2->setGeometry(1030,80,150,100);
    connect(reset2, SIGNAL(clicked(bool)), this, SLOT(reset_timer2()));
    connect(reset2, SIGNAL(clicked(bool)), this, SLOT(alarma_resetLatas()));

    stop2 = new QPushButton("STOP L", this);
    stop2->setGeometry(1230,80,150,100);
    connect(stop2, SIGNAL(clicked(bool)), this, SLOT(stop_timer2()));
    connect(stop2, SIGNAL(clicked(bool)),this, SLOT(alarma_stopLatas()));

    continuar2 = new QPushButton("Continue L", this);
    continuar2->setGeometry(1030, 230, 150,100);
    connect(continuar2, SIGNAL(clicked(bool)), this, SLOT(continue_timer2()));

    almacen2 = new QPushButton("ALMACEN L", this);
    almacen2->setGeometry(1230, 230, 150, 100);
    connect(almacen2, SIGNAL(clicked(bool)), this, SLOT(almacenarLatas()));


    labelLatasLlenadas = new QLabel("Latas: 0", this);
    QFont font2 = labelLatasLlenadas->font();
    font2.setBold(true);
    labelLatasLlenadas->setFont(font2);
    labelLatasLlenadas->setGeometry(900, 80, 100, 100);
    labelLatasLlenadas->setStyleSheet("background-color: white;");


    labelLatasAlmacen = new QLabel("En Almacén: 0", this);
        QFont font4 = labelLatasAlmacen->font();
    font4.setBold(true);
    labelLatasAlmacen->setFont(font4);
    labelLatasAlmacen->setGeometry(900, 230, 100, 100);
    labelLatasAlmacen->setStyleSheet("background-color: white;");




    barra1=new QProgressBar{this};
    barra1->setRange(0,6);
    barra1->setValue(0);
    barra1->setGeometry(750,440,50,200);
    barra1->setOrientation(Qt::Vertical);
    connect(this, &BottleFill::setValue1, barra1, &QProgressBar::setValue);

    reset1->setToolTip("Reinicia el Llenado");
    reset2->setToolTip("Reinicia el Llenado");
    stop1->setToolTip("Deniene el Llenado");
    stop2->setToolTip("Deniene el Llenado");
    almacen1->setToolTip("Manda al almacen un paquete lleno");
    almacen2->setToolTip("Manda al almacen un paquete lleno");
    continuar1->setToolTip("Reanuda el Llenado detenido");
    continuar2->setToolTip("Reanuda el Llenado detenido");

    connect(counter, &Almacen::resetEnviar, this, &BottleFill::resetEnvios); //connect que quise usar para conectar la señal del boton de envio de almacen a el slot que reinicie
                                                                                    //todo en la ventana de llenado


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

    labelBotellasLlenadas->setText("Botellas: 0");


    QPixmap alarma3(":/Alarms/botellas_almacen_0.png");
    alarmaBottleFilled->setPixmap(alarma3.scaled(100,100,Qt::KeepAspectRatio));
    alarmaBottleFilled->setGeometry(630, 230, 100, 100);
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
    alarma_stopBotella->setGeometry(630, 80, 100, 100);


}


void BottleFill::bottle_filler()
{
    if (contador1 == 1) {
        QPixmap imagen(":/Images/botella_2_1.png");
        botellaLabel->setPixmap(imagen.scaled(200,180,Qt::KeepAspectRatio));
        botellaLabel->setGeometry(350, 300, 500, 500);
    } else if (contador1 == 2) {
        QPixmap imagen(":/Images/botella_1.png");
        botellaLabel->setPixmap(imagen.scaled(200,180,Qt::KeepAspectRatio));
        botellaLabel->setGeometry(350, 300, 500, 500);
    } else if (contador1 == 3) {
        QPixmap imagen(":/Images/botella_2.png");
        botellaLabel->setPixmap(imagen.scaled(200,180,Qt::KeepAspectRatio));
        botellaLabel->setGeometry(350, 300, 500, 500);
    } else if (contador1 == 4) {
        QPixmap imagen(":/Images/botella_3.png");
        botellaLabel->setPixmap(imagen.scaled(200,180,Qt::KeepAspectRatio));
        botellaLabel->setGeometry(350, 300, 500, 500);
    }else if (contador1 == 5) {
        QPixmap imagen(":/Images/botella_4.png");
        botellaLabel->setPixmap(imagen.scaled(200,180,Qt::KeepAspectRatio));
        botellaLabel->setGeometry(350, 300, 500, 500);
    }else if (contador1 == 6) {
        QPixmap imagen(":/Images/botella_0.png");
        botellaLabel->setPixmap(imagen.scaled(200,180,Qt::KeepAspectRatio));
        botellaLabel->setGeometry(350, 300, 500, 500);
    }


    if(contador1 == 6)
    {
        botellas++;
        //qInfo() << "botellas llenadas: " << botellas;
        contador1 = 0;
        labelBotellasLlenadas->setText("Botellas: " + QString::number(botellas));

    }

    if(botellas == 3)
    {
        timer1->stop();

        QPixmap alarma3(":/Alarms/botellas_almacen_1.png");
        alarmaBottleFilled->setPixmap(alarma3.scaled(100,100,Qt::KeepAspectRatio));
        alarmaBottleFilled->setGeometry(630, 230, 100, 100);

        qInfo() << "Se ha completado todo un paquete de botellas";
        qInfo() << "Desea pasarlas al almacen?";
    }
}

//------------------------------------------------LATAS

void BottleFill::can_filler()
{
    if (contador2 == 1) {
        QPixmap imagenB(":/Images/lata_1.png");
        lataLabel->setPixmap(imagenB.scaled(200,130,Qt::KeepAspectRatio));
        lataLabel->setGeometry(1000, 300, 500, 500);

    } else if (contador2 == 2) {
        QPixmap imagenC(":/Images/lata_2.png");
        lataLabel->setPixmap(imagenC.scaled(200,130,Qt::KeepAspectRatio));
        lataLabel->setGeometry(1000, 300, 500, 500);

    } else if (contador2 == 3) {
        QPixmap imagenD(":/Images/lata_3.png");
        lataLabel->setPixmap(imagenD.scaled(200,130,Qt::KeepAspectRatio));
        lataLabel->setGeometry(1000, 300, 500, 500);

    } else if (contador2 == 4) {
        QPixmap imagenE(":/Images/lata_4.png");
        lataLabel->setPixmap(imagenE.scaled(200,130,Qt::KeepAspectRatio));
        lataLabel->setGeometry(1000, 300, 500, 500);

    }else if (contador2 == 5) {
        QPixmap imagenF(":/Images/lata_0.png");
        lataLabel->setPixmap(imagenF.scaled(200,130,Qt::KeepAspectRatio));
        lataLabel->setGeometry(1000, 300, 500, 500);

    }

    if(contador2 == 5)
    {
        latas++;
        //qInfo() << "latas llenadas: " << latas;
        contador2 = 0;
        labelLatasLlenadas->setText("Latas: " + QString::number(latas));

    }

    if(latas == 6)
    {
        timer2->stop();
        QPixmap alarma4(":/Alarms/latas_almacen_1.png");
        alarmaCanFilled->setPixmap(alarma4.scaled(100,100,Qt::KeepAspectRatio));
        alarmaCanFilled->setGeometry(770, 230, 100, 100);

    }
}


void BottleFill::reset_timer2()
{
    contador2 = 0;
    latas = 0;
    timer2->start();

    labelLatasLlenadas->setText("Latas: 0");


    QPixmap alarma4(":/Alarms/latas_almacen_0.png");
    alarmaCanFilled->setPixmap(alarma4.scaled(100,100,Qt::KeepAspectRatio));
    alarmaCanFilled->setGeometry(770, 230, 100, 100);
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
    alarma_stopLata->setGeometry(770, 80, 100, 100);
}



void BottleFill::almacenarBotellas()
{
    if (botellas == 3)
    {
        botellas_almacen++;
        reset_timer1();
        barra->setValue(botellas_almacen);
        emit counterUpdate(botellas_almacen);
    }
    else
    {
        qInfo() << "Aun no hay suficientes botellas para pasarlas a almacen";
    }

    labelBotellasAlmacen->setText("Almacen: " + QString::number(botellas_almacen));

    if(botellas_almacen == 9)
    {
        qInfo() << "Ya se lleno el almacen de botellas";
        timer1->stop();
    }
}

void BottleFill::almacenarLatas()
{
    if (latas == 6)
    {
        latas_almacen++;
        reset_timer2();
        barra1->setValue(latas_almacen);
        emit counterUpdate1(latas_almacen);
    }
    else
    {
        qInfo() << "Aún no hay suficientes latas para pasarlas a almacen";
    }
    labelLatasAlmacen->setText("Latas: " + QString::number(latas_almacen));

    if(latas_almacen == 6)
    {
        qInfo() << "Se lleno el almacen de latas";
        timer2->stop();
    }
}

void BottleFill::alarma_stopBotellas()
{
    QPixmap alarma1(":/Alarms/botella_1.png");
    alarma_stopBotella->setPixmap(alarma1.scaled(100,100,Qt::KeepAspectRatio));
    alarma_stopBotella->setGeometry(630, 80, 100, 100);
}

void BottleFill::alarma_stopLatas()
{
    QPixmap alarma2(":/Alarms/lata_1.png");
    alarma_stopLata->setPixmap(alarma2.scaled(100,100,Qt::KeepAspectRatio));
    alarma_stopLata->setGeometry(770, 80, 100, 100);
}
void BottleFill::alarma_resetBotellas()
{
    QPixmap alarma1(":/Alarms/botella_0.png");
    alarma_stopBotella->setPixmap(alarma1.scaled(100,100,Qt::KeepAspectRatio));
    alarma_stopBotella->setGeometry(630, 80, 100, 100);
}
void BottleFill::alarma_resetLatas()
{
    QPixmap alarma2(":/Alarms/lata_0.png");
    alarma_stopLata->setPixmap(alarma2.scaled(100,100,Qt::KeepAspectRatio));
    alarma_stopLata->setGeometry(770, 80, 100, 100);
}

void BottleFill::resetEnvios() //metodo que quise usar para reiniciar todo despues de usar el boton de envio
{
    qInfo() << "REINICIANDO TODO";
    barra->setValue(0);
    barra1->setValue(0);
    reset_timer1();
    reset_timer2();

}
