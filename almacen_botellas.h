#ifndef ALMACEN_BOTELLAS_H
#define ALMACEN_BOTELLAS_H

#include <QWidget>
#include <QDebug>
#include <QLabel>
#include "bottlefill.h"

class QLabel;

class Almacen : public QWidget
{
    Q_OBJECT
private:
    QLabel *almacen_background;
    QLabel *caja1;
    QLabel *caja2;
    QLabel *caja3;
    QLabel *caja4;
    QLabel *caja5;
    QLabel *caja6;
    QLabel *caja7;
    QLabel *caja8;
    QLabel *caja9;

public:
    explicit Almacen(QWidget *parent = nullptr);

signals:

public slots:
    void counterBottleReceiver(int);

};

#endif // ALMACEN_BOTELLAS_H
