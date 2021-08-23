#include "testwidget.h"
#include "ui_testwidget.h"
#include<QPushButton>
#include<QDebug>
TestWidget::TestWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TestWidget)
{
    //ui->setupUi(this);
    resize(500,500);
    QWidget *qw=new QWidget(this);
    qw->setWindowTitle("作业");
    //qw->setParent(this);
    QPushButton *btn1=new QPushButton("Open",this);
    QPushButton *btn2=new QPushButton("Close",this);
    btn2->move(300,300);
    //connect(btn1,&QPushButton::clicked,[qw](){qw->show();});
    //connect(btn2,&QPushButton::clicked,[qw](){qw->close();});
    connect(btn1,&QPushButton::clicked,[qw,btn1](){
        if(btn1->text()=="Open") {qw->show();btn1->setText("Close");}
        else {qw->close();btn1->setText("Open");}
    });
}

TestWidget::~TestWidget()
{
    delete ui;
}

