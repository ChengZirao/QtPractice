#ifndef MYCOIN_H
#define MYCOIN_H

#include <QPushButton>
#include<QTimer>
class MyCoin : public QPushButton
{
    Q_OBJECT
public:
    //explicit MyCoin(QWidget *parent = nullptr);

    //重写构造函数 参数列表 传入的为金币路径还是银币路径
    MyCoin(QString btnImg);

    //硬币的位置属性
    int posX,posY;
    //正反标志
    bool flag;

    //改变标志的函数
    void changeFlag();
    QTimer * timer1;//正面翻反面的计时器
    QTimer * timer2;//反面翻正面的计时器
    int min=1,max=8;

signals:

};

#endif // MYCOIN_H
