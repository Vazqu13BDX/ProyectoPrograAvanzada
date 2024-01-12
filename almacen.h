#ifndef ALMACEN_H
#define ALMACEN_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>

#include <QDebug>

#include <QTimer>
#include <QProgressBar>

#include <QPushButton>
#include <QMainWindow>
#include <QtWidgets>

#include "bottlefill.h"

class QLabel;
class QLineEdit;
class QLabel;
class QComboBox;
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
//Labels para las cajas de las latas
    QLabel *lata1;
    QLabel *lata2;
    QLabel *lata3;
    QLabel *lata4;
    QLabel *lata5;
    QLabel *lata6;

    QPushButton *enviar; //Boton que implemente para enviar la mercancia

    int valor{0};

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

    void changeImage();
    void changeImage2();


private slots:

    void onProjectionButtonClicked();
    void onProjectionButtonClicked1();
    void onComboBoxChange(int index);

public slots:
    void InicioEnvio();
    void counterBottleReceiver(int count);
    void counterLataReceiver(int coun);
    void updateImage();
    void updateImage2();


};

#endif // ALMACEN_H
