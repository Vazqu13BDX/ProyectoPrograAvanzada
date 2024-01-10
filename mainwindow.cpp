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
    bottle= new BottleFill;
    envios= new Envios;

    bottle->show();

    // Crear el diseño principal
    layoutPrincipal = new QVBoxLayout();
    layoutPrincipal->addWidget(tab_bar);
    layoutPrincipal->addWidget(bottle);

    centralWidget = new QWidget(this);
    centralWidget->setLayout(layoutPrincipal);
    setCentralWidget(centralWidget);


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
        bottle->hide();
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
