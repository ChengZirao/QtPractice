#include "smallwidget.h"
#include "ui_smallwidget.h"

smallWidget::smallWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::smallWidget)
{
    ui->setupUi(this);
    //QSpinBox移动，QSliderBox跟着移动
    //因SpinBox类的valueChanged函数有int参数类型和QString参数类型，发生二义性，故用函数指针接收
    void(QSpinBox::* spSignal)(int)=&QSpinBox::valueChanged;
    //槽函数可以不用写函数指针！！！
    //void(QSlider::* slSlot)(int)=&QSlider::setValue;
    connect(ui->spinBox,spSignal,ui->horizontalSlider,&QSlider::setValue);

    //QSliderBox移动，QSpinBox跟着移动
    //Slider类的valueChanged函数只有唯一的一个，故无需使用函数指针！！！
    void(QSlider::* slSignal)(int)=&QSlider::valueChanged;
    connect(ui->horizontalSlider,&QSlider::valueChanged,ui->spinBox,&QSpinBox::setValue);
}
//设置值
void smallWidget::setNum(int value)
{
    ui->spinBox->setValue(value);
}
//获取值
int smallWidget::getNum()
{
    return ui->spinBox->value();
}


smallWidget::~smallWidget()
{
    delete ui;
}
