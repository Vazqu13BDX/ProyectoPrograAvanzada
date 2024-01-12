#ifndef ALMACEN_BOTELLAS_H
#define ALMACEN_BOTELLAS_H

#include <QWidget>
#include <QDebug>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QVBoxLayout>
#include <QTimer>
#include <QProcess>

#include "bottlefill.h"

class QLabel;
class QLineEdit;
class QLabel;
class QComboBox;
class QVBoxLayout;
class QProgressBar;


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

    QComboBox *comb;
    QProgressBar *barra;
    QLineEdit *numberInput;
    QLineEdit *numberInput1;
    QLabel *projectionLabel;
    QLabel *projectionLabel2;
    QTimer *Timer;
    int valueB;
    int valueL;

public:
    explicit Almacen(QWidget *parent = nullptr);
    void getNumber(double i);
    void getNumber1(double i);
signals:

private slots:
    void onProjectionButtonClicked();
    void onProjectionButtonClicked1();

public slots:
   void counterBottleReceiver(int count);
   void counterLataReciver(int coun);

};

#endif // ALMACEN_BOTELLAS_H
