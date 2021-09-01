#include "playscene.h"
#include<QMenuBar>
#include<QPainter>
#include<mypushbutton.h>
#include<QLabel>
#include<QDebug>
#include<QPropertyAnimation>
#include<QSound>
#include"dataconfig.h"
//PlayScene::PlayScene(QWidget *parent) : QMainWindow(parent)
//{

//}
PlayScene::PlayScene(int levelNum)
{
    this->levelIndex=levelNum;
    setFixedSize(680,888);
    setWindowIcon(QIcon(":/new/prefix1/res/Coin0001.png"));
    QString title = QString("关卡%1").arg(levelNum);
    setWindowTitle(title);

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

    //用MyPushButton实现返回按钮
    MyPushButton * backBtn = new MyPushButton(":/new/prefix1/res/BackButton.png",":/new/prefix1/res/BackButtonSelected.png");
    backBtn->setParent(this);
    //移动Back按钮到右下角
    backBtn->move(this->width()-backBtn->width(),this->height()-backBtn->height());

    //点击Back 返回上一页
    connect(backBtn,&MyPushButton::clicked,[=](){
        //发送信号
        emit choosePlayBack();
    });

    //放置胜利图片
    QLabel * winLabel=new QLabel(this);
    QPixmap winPix;
    winPix.load(":/new/prefix1/res/LevelCompletedDialogBg.png");
    winPix=winPix.scaled(winPix.width()*2,winPix.height()*2);
    winLabel->setPixmap(winPix);
    winLabel->setGeometry(0,0,winPix.width(),winPix.height());
    //winLabel->setFixedSize(winPix.width(),-winPix.height());

    //隐藏在界面上方
    winLabel->move((this->width()-winPix.width())*0.5,-winPix.height());

    dataConfig config;
    //初始化每个关卡的二维数组
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            //记录第levelIndex关的第i行j列硬币的类型
            this->gameArray[i][j]=config.mData[this->levelIndex][i][j];
        }
    }

    //设置游戏胜利音效(素材源自最终幻想胜利音效)
    QSound * vicSound=new QSound(":/new/prefix1/res/Victory.wav",this);

    //绘制背景图片
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            QPixmap pix;
            pix.load(":/new/prefix1/res/BoardNode.png");
            pix=pix.scaled(pix.width()*2,pix.height()*2);
            QLabel * label=new QLabel(this);
            label->setPixmap(pix);
            label->setGeometry(0,0,pix.width(),pix.height());
            label->move(145 + i*100,280 + j*100);

            //放置硬币类型
            QString str;
            if(this->gameArray[i][j]==1)
            {
                //放置金币
                str=":/new/prefix1/res/Coin0001.png";
            }
            else
            {
                //放置银币
                str=":/new/prefix1/res/Coin0008.png";
            }
            MyCoin * coin=new MyCoin(str);
            coin->setParent(this);
            coin->move(145 + i*100,280 + j*100);

            //给硬币属性赋值
            coin->posX=i;
            coin->posY=j;
            coin->flag=this->gameArray[i][j];//1正面 0反面

            //将硬币的信息保存进二维数组中,便于后期维护
            coinBtn[i][j]=coin;

            //点击硬币，翻转自身及周围硬币
            //每new出一个coin，都建立该coin的连接，因此连接不能写在循环外!
            connect(coin,&MyCoin::clicked,[=](){
                coin->changeFlag();

                //翻转周围硬币
                //延时翻转
                QTimer::singleShot(300,this,[=](){
                    //判断是否在右边界以内
                    if(coin->posX+1<=3)
                    {
                        coinBtn[coin->posX+1][coin->posY]->changeFlag();
                    }
                    //判断是否在左边界以内
                    if(coin->posX-1>=0)
                    {
                        coinBtn[coin->posX-1][coin->posY]->changeFlag();
                    }
                    //判断是否在上边界以内
                    if(coin->posY-1>=0)
                    {
                        coinBtn[coin->posX][coin->posY-1]->changeFlag();
                    }
                    //判断是否在下边界以内
                    if(coin->posY+1<=3)
                    {
                        coinBtn[coin->posX][coin->posY+1]->changeFlag();
                    }

                    //判断是否胜利
                    //每点击一次硬币，遍历整个硬币矩阵
                    this->isWin=true;
                    for(int i=0;i<4;i++)
                    {
                        for(int j=0;j<4;j++)
                        {
                            //只要有一个是反面，就不是胜利
                            if(coinBtn[i][j]->flag==false)
                            {
                                this->isWin=false;
                                break;
                            }
                        }
                    }
                    //遍历过后，如果所有硬币都是金币
                    if(this->isWin==true)
                    {
                        //胜利了!
                        qDebug()<<"胜利了！";
                        //播放胜利音乐！
                        vicSound->play();
                        //将胜利图片移动下来
                        QPropertyAnimation * animation=new QPropertyAnimation(winLabel,"geometry");
                        animation->setDuration(1000);
                        animation->setStartValue(QRect(winLabel->x(),winLabel->y(),winLabel->width(),winLabel->height()));
                        animation->setEndValue(QRect(winLabel->x(),winLabel->y()+280,winLabel->width(),winLabel->height()));
                        //设置缓和曲线
                        animation->setEasingCurve(QEasingCurve::OutBounce);
                        animation->start();
                    }
                });

            });
        }
    }
}

void PlayScene::paintEvent(QPaintEvent *)
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
