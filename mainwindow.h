#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
#include <QLabel>
#include <QPushButton>
#include <QTabWidget>

#include "bottlefill.h"
#include "almacen.h"
#include "envios.h"

class QTabBar;
class QLabel;
class QPushButton;


class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    QTabBar *tab_bar;

    QWidget *contenidoPestana1;
    QLabel *labelPestana1;
    QVBoxLayout *layoutPestana1;

    QWidget *contenidoPestana2;
    QLabel *labelPestana2;
    QVBoxLayout *layoutPestana2;

    QWidget *contenidoPestana3;
    QLabel *labelPestana3;
    QVBoxLayout *layoutPestana3;

    QWidget *cont;
    QLabel *mens;
    QVBoxLayout *layoutmensaje;
    QVBoxLayout *layoutcont;

    QVBoxLayout *layoutPrincipal;
    QWidget *centralWidget;

   BottleFill *bottle{new BottleFill};
   Almacen *almac{new Almacen};
   Envios *env{new Envios};

public:

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void inicioPlanta();
    void llamadoPagina(int llamada);

public slots:

    void cambiarPestana(int index);

};
#endif // MAINWINDOW_H
