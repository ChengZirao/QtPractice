#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //使用添加的qt资源" : + 前缀名 / 文件名 "
    //注意每次添加前先编译(左下角的锤子)，这样才能看到新写的action和新添加的图片
    ui->actionnew->setIcon(QIcon(":/new/prefix1/ProfilePhoto.png"));
    ui->actionadd->setIcon(QIcon(":/new/prefix1/ProfilePhoto.JPG"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

