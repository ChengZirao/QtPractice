#include "widget.h"
#include "ui_widget.h"
#include<QPushButton>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //创建一个老师对象
    zt=new Teacher(this);//括号里写this是为了让它加入对象树中，这样new出来的对象就不用管内存释放了！
    //创建一个学生对象
    st=new Student(this);
    void(Teacher:: * p)(QString)=&Teacher::hungry;
    //ClassIsOver();
    QPushButton * btn=new QPushButton("下课");
    //以classisover函数作为有参函数hungry的trigger，这样不用像黑马那样使用函数指针
    connect(btn,&QPushButton::clicked,this,&Widget::ClassIsOver);
    //disconnect(btn,&QPushButton::clicked,this,&Widget::ClassIsOver);
    connect(zt,&Teacher::hungry,this,&Widget::close);
}
void Widget::ClassIsOver()
{
    //下课函数，调用后触发老师饿了的信号
    emit zt->hungry("fried chicken");//emit,当调用classisover函数时调用hungry函数(但好像不加emit也没关系呀！因为不管加不加都会调用hungry函数呀！)
}
Widget::~Widget()
{
    delete ui;
}

