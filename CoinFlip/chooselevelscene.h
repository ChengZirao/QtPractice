#ifndef CHOOSELEVELSCENE_H
#define CHOOSELEVELSCENE_H

#include <QMainWindow>
#include"playscene.h"
class ChooseLevelScene : public QMainWindow
{
    Q_OBJECT
public:
    explicit ChooseLevelScene(QWidget *parent = nullptr);

    //重写paintEvent事件，画背景图
    void paintEvent(QPaintEvent *);

    //游戏场景对象指针
    PlayScene * play=NULL;
signals:
    //点击back，返回开始界面
    void chooseBack();
};

#endif // CHOOSELEVELSCENE_H
