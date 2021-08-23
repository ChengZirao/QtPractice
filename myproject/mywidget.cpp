#include "mywidget.h"
#include<QPushButton>
myWidget::myWidget(QWidget *parent)
    : QWidget(parent)
{
    QPushButton *btn=new QPushButton;
    btn->setParent(this);
    btn->setText("第一个按钮");
    QPushButton *btn2=new QPushButton("第二个按钮",this);
    //重置窗口大小
    resize(500,500);//参数为坐标
    //移动btn2按钮
    btn2->move(250,250);
    //设置窗口名字
    setWindowTitle("第一个窗口");
    //设置固定大小窗口(用户不能拖动更改大小)
    //setFixedSize(1000,1000);
    //参数1：信号的发送者；参数2：发送的信号(注意是函数的地址！)；参数3：信号的接收者(也就是窗口)；参数4：处理信号的槽函数(这里是将窗口关闭)
    connect(btn2,&QPushButton::clicked,this,&myWidget::close);
}

myWidget::~myWidget()
{
}

