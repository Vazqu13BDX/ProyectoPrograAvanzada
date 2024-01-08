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
    //Latas
    QTimer *timer2;
    QProgressBar *barra;
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
    void almacen_func1();
    void reset_timer2();
    void stop_timer2();
    void continue_timer2();
    void almacen_func2();

public:
    void bottle_filler();
    void can_filler();
    friend class Almacen;
};
#endif // BOTTLEFILL_H
