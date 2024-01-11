#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QMainWindow>
#include <QtWidgets>
#include <QLabel>
#include <QPushButton>
#include <QTabWidget>

#include "bottlefill.h"
#include "envios.h"
#include "almacen_botellas.h"


class QTabBar;
class QLabel;
class QPushButton;

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    QTabBar *tab_bar;

    QLabel *fondoProceso;
   // QLabel *Almacen;

    QWidget *contenidoPestana1;
    QLabel *labelPestana1;
    QVBoxLayout *layoutPestana1;

    QWidget *contenidoPestana2;
    QLabel *labelPestana2;
    QVBoxLayout *layoutPestana2;


    QWidget *contenidoPestana3;
    QLabel *labelPestana3;
    QVBoxLayout *layoutPestana3;

    QVBoxLayout *layoutPrincipal;
    QWidget *centralWidget;


    QWidget *cont;
    QLabel *mens;
    QVBoxLayout *layoutcont;

    int i{0};

    BottleFill *bottle{new BottleFill};
    Envios *envios{new Envios};
    Almacen *almacen{new Almacen};





public:

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void inicioPlanta();
    void llamadoPagina(int llamada);
    void mostrarVentanaBienvenida();


public slots:

    void cambiarPestana(int index);
};
#endif // MAINWINDOW_H
