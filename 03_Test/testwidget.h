#ifndef TESTWIDGET_H
#define TESTWIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class TestWidget; }
QT_END_NAMESPACE

class TestWidget : public QWidget
{
    Q_OBJECT

public:
    TestWidget(QWidget *parent = nullptr);
    ~TestWidget();
    void NewWidget();
private:
    Ui::TestWidget *ui;
};
#endif // TESTWIDGET_H
