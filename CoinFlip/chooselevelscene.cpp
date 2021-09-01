#include "chooselevelscene.h"
#include<QMenuBar>
#include<QPainter>
#include<QDebug>
#include<QLabel>
#include<QSound>
#include"mypushbutton.h"
ChooseLevelScene::ChooseLevelScene(QWidget *parent) : QMainWindow(parent)
{
    setFixedSize(680,888);
    setWindowIcon(QIcon(":/new/prefix1/res/Coin0001.png"));
    setWindowTitle("选择关卡界面");

    //创建菜单栏(复习下代码方式)
    QMenuBar * bar=menuBar();
    //设置到窗口界面中
    setMenuBar(bar);

    //创建 开始 菜单
    QMenu * startMenu = bar->addMenu("开始");
    //创建 退出 菜单
    QAction * quitAction = startMenu->addAction("退出");

    //点击退出 退出游戏
    connect(quitAction,&QAction::triggered,this,&QMainWindow::close);

    //创建选择关卡音效
    QSound * chooseSound=new QSound(":/new/prefix1/res/TapButtonSound.wav",this);
    //创建返回按钮音效
    QSound * backSound=new QSound(":/new/prefix1/res/BackButtonSound.wav",this);

    //用MyPushButton实现返回按钮
    MyPushButton * backBtn = new MyPushButton(":/new/prefix1/res/BackButton.png",":/new/prefix1/res/BackButtonSelected.png");
    backBtn->setParent(this);
    //移动Back按钮到右下角
    backBtn->move(this->width()-backBtn->width(),this->height()-backBtn->height());

    //点击Back 返回上一页
    connect(backBtn,&MyPushButton::clicked,[=](){
        //播放返回音效
        backSound->play();
        //发送信号，写信号的原因是mainScene无法直接连接back按钮，所以需要信号作为媒介
        emit chooseBack();
    });

    //设置关卡选择按钮
    //只用一个for循环画出矩阵
    for(int i=0;i<20;i++)
    {
        MyPushButton * menuBtn=new MyPushButton(":/new/prefix1/res/LevelIcon.png");
        menuBtn->setParent(this);
        menuBtn->move(155 + i%4 * 100,220 + i/4 *100);
        QLabel * label=new QLabel(this);
        label->setText(QString::number(i+1));
        label->setFixedSize(menuBtn->width(),menuBtn->height());
        label->move(155 + i%4 * 100,220 + i/4 *100);

        //点击关卡，进入关卡界面
        connect(menuBtn,&MyPushButton::clicked,[=](){
            //播放点击关卡音效
            chooseSound->play();

            play=new PlayScene(i+1);
            this->hide();
            play->show();
            //接收关卡返回信号，返回到当前页面
            connect(play,&PlayScene::choosePlayBack,[=](){
                //播放返回音效
                backSound->play();
                delete play;
                this->show();
                play=NULL;
            });
        });


        //设置label上文字的对齐方式，水平居中和垂直居中
        //label边框大小和menuBtn一样，让文字在这个边框范围内居中，就相当于在圆按钮内居中，这样可以直接设置label的坐标和menuBtn一致，非常方便
        label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

        //设置label鼠标穿透事件(否则label覆盖按钮，按钮接收不到点击信号)
        //51号属性
        label->setAttribute(Qt::WA_TransparentForMouseEvents);
    }
}

void ChooseLevelScene::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/new/prefix1/res/OtherSceneBg.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
    pix.load(":/new/prefix1/res/Title.png");
    //放大图片
    pix=pix.scaled(pix.width()*1.5,pix.height()*1.5);
    //居中
    painter.drawPixmap((this->width()-pix.width())*0.5,30,pix);
}
