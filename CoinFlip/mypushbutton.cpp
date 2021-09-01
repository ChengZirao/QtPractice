#include "mypushbutton.h"
#include<QDebug>
#include<QPropertyAnimation>
//MyPushButton::MyPushButton(QWidget *parent) : QPushButton(parent)
//{

//}

//注意！函数的声明或定义只能有一个有(pressImg = "")，刚在声明写过了，故定义一定要删掉( = "" )
MyPushButton::MyPushButton(QString normalImg,QString pressImg)
{
    //保存两个路径
    this->normalImgPath=normalImg;
    this->pressImgPath=pressImg;
    QPixmap pix;
    //加载normal图片
    bool ret=pix.load(normalImg);
    //判断加载是否成功，若不成功，输出"图片加载失败"
    if(!ret)
    {
        qDebug()<<"图片加载失败";
        return;
    }
    //放大图片1.5倍
    pix=pix.scaled(pix.width()*1.5,pix.height()*1.5);
    //设置图片固定大小
    this->setFixedSize(pix.width(),pix.height());

    //设置不规则图片样式(为了显示出圆形Start按钮)
    this->setStyleSheet("QPushButton{border:0px;}");

    //设置图标
    this->setIcon(pix);

    //设置图标大小
    this->setIconSize(QSize(pix.width(),pix.height()));
}

//弹跳特效
void MyPushButton::zoom1()//向下跳
{
    //创建动画对象 参数1 给谁创建对象 参数2 用什么特效
    QPropertyAnimation * animation = new QPropertyAnimation(this,"geometry");
    //设置动画时间间隔(单位:毫秒)
    animation->setDuration(200);

    //起始位置
    animation->setStartValue(QVariant(QRect(this->x(),this->y(),this->width(),this->height())));
    //结束位置(y轴坐标+10)
    animation->setEndValue(QVariant(QRect(this->x(),this->y()+10,this->width(),this->height())));

    //设置弹跳曲线
    animation->setEasingCurve(QEasingCurve::OutBounce);
    //执行动画
    animation->start();
}

void MyPushButton::zoom2()//向上跳，和zoom1的区别只是把起始和结束y轴坐标调换一下
{
    //创建动画对象 参数1 给谁使用特效 参数2 用什么特效
    QPropertyAnimation * animation = new QPropertyAnimation(this,"geometry");
    //设置动画时间间隔(单位:毫秒)
    animation->setDuration(200);

    //起始位置(y轴坐标+10)
    animation->setStartValue(QVariant(QRect(this->x(),this->y()+10,this->width(),this->height())));
    //结束位置(y轴坐标)
    animation->setEndValue(QVariant(QRect(this->x(),this->y(),this->width(),this->height())));

    //设置弹跳曲线
    animation->setEasingCurve(QEasingCurve::OutBounce);
    //执行动画
    animation->start();
}


//重写按钮 按下 和 释放 事件
void MyPushButton::mousePressEvent(QMouseEvent *e)
{
    //判断用户有没有传入第二张图片，只有传了才会执行以下操作
    //切换为第二张图片
    if(this->pressImgPath!="")
    {
        QPixmap pix;
        //加载第二张图片
        bool ret=pix.load(this->pressImgPath);
        //判断加载是否成功，若不成功，输出"图片加载失败"
        if(!ret)
        {
            qDebug()<<"图片加载失败";
            return;
        }
        //放大图片1.5倍
        pix=pix.scaled(pix.width()*1.5,pix.height()*1.5);
        //设置图片固定大小
        this->setFixedSize(pix.width(),pix.height());
        //设置不规则图片样式(为了显示出圆形Start按钮)
        this->setStyleSheet("QPushButton{border:0px;}");
        //设置图标
        this->setIcon(pix);

        //设置图标大小
        this->setIconSize(QSize(pix.width(),pix.height()));
    }
    //让父类执行其他内容
    return QPushButton::mousePressEvent(e);
}
void MyPushButton::mouseReleaseEvent(QMouseEvent *e)
{
    //切换为初始图片
    if(this->pressImgPath!="")
    {
        QPixmap pix;
        //加载初始图片
        bool ret=pix.load(this->normalImgPath);
        //判断加载是否成功，若不成功，输出"图片加载失败"
        if(!ret)
        {
            qDebug()<<"图片加载失败";
            return;
        }
        //放大图片1.5倍
        pix=pix.scaled(pix.width()*1.5,pix.height()*1.5);
        //设置图片固定大小
        this->setFixedSize(pix.width(),pix.height());
        //设置不规则图片样式(为了显示出圆形Start按钮)
        this->setStyleSheet("QPushButton{border:0px;}");

        //设置图标
        this->setIcon(pix);

        //设置图标大小
        this->setIconSize(QSize(pix.width(),pix.height()));
    }
    return QPushButton::mouseReleaseEvent(e);
}
