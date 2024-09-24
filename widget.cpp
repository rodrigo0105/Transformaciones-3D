#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    alpha = 63.4;
    phi = 30.0;
    ui->lcdNumber->display(ui->dial->value());
    ui->lcdNumber_2->display(ui->dial_2->value());

    asisnarCubo();

}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    inicializaPuerto();
    proyeccionCubo();

}

void Widget::asisnarCubo()
{
    Puntos3D cubobase[] = {{100,50,0,0},{200,50,0,1},{200,150,0,1},{100,150,0,1},
                           {100,50,0,1},{100,50,100,1},{200,50,100,1},{200,150,100,1},
                           {200,150,0,1},{200,50,0,0},{200,50,100,1},{100,50,100,0},
                           {100,150,100,1},{100,150,0,1},{100,150,100,0},{200,150,100,1}};

    cubo = new Puntos3D [16];/*para copiar cubobase porque es el que sa va alimentar*/

    for(int i = 0; i<16;i++)
        cubo[i]= cubobase[i];

    inicializaPuerto();
    ancho = this->size().width() - ui->widget->size().width();
}

void Widget::proyeccionCubo()
{
    canvas  = new QPainter(this);
    canvas->setPen(QPen(Qt::white,3));
    //eje horizontal (X)
    canvas->drawLine(0,this->size().height()-1,ancho,size().height()-1);
    //eje vertical (Y)
    canvas->drawLine(1,0,1,size().height());

    //dibijar eje Z
    int zx1 = 0;
    int zy1 = 0;

    /*
    int zx2 = ancho * cos(phi);
    */
    int zx2 = ancho * cos(radianes(phi));
    int zy2 = ancho * sin(radianes(phi));

    int x1,y1,x2,y2;
    mapeo.mapear(zx1,zy1,x1,y1,L,M);
    mapeo.mapear(zx2,zy2,x2,y2,L,M);
    //eje z
    canvas->drawLine(x1,y1,x2,y2);

    for(int i = 0; i< 16; i++)
        if(cubo[i].opcion)
            lineTo3D(cubo[i].x,cubo[i].y,cubo[i].z,radianes(alpha),qDegreesToRadians(phi),i);
    else
            moveTo3D(cubo[i].x,cubo[i].y,cubo[i].z,radianes(alpha),qDegreesToRadians(phi),i);

    canvas->setPen(QPen(QColor(0,0,0),3));
    dibujarCubo();

    canvas->end();

}
void Widget::dibujarCubo()
{
    for(int i=0; i<15; i++)
        canvas->drawLine(points[i].x(),points[i].y(),points[i+1].x(),points[i+1].y());

    //canvas->eraseRect();
}

void Widget::inicializaPuerto()
{
    mapeo.ventana(0,0,size().width()-ancho,size().height());
    mapeo.puerto(0,0,size().width()-ancho,size().height());
    L = 0;
    M = size().height();

}

void Widget::lineTo3D(int x, int y, int z, float alpha, float phi,int i)
{
    int xp,yp;
    int longitud;
    float tanAlpha;

    if((tanAlpha = tan(alpha)) != 0)
        longitud = (int)(z/tanAlpha);
    else
        longitud = 0;
    xp = x + (longitud * cos(phi));
    yp = y + (longitud * sin(phi));

    int x1,y1;
    mapeo.mapear(xp,yp,x1,y1,L,M);

    points[i].setX(x1);
    points[i].setY(y1);


}

void Widget::moveTo3D(int x, int y, int z, float alpha, float phi,int i)
{
    int xp,yp;
    int longitud;
    float tanAlpha;

    if((tanAlpha = tan(alpha)) != 0)
        longitud = (int)(z/tanAlpha);
    else
        longitud = 0;
    xp = x + (longitud * cos(phi));
    yp = y + (longitud * sin(phi));

    int x1,y1;
    mapeo.mapear(xp,yp,x1,y1,L,M);

    points[i].setX(x1);
    points[i].setY(y1);

}


void Widget::on_dial_valueChanged(int value)
{
    alpha = value;
    ui->lcdNumber->display(ui->dial->value());
    inicializaPuerto();
    update();
}


void Widget::on_dial_2_valueChanged(int value)
{
    phi = value;
    ui->lcdNumber_2->display(ui->dial_2->value());
    inicializaPuerto();
    repaint();
}

