#include "mainscene.h"
#include "ui_mainscene.h"
#include<QPainter>
#include"mypushbutton.h"
#include<QTimer>
#include<QDebug>
#include<QSound>
MainScene::MainScene(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainScene)
{
    ui->setupUi(this);

    //设置主场景
    //设置固定大小
    setFixedSize(680,888);
    //设置主场景图标
    setWindowIcon(QIcon(":/new/prefix1/res/Coin0001.png"));
    setWindowTitle("饶's CoinFlip");
    //退出按钮设置
    connect(ui->actionquit,&QAction::triggered,this,&QMainWindow::close);

    //开始音效的设置(需在pro文件QT += multimedia)
    QSound * startSound=new QSound(":/new/prefix1/res/TapButtonSound.wav",this);

    //开始按钮(引用mypushbutoon.h) 载入normal图片
    MyPushButton * startBtn=new MyPushButton(":/new/prefix1/res/MenuSceneStartButton.png");
    startBtn->setParent(this);
    //按钮位置下方居中
    startBtn->move(this->width()*0.5 - startBtn->width()*0.5,this->height()*0.7);

    //实例化选择关卡场景(chooseScene在头文件中声明)
    chooseScene=new ChooseLevelScene;

    connect(startBtn,&MyPushButton::clicked,[=](){
        //设置开始按钮点击音效
        startSound->play();

        startBtn->zoom1();
        startBtn->zoom2();

        //进入到选择关卡场景中
        //延时隐藏(否则隐藏太快，没有按钮弹跳特效)
        //参数1 延时400毫秒(因为zoom1和2的总执行时间为500毫秒) 参数2 指定延时对象
        QTimer::singleShot(400,this,[=](){
            //自身隐藏
            this->hide();
            //显示选择关卡场景
            chooseScene->show();
        });
    });

    //点击Back 返回上一页
    connect(chooseScene,&ChooseLevelScene::chooseBack,[=](){
        chooseScene->hide();
        this->show();
    });
}

//重写paintEvent事件，画背景图
void MainScene::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    //画背景图
    pix.load(":/new/prefix1/res/PlayLevelSceneBg.png");
    //width()和height()，为指定拉伸(缩放)的宽和高，这里设置和窗口大小一致，相当于填满窗口
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

    //画背景上图标
    pix.load(":/new/prefix1/res/Title.png");
    pix=pix.scaled(pix.width()*1.5,pix.height()*1.5);
    painter.drawPixmap(0,0,pix);
}

MainScene::~MainScene()
{
    delete ui;
}

