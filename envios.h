#ifndef ENVIOS_H
#define ENVIOS_H
#include "bottlefill.h"

#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>

class QLabel;
class QWidget;
class QVBoxLayout;
class QProgressBar;
class QLineEdit;

class Envios: public QWidget
{   Q_OBJECT
private:

    QProgressBar *barra;

    QLabel *info;

    QLineEdit *numberInput;
    QLineEdit *numberInput1;
    QLabel *projectionLabel;
    QLabel *projectionLabel2;

public:
    Envios(QWidget *parent =nullptr);
    ~Envios();
    friend class MainWindow;
    almacen();
private slots:
    void onProjectionButtonClicked();
    void onProjectionButtonClicked1();
    void recibeAlmacen(int bott, int lat );
};

#endif // ENVIOS_H
