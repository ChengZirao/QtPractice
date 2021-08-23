#include "widget.h"
#include "ui_widget.h"
#include<QTimer>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //启动定时器(调用timerEvent函数)
    startTimer(1000);//参数interval为间隔，单位为毫秒

    //定时器的第二种启动方式(不调用timerEvent函数的方式！更推荐用第二种！！)
    QTimer * timer=new QTimer(this);
    //启动定时器
    timer->start(2000);
    connect(timer,&QTimer::timeout,[=](){
       static int num=1;
       //label_3每隔2秒加1
       ui->label_3->setText(QString::number(num++));
    });

    //(针对第二种方式)点击"暂停"，计时器停止
    connect(ui->btn,&QPushButton::clicked,[=](){
        timer->stop();
        //ui->label_3->resize(200,200);
    });
}

//重写定时器timerEvent函数
void Widget::timerEvent(QTimerEvent *)
{
    static int num=1;
    ui->label_2->setText(QString::number(num++));
}

Widget::~Widget()
{
    delete ui;
}

