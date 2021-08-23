#include "widget.h"
#include "ui_widget.h"
#include<QPixmap>
#include<QPainter>
#include<QImage>
#include<QPicture>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

//    //QPixmap作为绘图设备，专门为平台做了显示优化
//    QPixmap pix(400,400);
//    pix.fill(Qt::white);
//    QPainter painter(&pix);
//    painter.setPen(Qt::green);
//    painter.drawEllipse(QPointF(200,200),150,150);
//    //保存到桌面(注意每个目录都要写双反斜杠！！)
//    pix.save("C:\\Users\\orang_9qy7n8e\\Desktop\\pix.png");


    //QPicture作为绘图设备，可以记录和重现绘图指令(保存的文件从外部打不开，只能用代码打开)
        QPicture pic;
        QPainter painter;
        painter.begin(&pic);//在pic上作图，相当于QPainter painter(&pic);
        painter.setPen(Qt::green);
        painter.drawEllipse(QPointF(200,200),150,150);
        painter.end();//结束作图
        //保存到桌面
        pic.save("C:\\Users\\orang_9qy7n8e\\Desktop\\pix.czr");
}

//重写paintEvent
void Widget::paintEvent(QPaintEvent *event)
{
//    //QImage作为绘图设备，可进行像素级别的修改
//    QPainter painter(this);
//    QImage img;
//    //加载图片
//    img.load(":/new/prefix1/ProfilePhoto.JPG");
//    for(int i=0;i<100;i++)
//    {
//        for(int j=0;j<100;j++)
//        {
//            //像素点修改(涂红)
//            QRgb value=qRgb(255,0,0);
//            img.setPixel(i,j,value);
//        }
//    }
//    //在窗口显示
//    painter.drawImage(0,0,img);
    
    
    ////////QPicture作为绘图设备//////
    QPainter painter(this);
    QPicture pic;
    pic.load("C:\\Users\\orang_9qy7n8e\\Desktop\\pix.czr");
    painter.drawPicture(0,0,pic);
}
Widget::~Widget()
{
    delete ui;
}

