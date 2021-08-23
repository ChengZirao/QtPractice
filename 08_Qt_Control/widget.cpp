#include "widget.h"
#include "ui_widget.h"
//#include<QListWidgetItem>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //默认选中男的
    ui->rbtnMan->setChecked(true);
    QListWidgetItem * item=new QListWidgetItem("苟利国家生死以");
    ui->listWidget->addItem(item);
}

Widget::~Widget()
{
    delete ui;
}

