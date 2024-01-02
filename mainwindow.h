#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>

class QAction;
class QTabBar;
class QLabel;

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    QTabBar *tab_bar;

    QWidget *contenidoPestana1;
    QLabel *labelPestana1;
    QVBoxLayout *layoutPestana1;

    QWidget *contenidoPestana2;
    QLabel *labelPestana2;
    QVBoxLayout *layoutPestana2;

    QWidget *contenidoPestana3;
    QLabel *labelPestana3;
    QVBoxLayout *layoutPestana3;

    QVBoxLayout *layoutPrincipal;
    QWidget *centralWidget;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void cambiarPestana(int index);
private slots:

};
#endif // MAINWINDOW_H
