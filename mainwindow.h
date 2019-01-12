#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QTime>
#include <QString>
#include <QVector>
#include <QHash>
#include <QPushButton>
#include <QMessageBox>


namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow{
    Q_OBJECT


public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QTimer *timer=new QTimer();
    QTime time;
    QVector<QString> tarjetas{"tarjeta01", "tarjeta02", "tarjeta03", "tarjeta04",
                              "tarjeta05", "tarjeta06", "tarjeta07", "tarjeta08",
                              "tarjeta09", "tarjeta10", "tarjeta11", "tarjeta12"};
    QHash<QString, QString> reparto;
    int puntaje=0;
    bool jugadaIniciada;
    QPushButton* tarjetaAnterior;
    QPushButton* tarjetaActual;
    int parejasRestantes;
    QMessageBox msgBox;


private slots:
    void actualizarCronometro();
    void tarjetaDescubierta();
    void mezclar(QVector<QString> &tarjetas);
    void repartir(QVector<QString> &tarjetas, QHash<QString, QString> &reparto);
    void definirResultadoParcial();
    void reiniciarTarjetas();
    void mostrarImagen();
    void definirResultadoFinal();
    void actualizarEstado();
    void inicializarJuego();


private:
    Ui::MainWindow *ui;
};


#endif // MAINWINDOW_H
