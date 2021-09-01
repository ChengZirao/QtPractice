#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QPushButton>

class MyPushButton : public QPushButton
{
    Q_OBJECT
public:
    //不用系统默认构造函数
    //explicit MyPushButton(QWidget *parent = nullptr);

    //重写构造函数 参数1 正常显示的图片路径 参数2 按下按钮后显示的图片路径
    MyPushButton(QString normalImg,QString pressImg="");

    //成员变量 保存用户传入的俩参数路径
    QString normalImgPath;
    QString pressImgPath;

    //弹跳特效
    void zoom1();//向下跳
    void zoom2();//向上跳

    //重写按钮 按下 和 释放 事件
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
signals:

};

#endif // MYPUSHBUTTON_H
