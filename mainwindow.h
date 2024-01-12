#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
#include <QLabel>
#include <QPushButton>
#include <QTabWidget>

#include "bottlefill.h"
#include "almacen.h"


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

    QVBoxLayout *layoutPrincipal;
    QWidget *centralWidget;

    int i{0};

    BottleFill *bottle{new BottleFill};
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
