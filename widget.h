#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPainter>
#include <QtGui>
#include <QKeyEvent>

#include "mapeo.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

#define radianes(g) ((double) (g) * M_PI/180.0)

struct Puntos3D
{
    int x,y,z;
    bool opcion; //1 = LINETO3D, 0 = MOVETO3D

};

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    void paintEvent(QPaintEvent *event);
    void asisnarCubo();
    void proyeccionCubo();
    void dibujarCubo();
    void inicializaPuerto();

    void lineTo3D(int x,int y,int z,float alpha,float phi,int i);
    void moveTo3D(int x,int y,int z,float alpha,float phi,int i);

private slots:
    void on_dial_valueChanged(int value);

    void on_dial_2_valueChanged(int value);

private:
    Ui::Widget *ui;

    QPainter *canvas;

    Puntos3D *cubo;

    QPointF points[16]; //aqui se guardan los puntos
                        //para Dibujar con dibujoCubo
    Mapeo mapeo;
    int L,M;
    int ancho;

    float alpha;
    float phi;




};
#endif // WIDGET_H











