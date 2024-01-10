#include "envios.h"

Envios::Envios(QWidget *parent):QWidget(parent)
{
    numberInput = new QLineEdit(this);
    numberInput->setGeometry(10,10,100,50);

    QPushButton *ProjectButton= new QPushButton("Pedir Latas", this);
    connect(ProjectButton, &QPushButton::clicked, this, &Envios::onProjectionButtonClicked);
    ProjectButton->setGeometry(10,60,100,50);
    projectionLabel=new QLabel("Envios de latas",this);
    projectionLabel->setGeometry(10,100,100,50);

    numberInput1 = new QLineEdit(this);
    numberInput1->setGeometry(110,10,100,50);

    QPushButton *ProjectButton1= new QPushButton("Pedir Botellas", this);
    ProjectButton1->setGeometry(110,60,100,50);
    connect(ProjectButton1, &QPushButton::clicked, this, &Envios::onProjectionButtonClicked1);
    projectionLabel2=new QLabel("Envios de botellas",this);
    projectionLabel2->setGeometry(110,100,100,50);
}

Envios::~Envios()
{

}

void Envios::onProjectionButtonClicked()
{
        QString inputText = numberInput->text();
        bool conversionOk;
        double number = inputText.toDouble(&conversionOk);

        if (conversionOk) {
            projectionLabel->setText("Tu pedido: " + QString::number(number));

        } else {
            projectionLabel->setText("Entrada no válida. Introduce un número.");
        }
}

void Envios::onProjectionButtonClicked1()
{
        QString inputText1 = numberInput1->text();
        bool conversionOk1;
        double number1 = inputText1.toDouble(&conversionOk1);
        if (conversionOk1) {
            projectionLabel2->setText("Tu pedido: " + QString::number(number1));

        } else {
            projectionLabel2->setText("Entrada no válida. Introduce un número.");
        }
}

void Envios::recibeAlmacen(int bott, int lat)
{
        if (bott<=0){

        }
        else if (bott>1){

        }
}
