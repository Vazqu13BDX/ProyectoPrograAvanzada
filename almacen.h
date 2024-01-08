#ifndef ALMACEN_H
#define ALMACEN_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include "bottlefill.h"


class QLabel;
class QWidget;
class QVBoxLayout;
class QProgressBar;

class Almacen: public QWidget
{

private:
  QWidget *centralWidget;
  QVBoxLayout *layoutPrincipal;
  QLabel *informacionL;
  QLabel *informacionL1;
  QProgressBar *barra;
  QProgressBar *barra1;

public:

    Almacen(QWidget *parent= nullptr);
    ~Almacen();

};

#endif // ALMACEN_H
