#include "mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("Planta de Refrescos");
    setMinimumSize(800,800);

    tab_bar = new QTabBar(this);
    tab_bar->addTab("Proceso");
    tab_bar->addTab("Envios y Rastreo");
    connect(tab_bar, SIGNAL(currentChanged(int)), this, SLOT(cambiarPestana(int)));

    // Crear los contenidos de las pestañas
    contenidoPestana1 = new QWidget(this);
    labelPestana1 = new QLabel("Bienvenido a la Planta de Refrescos en esta se llenaran Botellas y Latas de Refresco", contenidoPestana1);
    layoutPestana1 = new QVBoxLayout(contenidoPestana1);
    layoutPestana1->addWidget(labelPestana1);

    contenidoPestana2 = new QWidget(this);
    labelPestana2 = new QLabel("Para iniciar de click en cualquier pestaña", contenidoPestana2);
    layoutPestana2 = new QVBoxLayout(contenidoPestana2);
    layoutPestana2->addWidget(labelPestana2);


    // Crear el diseño principal
    layoutPrincipal = new QVBoxLayout();
    layoutPrincipal->addWidget(tab_bar);
    layoutPrincipal->addWidget(contenidoPestana1);
    layoutPrincipal->addWidget(contenidoPestana2);

    centralWidget = new QWidget(this);
    centralWidget->setLayout(layoutPrincipal);
    setCentralWidget(centralWidget);

    bottle= new BottleFill;
    envios= new Envios;

    connect(bottle, &BottleFill::sendALmacen, envios, &Envios::recibeAlmacen);

}
void MainWindow::cambiarPestana(int index){

    if (index == 0) {
        llamadoPagina(1);
    }
    else if (index == 1) {
        llamadoPagina(2);
    }

}
MainWindow::~MainWindow(){

}

void MainWindow::llamadoPagina(int llamada)
{
    if (i==0){
        delete contenidoPestana1;
        delete contenidoPestana2;
        i=1;
    }
    if(llamada==1){
        bottle->show();
        envios->hide();
        layoutPrincipal->addWidget(tab_bar);
        layoutPrincipal->addWidget(bottle);
        centralWidget->setLayout(layoutPrincipal);

    }
    else if(llamada==2){
        bottle->hide();
        envios->show();
        layoutPrincipal->addWidget(tab_bar);
        layoutPrincipal->addWidget(envios);
        centralWidget->setLayout(layoutPrincipal);
        //connect(bottle, &BottleFill::sendALmacen, envios, &Envios::recibeAlmacen);

    }

}
