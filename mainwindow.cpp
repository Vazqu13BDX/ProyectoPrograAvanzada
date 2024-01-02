#include "mainwindow.h"
#include <QtWidgets>
#include <QLabel>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

    tab_bar = new QTabBar(this);
        tab_bar->addTab("Proceso de Llenado");
        tab_bar->addTab("Almacen");
        tab_bar->addTab("Envios y Rastreo");
        connect(tab_bar, SIGNAL(currentChanged(int)), this, SLOT(cambiarPestana(int)));

    // Crear los contenidos de las pestañas
    contenidoPestana1 = new QWidget(this);
        labelPestana1 = new QLabel("Proceso de llenado", contenidoPestana1);
        layoutPestana1 = new QVBoxLayout(contenidoPestana1);
        layoutPestana1->addWidget(labelPestana1);

    contenidoPestana2 = new QWidget(this);
        labelPestana2 = new QLabel("Almacen de Embotelladora", contenidoPestana2);
        layoutPestana2 = new QVBoxLayout(contenidoPestana2);
        layoutPestana2->addWidget(labelPestana2);

    contenidoPestana3= new QWidget(this);
        labelPestana3= new QLabel("Envios y Rastreo");
        layoutPestana3= new QVBoxLayout(contenidoPestana3);
        layoutPestana3->addWidget(labelPestana3);


    // Crear el diseño principal
    layoutPrincipal = new QVBoxLayout();
    layoutPrincipal->addWidget(tab_bar);
    layoutPrincipal->addWidget(contenidoPestana1);
    layoutPrincipal->addWidget(contenidoPestana2);
    layoutPrincipal->addWidget(contenidoPestana3);

    // Crear el widget central y establecer el diseño principal

    centralWidget = new QWidget(this);
    centralWidget->setLayout(layoutPrincipal);
    setCentralWidget(centralWidget);






    setWindowTitle("Embotelladora Industrial");
    setMinimumSize(200,200);
    resize(480,320);
}

MainWindow::~MainWindow()
{

}

void MainWindow::cambiarPestana(int index)
{
        if (index == 0) {
            labelPestana1->setText("Contenido 1");
            labelPestana2->setText("");
            labelPestana3->setText(""); // Limpiar contenido de la Pestaña
        }
        else if (index == 1) {
            labelPestana1->setText("");  // Limpiar contenido de la Pestaña 1
            labelPestana2->setText("Contenido 2");
            labelPestana3->setText("");
        }
        else if (index==2){
            labelPestana1->setText("");
            labelPestana2->setText("");
            labelPestana3->setText("Contenido 3");
        }
}

