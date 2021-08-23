#ifndef MYLABEL_H
#define MYLABEL_H

#include <QLabel>

class myLabel : public QLabel
{
    Q_OBJECT
public:
    explicit myLabel(QWidget *parent = nullptr);
    //鼠标进入事件
    void enterEvent(QEvent *event);
    //鼠标离开事件
    void leaveEvent(QEvent *event);

    //鼠标按压事件
    void mousePressEvent(QMouseEvent *ev);
    //鼠标释放事件
    void mouseReleaseEvent(QMouseEvent *ev);
    //鼠标移动事件(默认情况下只有按压鼠标的移动才算移动)
    void mouseMoveEvent(QMouseEvent *ev);
signals:

};

#endif // MYLABEL_H
