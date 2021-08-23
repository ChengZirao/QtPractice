#include "mainwindow.h"
#include<QMenuBar>
#include<QDebug>
#include<QToolBar>
#include<QPushButton>
#include<QStatusBar>
#include<QLabel>
#include<QDockWidget>
#include<QTextEdit>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    resize(600,400);
    //菜单栏创建(最多有一个)，需包含头文件QMenuBar
    QMenuBar * bar =menuBar();//menubar函数已将QMenuBar变量归为对象树中了
    //将菜单栏放入窗口中
    setMenuBar(bar);
    setWindowTitle("菜单");
    //创建菜单
    QMenu*fileMenu=bar->addMenu("新建");
    QMenu*editMenu=bar->addMenu("编辑");
    //创建菜单项
    //fileMenu->addAction("新建");
    //添加分割线
    //fileMenu->addSeparator();
    //fileMenu->addAction("打开");

    //与此同时addAction函数也会实现，因此将上面的addAction注释掉，防止重复
    QAction * newAction=fileMenu->addAction("新建");
    QAction * openAction=fileMenu->addAction("打开");
    //工具栏，可以有多个
    QToolBar * toolBar = new QToolBar(this);
    //将创建好的工具栏放在窗口中，可多写一个停靠方位的参数
    addToolBar(Qt::LeftToolBarArea,toolBar);
    toolBar->setAllowedAreas(Qt::LeftToolBarArea|Qt::RightToolBarArea);
    //工具栏不可浮动
    toolBar->setFloatable(false);
    //toolbar的新建和打开与filemenu的是同一个(地址一样)
    toolBar->addAction(newAction);
    toolBar->addSeparator();
    toolBar->addAction(openAction);
    //工具栏中添加控件
    QPushButton * btn=new QPushButton("aaa",this);
    toolBar->addWidget(btn);

    //状态栏(最多有一个)
    QStatusBar * stBar=statusBar();
    //设置到窗口中(和窗口绑定)
    setStatusBar(stBar);
    //放标签控件
    QLabel * label=new QLabel("提示信息",this);
    stBar->addWidget(label);
    QLabel * label2=new QLabel("右侧提示",this);
    stBar->addPermanentWidget(label2);

    //铆接部件(浮动窗口)
    QDockWidget * dockWidget=new QDockWidget("浮动",this);
    addDockWidget(Qt::BottomDockWidgetArea,dockWidget);
    QTextEdit * edit=new QTextEdit(this);
    setCentralWidget(edit);
}

MainWindow::~MainWindow()
{
}

