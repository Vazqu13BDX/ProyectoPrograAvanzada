#ifndef ALMACEN_H
#define ALMACEN_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>

#include "bottlefill.h"

class QLabel;
class QWidget;
class QVBoxLayout;


class Almacen: public QWidget
{
private:
    QWidget *almacen;
    QVBoxLayout *layout1;

    QLabel *informacionL;



public:
    explicit Almacen(QWidget *parent= nullptr);
    ~Almacen();

};

#endif // ALMACEN_H
