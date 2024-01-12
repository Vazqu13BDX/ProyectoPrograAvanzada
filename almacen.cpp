#include "almacen.h"

Almacen::Almacen(QWidget *parent)
    : QWidget{parent}
{

    Timer=new QTimer{this};
    connect(Timer, &QTimer::timeout, this, &Almacen::InicioEnvio);
    almacen_background = new QLabel(this);
    QPixmap imagenFondo(":/Images/Fondo_Almacen.png"); // Carga la imagen del archivo de recursos images.qrc
    almacen_background->setPixmap(imagenFondo.scaled(1536,864,Qt::KeepAspectRatio));
    almacen_background->setGeometry(0,0, 1536, 864);

    caja1 = new QLabel(this);
    QPixmap imagenCaja1(":/Images/Cajas_0.png"); // Carga la imagen del archivo de recursos images.qrc
    caja1->setPixmap(imagenCaja1.scaled(170,170,Qt::KeepAspectRatio));
    caja1->setGeometry(880,150, 170, 170);

    caja2 = new QLabel(this);
    QPixmap imagenCaja2(":/Images/Cajas_0.png"); // Carga la imagen del archivo de recursos images.qrc
    caja2->setPixmap(imagenCaja2.scaled(170,170,Qt::KeepAspectRatio));
    caja2->setGeometry(1020,150, 170, 170);

    caja3 = new QLabel(this);
    QPixmap imagenCaja3(":/Images/Cajas_0.png"); // Carga la imagen del archivo de recursos images.qrc
    caja3->setPixmap(imagenCaja3.scaled(170,170,Qt::KeepAspectRatio));
    caja3->setGeometry(1160,150, 170, 170);

    caja4 = new QLabel(this);
    QPixmap imagenCaja4(":/Images/Cajas_0.png"); // Carga la imagen del archivo de recursos images.qrc
    caja4->setPixmap(imagenCaja4.scaled(170,170,Qt::KeepAspectRatio));
    caja4->setGeometry(880,310, 170, 170);

    caja5 = new QLabel(this);
    QPixmap imagenCaja5(":/Images/Cajas_0.png"); // Carga la imagen del archivo de recursos images.qrc
    caja5->setPixmap(imagenCaja5.scaled(170,170,Qt::KeepAspectRatio));
    caja5->setGeometry(1020,310, 170, 170);

    caja6 = new QLabel(this);
    QPixmap imagenCaja6(":/Images/Cajas_0.png"); // Carga la imagen del archivo de recursos images.qrc
    caja6->setPixmap(imagenCaja6.scaled(170,170,Qt::KeepAspectRatio));
    caja6->setGeometry(1160,310, 170, 170);

    caja7 = new QLabel(this);
    QPixmap imagenCaja7(":/Images/Cajas_0.png"); // Carga la imagen del archivo de recursos images.qrc
    caja7->setPixmap(imagenCaja7.scaled(170,170,Qt::KeepAspectRatio));
    caja7->setGeometry(880,470, 170, 170);

    caja8 = new QLabel(this);
    QPixmap imagenCaja8(":/Images/Cajas_0.png"); // Carga la imagen del archivo de recursos images.qrc
    caja8->setPixmap(imagenCaja8.scaled(170,170,Qt::KeepAspectRatio));
    caja8->setGeometry(1020,470, 170, 170);

    caja9 = new QLabel(this);
    QPixmap imagenCaja9(":/Images/Cajas_0.png"); // Carga la imagen del archivo de recursos images.qrc
    caja9->setPixmap(imagenCaja9.scaled(170,170,Qt::KeepAspectRatio));
    caja9->setGeometry(1160,470, 170, 170);

    connect(this, &Almacen::changeImage, this, &Almacen::updateImage);

    lata1 = new QLabel(this);
    QPixmap imagenLata1(":/Images/Cajas_0.png"); // Carga la imagen del archivo de recursos images.qrc
    lata1->setPixmap(imagenLata1.scaled(170,170,Qt::KeepAspectRatio));
    lata1->setGeometry(100,240, 170, 170);

    lata2 = new QLabel(this);
    QPixmap imagenLata2(":/Images/Cajas_0.png"); // Carga la imagen del archivo de recursos images.qrc
    lata2->setPixmap(imagenLata2.scaled(170,170,Qt::KeepAspectRatio));
    lata2->setGeometry(250,240, 170, 170);

    lata3 = new QLabel(this);
    QPixmap imagenLata3(":/Images/Cajas_0.png"); // Carga la imagen del archivo de recursos images.qrc
    lata3->setPixmap(imagenLata3.scaled(170,170,Qt::KeepAspectRatio));
    lata3->setGeometry(100,370, 170, 170);

    lata4 = new QLabel(this);
    QPixmap imagenLata4(":/Images/Cajas_0.png"); // Carga la imagen del archivo de recursos images.qrc
    lata4->setPixmap(imagenLata4.scaled(170,170,Qt::KeepAspectRatio));
    lata4->setGeometry(250,370, 170, 170);

    lata5 = new QLabel(this);
    QPixmap imagenLata5(":/Images/Cajas_0.png"); // Carga la imagen del archivo de recursos images.qrc
    lata5->setPixmap(imagenLata5.scaled(170,170,Qt::KeepAspectRatio));
    lata5->setGeometry(100,500, 170, 170);

    lata6 = new QLabel(this);
    QPixmap imagenLata6(":/Images/Cajas_0.png"); // Carga la imagen del archivo de recursos images.qrc
    lata6->setPixmap(imagenLata6.scaled(170,170,Qt::KeepAspectRatio));
    lata6->setGeometry(250,500, 170, 170);

    connect(this, &Almacen::changeImage2, this, &Almacen::updateImage2);

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
    connect(comb, &QComboBox::currentIndexChanged, this, &Almacen::onComboBoxChange);

    enviar=new QPushButton{"ENVIAR",this};
    enviar->setGeometry(1200,60,100,20);
    connect(enviar, &QPushButton::clicked, this, &Almacen::InicioEnvio);
}

