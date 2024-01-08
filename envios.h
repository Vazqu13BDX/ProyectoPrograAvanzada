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

    QWidget *central;
    QVBoxLayout *layout;
    QLabel *info;

    QLineEdit *numberInput;
    QLineEdit *numberInput1;
    QLabel *projectionLabel;
    QLabel *projectionLabel2;

public:
    Envios(QWidget *parent =nullptr);
    ~Envios();

private slots:
    void onProjectionButtonClicked();
};

#endif // ENVIOS_H
