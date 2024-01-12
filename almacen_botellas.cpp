#include "almacen_botellas.h"

Almacen::Almacen(QWidget *parent)
    : QWidget{parent}
{

    almacen_background = new QLabel(this);
    QPixmap imagenFondo(":/Images/Fondo_Almacen.png"); // Carga la imagen del archivo de recursos images.qrc
    almacen_background->setPixmap(imagenFondo.scaled(1536,864,Qt::KeepAspectRatio));
    almacen_background->setGeometry(0,0, 1536, 864);

    caja1 = new QLabel(this);
    QPixmap imagenCaja1(":/Images/Cajas_0.png"); // Carga la imagen del archivo de recursos images.qrc
    caja1->setPixmap(imagenCaja1.scaled(170,170,Qt::KeepAspectRatio));
    caja1->setGeometry(480,90, 200, 200);

    caja2 = new QLabel(this);
    QPixmap imagenCaja2(":/Images/Cajas_0.png"); // Carga la imagen del archivo de recursos images.qrc
    caja2->setPixmap(imagenCaja2.scaled(170,170,Qt::KeepAspectRatio));
    caja2->setGeometry(660,90, 200, 200);

    caja3 = new QLabel(this);
    QPixmap imagenCaja3(":/Images/Cajas_0.png"); // Carga la imagen del archivo de recursos images.qrc
    caja3->setPixmap(imagenCaja3.scaled(170,170,Qt::KeepAspectRatio));
    caja3->setGeometry(840,90, 200, 200);

    caja4 = new QLabel(this);
    QPixmap imagenCaja4(":/Images/Cajas_0.png"); // Carga la imagen del archivo de recursos images.qrc
    caja4->setPixmap(imagenCaja4.scaled(170,170,Qt::KeepAspectRatio));
    caja4->setGeometry(480,300, 200, 200);

    caja5 = new QLabel(this);
    QPixmap imagenCaja5(":/Images/Cajas_0.png"); // Carga la imagen del archivo de recursos images.qrc
    caja5->setPixmap(imagenCaja5.scaled(170,170,Qt::KeepAspectRatio));
    caja5->setGeometry(660,300, 200, 200);

    caja6 = new QLabel(this);
    QPixmap imagenCaja6(":/Images/Cajas_0.png"); // Carga la imagen del archivo de recursos images.qrc
    caja6->setPixmap(imagenCaja6.scaled(170,170,Qt::KeepAspectRatio));
    caja6->setGeometry(840,300, 200, 200);

    caja7 = new QLabel(this);
    QPixmap imagenCaja7(":/Images/Cajas_0.png"); // Carga la imagen del archivo de recursos images.qrc
    caja7->setPixmap(imagenCaja7.scaled(170,170,Qt::KeepAspectRatio));
    caja7->setGeometry(480,510, 200, 200);

    caja8 = new QLabel(this);
    QPixmap imagenCaja8(":/Images/Cajas_0.png"); // Carga la imagen del archivo de recursos images.qrc
    caja8->setPixmap(imagenCaja8.scaled(170,170,Qt::KeepAspectRatio));
    caja8->setGeometry(660,510, 200, 200);

    caja9 = new QLabel(this);
    QPixmap imagenCaja9(":/Images/Cajas_0.png"); // Carga la imagen del archivo de recursos images.qrc
    caja9->setPixmap(imagenCaja9.scaled(170,170,Qt::KeepAspectRatio));
    caja9->setGeometry(840,510, 200, 200);

    numberInput = new QLineEdit(this);
    numberInput->setGeometry(10,10,100,50);

    QPushButton *ProjectButton= new QPushButton("Pedir Latas", this);
    connect(ProjectButton, &QPushButton::clicked, this, &Almacen::onProjectionButtonClicked);
    ProjectButton->setGeometry(10,60,100,50);
    projectionLabel=new QLabel("Envios de latas",this);
    projectionLabel->setGeometry(10,100,100,50);

    numberInput1 = new QLineEdit(this);
    numberInput1->setGeometry(110,10,100,50);

    QPushButton *ProjectButton1= new QPushButton("Pedir Botellas", this);
    ProjectButton1->setGeometry(110,60,100,50);
    connect(ProjectButton1, &QPushButton::clicked, this, &Almacen::onProjectionButtonClicked1);
    projectionLabel2=new QLabel("Envios de botellas",this);
    projectionLabel2->setGeometry(110,100,100,50);

    barra = new QProgressBar{this};
    barra->setRange(0,100);
    barra->setValue(0);
    barra->setGeometry(1200,10,300,20);
    barra->setOrientation(Qt::Horizontal);

    comb =new QComboBox{this};
    comb->addItem("Destino 1");
    comb->addItem("Destino 2");
    comb->addItem("Destino 3");
    comb->setGeometry(1200,30,100,20);


}

void Almacen::getNumber(double i)
{
    if(valueB<i){
        qInfo()<<"No hay en el inventario";
    }
    else if(valueB>=i){
        qInfo()<<"Si hay inventario";
    }
}

void Almacen::getNumber1(double i)
{
    if(valueL<i){
         qInfo()<<"No hay en el inventario";
    }
    else if(valueL>=i){
        qInfo()<<"Si hay inventario";
    }
}

void Almacen::counterBottleReceiver(int count)
{
    qInfo() << "Almacen:" << count;
    valueB=count;
}

void Almacen::counterLataReciver(int coun)
{
    qInfo()<<"Almacen 1: "<<coun;
    valueL=coun;
}
void Almacen::onProjectionButtonClicked()
{
        QString inputText = numberInput->text();
        bool conversionOk;
        double number = inputText.toDouble(&conversionOk);
        if (conversionOk) {
            projectionLabel->setText("Tu pedido: " + QString::number(number));

        } else {
            projectionLabel->setText("Entrada no válida. Introduce un número.");
        }
        getNumber(number);

}
void Almacen::onProjectionButtonClicked1()
{
        QString inputText1 = numberInput1->text();
        bool conversionOk1;
        double number1 = inputText1.toDouble(&conversionOk1);
        if (conversionOk1) {
            projectionLabel2->setText("Tu pedido: " + QString::number(number1));

        } else {
            projectionLabel2->setText("Entrada no válida. Introduce un número.");
        }
        getNumber1(number1);
}


