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
    QTimer *timer1;  // Temporizador para el proceso de llenado de botellas
    QPushButton *reset1;  // Botón para reiniciar el temporizador de botellas
    QPushButton *stop1;   // Botón para detener el temporizador de botellas
    QPushButton *almacen1;  // Botón para almacenar botellas llenadas
    QPushButton *continuar1;  // Botón para continuar el temporizador de botellas
    int contador1{};  // Contador de botellas llenadas
    int botellas{};   // Número total de botellas a llenar
    int botellas_almacen{};  // Número de botellas almacenadas
    QLabel *labelBotellasLlenadas;  // Etiqueta para mostrar la cantidad de botellas llenadas
    QLabel *labelBotellasAlmacen;   // Etiqueta para mostrar la cantidad de botellas almacenadas
    QLabel *botellaLabel;  // Etiqueta para indicar el tipo de contenedor (botella)

    // Latas
    QTimer *timer2;  // Temporizador para el proceso de llenado de latas
    // QProgressBar *barra;  // Barra de progreso para mostrar el llenado de latas
    QPushButton *reset2;   // Botón para reiniciar el temporizador de latas
    QPushButton *stop2;    // Botón para detener el temporizador de latas
    QPushButton *almacen2;  // Botón para almacenar latas llenadas
    QPushButton *continuar2;  // Botón para continuar el temporizador de latas
    int contador2{};  // Contador de latas llenadas
    int latas{};      // Número total de latas a llenar
    int latas_almacen{};  // Número de latas almacenadas
    QLabel *labelLatasLlenadas;  // Etiqueta para mostrar la cantidad de latas llenadas
    QLabel *labelLatasAlmacen;   // Etiqueta para mostrar la cantidad de latas almacenadas
    QLabel *lataLabel;
private slots:
    void bottle_process();     // Proceso de llenado de botellas
    void can_process();        // Proceso de llenado de latas
    void reset_timer1();       // Reiniciar temporizador de botellas
    void stop_timer1();        // Detener temporizador de botellas
    void continue_timer1();    // Continuar temporizador de botellas
    void reset_timer2();       // Reiniciar temporizador de latas
    void stop_timer2();        // Detener temporizador de latas
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

};
#endif // BOTTLEFILL_H
