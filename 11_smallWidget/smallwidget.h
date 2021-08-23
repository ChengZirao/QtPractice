#ifndef SMALLWIDGET_H
#define SMALLWIDGET_H

#include <QWidget>

namespace Ui {
class smallWidget;
}

class smallWidget : public QWidget
{
    Q_OBJECT

public:
    explicit smallWidget(QWidget *parent = nullptr);
    ~smallWidget();
    //设置值
    void setNum(int);
    //获取值
    int getNum();
private:
    Ui::smallWidget *ui;
};

#endif // SMALLWIDGET_H
