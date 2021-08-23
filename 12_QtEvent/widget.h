#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    //重写定时器timerEvent函数
    void timerEvent(QTimerEvent *);
private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
