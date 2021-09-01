#ifndef PLAYSCENE_H
#define PLAYSCENE_H

#include <QMainWindow>
#include"mycoin.h"

class PlayScene : public QMainWindow
{
    Q_OBJECT
public:
    //explicit PlayScene(QWidget *parent = nullptr);
    //重写构造函数
    PlayScene(int levelNum);

    //重写paintEvent
    void paintEvent(QPaintEvent *);

    //成员变量，记录所选关卡
    int levelIndex;

    int gameArray[4][4];//二维数组，维护每个关卡的硬币类型数据

    //硬币二维数组，用于保存每一枚硬币的信息
    MyCoin * coinBtn[4][4];

    //是否胜利的标志
    bool isWin;
signals:
    //返回信号
    void choosePlayBack();
};

#endif // PLAYSCENE_H
