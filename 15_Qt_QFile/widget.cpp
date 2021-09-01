#include "widget.h"
#include "ui_widget.h"
#include<QFileDialog>
#include<QFile>
#include<QFileInfo>
#include<QDebug>
#include<QDateTime>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //用户点击"选取文件"按钮，弹出选择框，并在按钮左侧显示文件路径
    connect(ui->pushButton,&QPushButton::clicked,[=](){
        //path接收文件路径名称
        QString path=QFileDialog::getOpenFileName(this,"Open file","D:");
        //将文件路径放入lineEdit中
        ui->lineEdit->setText(path);
        QFile file(path);
        //设置打开方式为只读
        file.open(QIODevice::ReadOnly);


//////////////////读取全部文本并以byte array格式返回//////////////////
//        QByteArray array=file.readAll();


//////////////////按行读取文本//////////////////
        QByteArray array;
        //按行读取直到全部读完
        while(!file.atEnd())
        {
            array+=file.readLine();
        }


        //显示文本(setText里面也可直接填array，隐式转换)
        ui->textEdit->setText(QString(array));

        //关闭文件
        file.close();

//////////////////获取文件信息//////////////////
        QFileInfo info(path);
        qDebug()<<"大小："<<info.size()<<" 后缀名："<<info.suffix()<<" 文件名称："<<info.fileName()<<" 文件路径："<<info.path();

//////////////////两种方式获取日期//////////////////

        //第一种可通过fileTime的参数获取创建日期、最后一次修改日期等多个日期
        //qDebug()<<"创建日期："<<info.fileTime(QFileDevice::FileBirthTime).toString("yyyy/MM/dd hh.mm.ss.zzz").toUtf8().data();

        //第二种只能获取创建日期
        qDebug()<<"创建日期："<<info.birthTime().toString("yyyy/MM/dd hh.mm.ss.zzz").toUtf8().data();


//        //写文件
//        //append以追加的方式写文件，如果直接QIODevice::WriteOnly，之前的文本内容就没了
//        file.open(QIODevice::Append);
//        file.write("杜甫");
//        file.close();
    });
}

Widget::~Widget()
{
    delete ui;
}

