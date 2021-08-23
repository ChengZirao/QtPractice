#include "widget.h"
#include "ui_widget.h"
#include<QPainter> //画图类
#include<QDebug>
#include<QTimer>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(ui->btn,&QPushButton::clicked,[=](){
        posX+=20;
        //手动调用paintEvent函数不能直接写paintEvent()，要写update()
        update();
    });

    ////////////利用计时器自动移动图片////////////
    QTimer *timer=new QTimer(this);
    timer->start(1000);
    connect(timer,&QTimer::timeout,[=](){
        posX+=20;
        update();
    });
}

//重写绘图事件(paintEvent函数不需写进构造函数中！系统会自动调用！！)
void Widget::paintEvent(QPaintEvent *event)
{
//    //实例化画家对象，this指定的是绘图设备！
//    QPainter painter(this);

//    //设置画笔
//    //painter.setPen(QColor(255,0,0));
//    //或者如果要一次设置多个属性，可以这么写
//    QPen pen(QColor(255,0,0));
//    //设置画笔画图宽度
//    pen.setWidth(3);
//    //设置style
//    pen.setStyle(Qt::DashLine);
//    painter.setPen(pen);

//    //设置画刷(填充图形)
//    //设置画刷颜色
//    QBrush brush(Qt::cyan,Qt::Dense1Pattern);
//    //也可以brush.setStyle(Qt::Dense1Pattern);
//    painter.setBrush(brush);

//    //画线
//    painter.drawLine(QPoint(0,0),QPoint(100,200));

//    //画椭圆(rx==ry时为圆)
//    painter.drawEllipse(QPoint(100,100),50,50);

//    //画矩形
//    painter.drawRect(QRectF(QPointF(200,200),QPointF(400,400)));
//    qDebug()<<"drawline";

//    //画文字
//    painter.drawText(QRect(20,200,150,50),"好好学习天天向上");


//    /////////////高级设置////////////
//    QPainter painter(this);
//    painter.drawEllipse(200,200,200,200);
//    //设置抗锯齿
//    painter.setRenderHint(QPainter::Antialiasing);
//    painter.drawEllipse(400,200,200,200);

    ///////////利用画家 画resource图片///////////
    QPainter painter(this);
    painter.drawPixmap(posX,20,QPixmap(":/new/prefix1/ProfilePhoto.JPG"));
}



Widget::~Widget()
{
    delete ui;
}

