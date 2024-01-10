#ifndef BOTTLEFILL_H
#define BOTTLEFILL_H

#include <QWidget>
#include <QTimer>
#include <QDebug>
#include <QProgressBar>
#include <QPushButton>
#include <QLabel>


class QPushButton;
class QProgressBar;
//class QLabel:

class BottleFill : public QWidget
{
    Q_OBJECT

public:

    explicit BottleFill(QWidget *parent = nullptr);
    ~BottleFill();

private:
    //Botellas
    QProgressBar *barra;
    QProgressBar *barra1;
    QTimer *timer1;
    QPushButton *reset1;
    QPushButton *stop1;
    QPushButton *almacen1;
    QPushButton *continuar1;
    int contador1{};
    int botellas{};
    int botellas_almacen{};
    QLabel *labelBotellasLlenadas;
    QLabel *labelBotellasAlmacen;
    QLabel *botellaLabel;

    QLabel *alarma_stopBotella;
    QLabel *alarma_stopLata;
    QLabel *alarmaBottleFilled;
    QLabel *alarmaCanFilled;

    // Latas
    QTimer *timer2;
    QPushButton *reset2;
    QPushButton *stop2;
    QPushButton *almacen2;
    QPushButton *continuar2;
    int contador2{};
    int latas{};
    int latas_almacen{};
    QLabel *labelLatasLlenadas;
    QLabel *labelLatasAlmacen;
    QLabel *lataLabel;

private slots:
    void bottle_process();
    void can_process();
    void reset_timer1();
    void stop_timer1();
    void continue_timer1();
    void reset_timer2();
    void stop_timer2();
    void continue_timer2();

signals:
    void setValue(int senal);
    void setValue1(int senal1);
    void sendALmacen(int i, int i1);

public:
    void bottle_filler();
    void can_filler();
    inline int getLatasValue() { return latas_almacen; }   // Obtener cantidad de latas almacenadas
    inline int getBotellasValue() { return botellas_almacen; }  // Obtener cantidad de botellas almacenadas
    friend class Envios;
public slots:
    void almacenarBotellas();
    void almacenarLatas();
    void alarma_stopBotellas();
    void alarma_stopLatas();

};
#endif // BOTTLEFILL_H
