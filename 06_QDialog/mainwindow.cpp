#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDialog>
#include<QDebug>
#include<QMessageBox>
#include<QColorDialog>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //点击按钮，弹出一个对话框(QAction没有clicked，用triggered代替)
    connect(ui->actionNew,&QAction::triggered,[=](){
//        对话框分类
//        模态对话框(不可以对其他窗口操作) 和 非模态对话框(打开该框的同时可以对其它窗口操作)
//        模态创建(include QDialog)
//        QDialog dlg(this);
//        dlg.resize(600,400);
//      //以模态形式打开(和main函数的return a.exec()是不同的！具体查帮助)
//        dlg.exec();

//        窗口出现后这句话并不会显示！因为模态对话框的出现阻塞了后续代码的运行！当对话框被关闭后这句话才会显示
//        qDebug()<<"模态对话框弹出了";

//        //非模态创建
//        QDialog * dlg2=new QDialog(this);
//        dlg2->resize(600,400);
//        //Makes Qt delete this widget when the widget has accepted the close event
//        //防止内存泄露！！时刻注意关掉小窗口并没有释放内存！只不过窗口没有show()出来而已
//        dlg2->setAttribute(Qt::WA_DeleteOnClose);//55号属性
//        dlg2->show();

        //消息对话框
        //QMessageBox::critical(this,"标题","Error!!");
//        QMessageBox *qmb=new QMessageBox;
//        qmb->resize(1000,1000);
//        qmb->critical(this,"Title","error",QMessageBox::Cancel|QMessageBox::Open,QMessageBox::Cancel);

        //颜色对话框
        QColor color=QColorDialog::getColor();
        qDebug()<<"r="<<color.red()<<" g="<<color.green()<<" b="<<color.blue();
        int a=11;a;
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

