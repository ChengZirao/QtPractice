#include "mylabel.h"
#include<QDebug>
#include<QMouseEvent>
myLabel::myLabel(QWidget *parent) : QLabel(parent)
{

}
//鼠标进入事件
void myLabel::enterEvent(QEvent *event)
{
    qDebug()<<"鼠标进入了";
    //this->close();
}
//鼠标离开事件
void myLabel::leaveEvent(QEvent *event)
{
    //qDebug()<<"鼠标离开了";
}

//鼠标按压事件
void myLabel::mousePressEvent(QMouseEvent *ev)
{
    //qDebug()<<"鼠标按下了";
    //当鼠标按下左键，提示信息
    if(ev->button()==Qt::LeftButton)
        qDebug()<<"鼠标按下了左键";
    //鼠标点击的xy坐标(坐标基于控件)
    //匿名对象Qstring
    qDebug()<<QString ("鼠标点击的坐标x=%1,y=%2").arg(ev->x()).arg(ev->y());
}
//鼠标释放事件
void myLabel::mouseReleaseEvent(QMouseEvent *ev)
{
    qDebug()<<"鼠标释放了";
}
//鼠标移动事件(默认情况下只有按压鼠标时移动才算移动)
void myLabel::mouseMoveEvent(QMouseEvent *ev)
{
    //设置为true后不按压鼠标也可以接收到移动
    setMouseTracking(true);
    qDebug()<<"鼠标移动了";
}
