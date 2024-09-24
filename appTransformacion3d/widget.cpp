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

    tX = tY = tZ = 0;

    xC = ui->spinBox->value();
    yC = ui->spinBox_2->value();
    zC = ui->spinBox_3->value();

    anguloX = anguloY = anguloZ = 0;

    rX = rY = rZ = false;
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
    Puntos3D cubobase[] = {{100,50,0,0},   {200,50,0,1},  {200,150,0,1},  {100,150,0,1},
                           {100,50,0,1},   {100,50,100,1},{200,50,100,1}, {200,150,100,1},
                           {200,150,0,1},  {200,50,0,0},  {200,50,100,1}, {100,50,100,0},
                           {100,150,100,1},{100,150,0,1}, {100,150,100,0},{200,150,100,1}};

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

    int x,y,z;

    for(int i = 0; i< 16; i++)
    {
        x = cubo[i].x;
        y = cubo[i].y;
        z = cubo[i].z;

        if(rX){
            x = cubo[i].x;
            y = round((yC+(cubo[i].y-yC)*cos(radianes(anguloX))+(cubo[i].z-zC)*sin(radianes(anguloX)))+0.5);
            z = round((zC+(-(cubo[i].y-yC)*sin(radianes(anguloX)))+(cubo[i].z-zC)*cos(radianes(anguloX)))+0.5);
        }if( rY ) {
            y = cubo[i].y;
            x = round((xC+(cubo[i].x-xC)*cos(radianes(anguloY))-(cubo[i].z-zC)*sin(radianes(anguloY)))+0.5);
            z = round((zC+(cubo[i].x-xC)*sin(radianes(anguloY))+(cubo[i].z-zC)*cos(radianes(anguloY)))+0.5);
        } if (rZ) {
            z = cubo[i].z;
            x = round((xC+(cubo[i].x-xC)*cos(radianes(anguloZ))-(cubo[i].y-yC)*sin(radianes(anguloZ)))+0.5);
            y = round((yC+(cubo[i].x-xC)*sin(radianes(anguloZ))+(cubo[i].y-yC)*cos(radianes(anguloZ)))+0.5);
        }



        //Agregar Rotacion en y , z
        if(cubo[i].opcion)
           lineTo3D(x+tX,y+tY,z+tZ,radianes(alpha),qDegreesToRadians(phi),i);
            else
            moveTo3D(x+tX,y+tY,z+tZ,radianes(alpha),qDegreesToRadians(phi),i);
    }

        /*
    for(int i = 0; i< 16; i++)
        if(cubo[i].opcion)
            lineTo3D(cubo[i].x+tX,cubo[i].y+tY,cubo[i].z+tZ,radianes(alpha),qDegreesToRadians(phi),i);
    else
            moveTo3D(cubo[i].x+tX,cubo[i].y+tY,cubo[i].z+tZ,radianes(alpha),qDegreesToRadians(phi),i);
*/

    update();
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

void Widget::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Left)
    {
        tX -=5;
    }
    if(event->key() == Qt::Key_Right)
    {
        tX +=5;
    }
    //agregar flecha arriva-abajo
    if(event->key() == Qt::Key_Down)
    {
        tY -=5;
    }
    if(event->key() == Qt::Key_Up)
    {
        tY +=5;
    }
    //agregar para trasladar en z : 9 = z+, 0 = z-
    if(event->key() == Qt::Key_1)
    {
        tZ -=5;
    }
    if(event->key() == Qt::Key_2)
    {
        tZ +=5;
    }
    //rotacion con  teclas
    //positivo
    if(event->key() == Qt::Key_X)
    {
        anguloX += 5;
        rX = true;
        rY = false;
        rZ = false;
    }
    //rot.negatona
    if(event->key() == Qt::Key_C)
    {
        anguloX -= 5;
        rX = true;
        rY = false;
        rZ = false;
    }
   // rotacion en y positiva
    if(event->key() == Qt::Key_Y)
    {
        anguloY += 5;
        rX = false;
        rY = true;
        rZ = false;
    }
    // rotacion en y negativa
    if(event->key() == Qt::Key_U)
    {
        anguloY -= 5;
        rX = false;
        rY = true;
        rZ = false;
    }
    // rotacion en Z negativa
    if(event->key() == Qt::Key_Z)
    {
        anguloZ += 5;
        rX = false;
        rY = false;
        rZ = true;
    }
    // rotacion en Z positiva
    if(event->key() == Qt::Key_A)
    {
        anguloZ -= 5;
        rX = false;
        rY = false;
        rZ = true;
    }



    update();

}

void Widget::on_checkBox_stateChanged(int arg1)
{
    if(ui->checkBox->isChecked())
    {
        ui->widget->setEnabled(false);
    }else{
        ui->widget->setEnabled(true);
    }
}


void Widget::on_pushButton_clicked()
{
    alpha = 63.4;
    phi   = 30.0;

    tX = tY = tZ = 0;

    //ESTABLECER EL EJE DE GIRO
    // 1ero. CON RESPECTO A UN EJE PIVOTE
    // CONSIDERANDO EL CENTRO DEL CUBO
    // EN CADA UNO DE SUS EJES

    xC = ui->spinBox->value();
    yC = ui->spinBox_2->value();
    zC = ui->spinBox_3->value();

    rX = rY = rZ = false;

    anguloX = anguloY = anguloZ = 0;

    update();
}


void Widget::on_pushButton_2_clicked()
{
    tZ--;
    update();
}


void Widget::on_spinBox_valueChanged(int valor)
{
    xC = valor;
    //inicializaPuerto();
    repaint();
}


void Widget::on_spinBox_2_valueChanged(int valor)
{
    yC = valor;
    //inicializaPuerto();
    repaint();
}


void Widget::on_spinBox_3_valueChanged(int valor)
{
    zC = valor;
    //inicializaPuerto();
    repaint();
}

