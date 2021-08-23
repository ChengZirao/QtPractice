#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //设置列数
    ui->tableWidget->setColumnCount(3);
    //设置水平表头
    ui->tableWidget->setHorizontalHeaderLabels(QStringList()<<"姓名"<<"性别"<<"年龄");
    //设置行数
    ui->tableWidget->setRowCount(5);
    //添加角色
    //ui->tableWidget->setItem(0,0,new QTableWidgetItem("维吉尔"));//匿名对象指针
    QStringList namelist;
    namelist<<"Virgil"<<"Arthur Morgan"<<"Peter Parker"<<"Dragonborn"<<"Genji";
    for(int i=0;i<5;i++)
    {
        int col=0;
        ui->tableWidget->setItem(i,col++,new QTableWidgetItem(namelist[i]));
        ui->tableWidget->setItem(i,col++,new QTableWidgetItem("Male"));
        //int转QString
        ui->tableWidget->setItem(i,col++,new QTableWidgetItem(QString::number(i+18)));
    }
}

Widget::~Widget()
{
    delete ui;
}

