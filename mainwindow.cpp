#include "mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("Planta de Refrescos");
    setMinimumSize(1536,864);

    mostrarVentanaBienvenida();

    tab_bar = new QTabBar(this);
    tab_bar->addTab("Proceso");
    tab_bar->addTab("Almacen");
    connect(tab_bar, SIGNAL(currentChanged(int)), this, SLOT(cambiarPestana(int)));

    // Crear los contenidos de las pestañas
    bottle= new BottleFill;
    almacen = new Almacen;

    bottle->show();

    // Crear el diseño principal
    layoutPrincipal = new QVBoxLayout();
    layoutPrincipal->addWidget(tab_bar);
    layoutPrincipal->addWidget(bottle);

    centralWidget = new QWidget(this);
    centralWidget->setLayout(layoutPrincipal);
    setCentralWidget(centralWidget);

    connect(bottle, &BottleFill::counterUpdate, almacen, &Almacen::counterBottleReceiver);
    connect(bottle, &BottleFill::counterUpdate1, almacen, &Almacen::counterLataReceiver);

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
        almacen->hide();
        layoutPrincipal->addWidget(tab_bar);
        layoutPrincipal->addWidget(bottle);
        centralWidget->setLayout(layoutPrincipal);

    }
    else if(llamada==2){
        bottle->hide();
        almacen->show();
        layoutPrincipal->addWidget(tab_bar);
        layoutPrincipal->addWidget(almacen);
        centralWidget->setLayout(layoutPrincipal);
    }

}

void MainWindow::mostrarVentanaBienvenida() {
    QMessageBox mensajeBienvenida;
    mensajeBienvenida.setWindowTitle("Bienvenido");
    mensajeBienvenida.setText("¡Bienvenido a la Llenadora de refrescos!");
    mensajeBienvenida.setIcon(QMessageBox::Information);
    mensajeBienvenida.exec();
}


