#include "widget.h"
#include "ui_widget.h"
#include<QDebug>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //关联“获取值”和smallwidget
    connect(ui->btn_Get,&QPushButton::clicked,[this](){qDebug()<<ui->xiaowidget->getNum();});
    //关联“设置值”
    connect(ui->btn_Set,&QPushButton::clicked,[=](){smallWidget *s=ui->xiaowidget;s->setNum(50);});
}

Widget::~Widget()
{
    delete ui;
}