void Almacen::updateImage()
{
    if(valueB == 1)
    {
        QPixmap imagenCaja1(":/Images/Cajas_1.png");
        caja1->setPixmap(imagenCaja1.scaled(170,170,Qt::KeepAspectRatio));
         caja1->setGeometry(880,150, 170, 170);
    }
    else if(valueB == 2)
    {
        QPixmap imagenCaja2(":/Images/Cajas_1.png");
        caja2->setPixmap(imagenCaja2.scaled(170,170,Qt::KeepAspectRatio));
        caja2->setGeometry(1020,150, 170, 170);
    }
    else if(valueB == 3)
    {
        QPixmap imagenCaja2(":/Images/Cajas_1.png");
        caja3->setPixmap(imagenCaja2.scaled(170,170,Qt::KeepAspectRatio));
        caja3->setGeometry(1160,150, 170, 170);
    }
    else if(valueB == 4)
    {
        QPixmap imagenCaja2(":/Images/Cajas_1.png");
        caja4->setPixmap(imagenCaja2.scaled(170,170,Qt::KeepAspectRatio));
        caja4->setGeometry(880,310, 170, 170);

    }
    else if(valueB == 5)
    {
        QPixmap imagenCaja2(":/Images/Cajas_1.png");
        caja5->setPixmap(imagenCaja2.scaled(170,170,Qt::KeepAspectRatio));
        caja5->setGeometry(1020,310, 170, 170);

    }
    else if(valueB == 6)
    {
        QPixmap imagenCaja2(":/Images/Cajas_1.png");
        caja6->setPixmap(imagenCaja2.scaled(170,170,Qt::KeepAspectRatio));
        caja6->setGeometry(1160,310, 170, 170);

    }
    else if(valueB == 7)
    {
        QPixmap imagenCaja2(":/Images/Cajas_1.png");
        caja7->setPixmap(imagenCaja2.scaled(170,170,Qt::KeepAspectRatio));
        caja7->setGeometry(880,470, 170, 170);
    }
    else if(valueB == 8)
    {
        QPixmap imagenCaja2(":/Images/Cajas_1.png");
        caja8->setPixmap(imagenCaja2.scaled(170,170,Qt::KeepAspectRatio));
        caja8->setGeometry(1020,470, 170, 170);
    }
    else if(valueB == 9)
    {
        QPixmap imagenCaja2(":/Images/Cajas_1.png");
        caja9->setPixmap(imagenCaja2.scaled(170,170,Qt::KeepAspectRatio));
        caja9->setGeometry(1160,470, 170, 170);
    }

}

void Almacen::updateImage2()
{
    if(valueL == 1)
    {
        QPixmap imagenLata1(":/Images/Cajas_1.png"); // Carga la imagen del archivo de recursos images.qrc
        lata1->setPixmap(imagenLata1.scaled(170,170,Qt::KeepAspectRatio));
        lata1->setGeometry(100,240, 170, 170);
    }
    if(valueL == 2)
    {
        QPixmap imagenLata2(":/Images/Cajas_1.png"); // Carga la imagen del archivo de recursos images.qrc
        lata2->setPixmap(imagenLata2.scaled(170,170,Qt::KeepAspectRatio));
        lata2->setGeometry(250,240, 170, 170);
    }
    if(valueL == 3)
    {
        QPixmap imagenLata3(":/Images/Cajas_1.png"); // Carga la imagen del archivo de recursos images.qrc
        lata3->setPixmap(imagenLata3.scaled(170,170,Qt::KeepAspectRatio));
        lata3->setGeometry(100,370, 170, 170);
    }
    if(valueL == 4)
    {
        QPixmap imagenLata4(":/Images/Cajas_1.png"); // Carga la imagen del archivo de recursos images.qrc
        lata4->setPixmap(imagenLata4.scaled(170,170,Qt::KeepAspectRatio));
        lata4->setGeometry(250,370, 170, 170);

    }
    if(valueL == 5)
    {
        QPixmap imagenLata5(":/Images/Cajas_1.png"); // Carga la imagen del archivo de recursos images.qrc
        lata5->setPixmap(imagenLata5.scaled(170,170,Qt::KeepAspectRatio));
        lata5->setGeometry(100,500, 170, 170);
    }
    if(valueL == 6)
    {
        QPixmap imagenLata6(":/Images/Cajas_1.png"); // Carga la imagen del archivo de recursos images.qrc
        lata6->setPixmap(imagenLata6.scaled(170,170,Qt::KeepAspectRatio));
        lata6->setGeometry(250,500, 170, 170);
    }


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
    emit changeImage();
}

void Almacen::counterLataReceiver(int coun)
{
    qInfo()<<"Almacen 1: "<<coun;
    valueL=coun;
    emit changeImage2();

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

void Almacen::onComboBoxChange(int index)
{
        if (index==0){
            Timer->setInterval(20000);
        }
        else if(index==1){
            Timer->setInterval(15000);
        }
        else if (index==2){
            Timer->setInterval(10000);
        }
}

void Almacen::InicioEnvio()
{
        for(size_t i{0};i<=10;i++){
            valor=valor+1;
            barra->setValue(valor);
            Timer->start();
        }

}
