#include "envios.h"

Envios::Envios(QWidget *parent):QWidget(parent)
{
    QWidget *central= new QWidget(this);


    QVBoxLayout *mainLayout=new QVBoxLayout(central);
    numberInput = new QLineEdit(this);


    QPushButton *ProjectButton= new QPushButton("Pedir Latas", this);

    connect(ProjectButton, &QPushButton::clicked, this, &Envios::onProjectionButtonClicked);

    projectionLabel=new QLabel("Envios de latas",this);

    numberInput1 = new QLineEdit(this);
    numberInput1->setGeometry(70,20,70,50);

    QPushButton *ProjectButton1= new QPushButton("Pedir Botellas", this);
    ProjectButton1->setGeometry(70,20,70,50);
    connect(ProjectButton1, &QPushButton::clicked, this, &Envios::onProjectionButtonClicked);


    projectionLabel2=new QLabel("Envios de botellas",this);

    mainLayout->addWidget(numberInput);
    mainLayout->addWidget(ProjectButton1);
    mainLayout->addWidget(numberInput1);
    mainLayout->addWidget(ProjectButton);
    mainLayout->addWidget(projectionLabel);
    mainLayout->addWidget(projectionLabel2);
    central->setLayout(mainLayout);


    barra= new QProgressBar{this};
    barra->setRange(0,100);
    barra->setValue(0);
    barra->setGeometry(600,10,200,30);
    barra->setOrientation(Qt::Horizontal);

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
        QString inputText1 = numberInput1->text();
        bool conversionOk1;
        double number1 = inputText1.toDouble(&conversionOk1);
        if (conversionOk1) {
            projectionLabel2->setText("Tu pedido: " + QString::number(number1));
        } else {
            projectionLabel2->setText("Entrada no válida. Introduce un número.");
        }
}
