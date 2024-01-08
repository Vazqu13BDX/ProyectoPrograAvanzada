#ifndef ENVIOS_H
#define ENVIOS_H
#include "bottlefill.h"

class QLabel;
class QWidget;
class QVBoxLayout;
class QProgressBar;

class Envios: public QWidget
{   Q_OBJECT
private:

    QProgressBar *barra;

    QWidget *central;
    QVBoxLayout *layout;
    QLabel *info;

public:
    Envios(QWidget *parent =nullptr);
    ~Envios();
};

#endif // ENVIOS_H
