#include "mycoin.h"
#include<QDebug>
//MyCoin::MyCoin(QWidget *parent) : QPushButton(parent)
//{

//}
MyCoin::MyCoin(QString btnImg)
{
    QPixmap pix;
    bool ret=pix.load(btnImg);
    if(!ret)
    {
        qDebug()<<QString("图片%1加载失败").arg(btnImg);
        return;
    }
    pix=pix.scaled(pix.width()*2,pix.height()*2);
    this->setIcon(pix);
    this->setFixedSize(pix.width(),pix.height());
    this->setStyleSheet("QPushButton{border:0px;}");
    this->setIconSize(QSize(pix.width(),pix.height()));

    //初始化定时器对象
    timer1=new QTimer(this);
    timer2=new QTimer(this);

    //连接定时器和翻金币动作
    connect(timer1,&QTimer::timeout,[=](){
        QPixmap pix;
        //每30毫秒一帧，实现动画效果
        QString str=QString(":/new/prefix1/res/Coin000%1.png").arg(this->min++);
        pix.load(str);

        pix=pix.scaled(pix.width()*2,pix.height()*2);
        this->setIcon(pix);
        this->setFixedSize(pix.width(),pix.height());
        this->setStyleSheet("QPushButton{border:0px;}");
        this->setIconSize(QSize(pix.width(),pix.height()));

        //判断如果翻完了，min重置为1，且计时器停止
        if(this->max<this->min)
        {
            this->min=1;
            //计时器停止
            timer1->stop();
        }
    });

    //翻银币动作
    connect(timer2,&QTimer::timeout,[=](){
        QPixmap pix;
        QString str=QString(":/new/prefix1/res/Coin000%1.png").arg(this->max--);
        pix.load(str);

        pix=pix.scaled(pix.width()*2,pix.height()*2);
        this->setIcon(pix);
        this->setFixedSize(pix.width(),pix.height());
        this->setStyleSheet("QPushButton{border:0px;}");
        this->setIconSize(QSize(pix.width(),pix.height()));

        //判断如果翻完了，min重置为1，且计时器停止
        if(this->min>this->max)
        {
            this->max=8;
            //计时器停止
            timer2->stop();
        }
    });
}
//改变正反面标志的函数
void MyCoin::changeFlag()
{
    //如果是正面，翻反面
    if(this->flag)
    {
        //开始翻正面的定时器timer1
        timer1->start(30);
        //标记为银币
        flag=0;
    }
    else
        //翻反面定时器timer2
    {
        //标记为金币
        timer2->start(30);
        flag=1;
    }
}
