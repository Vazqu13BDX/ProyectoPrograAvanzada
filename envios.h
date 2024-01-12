#ifndef ENVIOS_H
#define ENVIOS_H
#include "bottlefill.h"

#include <QLabel>

#include <QPushButton>
#include <QVBoxLayout>


class QWidget;
class QVBoxLayout;
class QProgressBar;


class Envios: public QWidget
{   Q_OBJECT
private:

    QProgressBar *barra;

    QLabel *info;


public:
    Envios(QWidget *parent =nullptr);
    ~Envios();
    friend class MainWindow;
    almacen();
private slots:

};

#endif // ENVIOS_H
