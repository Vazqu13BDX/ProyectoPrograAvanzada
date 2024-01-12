#ifndef ALMACEN_H
#define ALMACEN_H

#include <QWidget>
#include <QDebug>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QVBoxLayout>
#include <QTimer>
#include <QProcess>
#include <QPushButton>

#include "bottlefill.h"

class QLabel;
class QLineEdit;
class QLabel;
class QComboBox;
class QVBoxLayout;
class QProgressBar;
class BottleFill;

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

    int valorAlmacen{};

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
    void resetEnviar();//signal que implemente para reiniciar desde la clase almacen a la de llenado, si quieres lo puedes quitar e implementar uno propio
private slots:
    void onProjectionButtonClicked();
    void onProjectionButtonClicked1();

public slots:
    void counterBottleReceiver(int count);
    void counterLataReceiver(int coun);
    void updateImage();
    void updateImage2();
    void enviarFunc(); //slot que envia la señal de resetEnviar
};

#endif // ALMACEN_H
