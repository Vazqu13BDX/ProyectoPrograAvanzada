#ifndef ENVIOS_H
#define ENVIOS_H
#include "envios.h"

#include <QMainWindow>
#include <QtWidgets>
#include <QWidget>


class QLabel;

class Envios: public QWidget
{   Q_OBJECT
private:
     QLabel *informacionL;

public:
    explicit Envios(QWidget *parent =nullptr);
    ~Envios();
};

#endif // ENVIOS_H
