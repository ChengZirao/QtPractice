#include "widget.h"
#include "ui_widget.h"
#include<QDebug>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    qDebug()<<"abaaba";
    //treeWidget树控件的使用
    //设置水平头
    ui->treeWidget->setHeaderLabels(QStringList()<<"英雄"<<"英雄介绍");//这里使用了匿名对象
    QTreeWidgetItem * liItem = new QTreeWidgetItem(QStringList()<<"力量");
    QTreeWidgetItem * minItem = new QTreeWidgetItem(QStringList()<<"敏捷");
    QTreeWidgetItem * zhiItem = new QTreeWidgetItem(QStringList()<<"智力");
    ui->treeWidget->addTopLevelItem(liItem);
    ui->treeWidget->addTopLevelItem(minItem);
    ui->treeWidget->addTopLevelItem(zhiItem);
    QTreeWidgetItem * hero = new QTreeWidgetItem(QStringList()<<"源氏"<<"源氏在此");
    liItem->addChild(hero);
}

Widget::~Widget()
{
    delete ui;
}

