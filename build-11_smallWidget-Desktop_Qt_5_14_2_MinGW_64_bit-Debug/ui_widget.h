/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include <smallwidget.h>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    smallWidget *xiaowidget;
    QPushButton *btn_Get;
    QPushButton *btn_Set;
    smallWidget *widget;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(800, 600);
        xiaowidget = new smallWidget(Widget);
        xiaowidget->setObjectName(QString::fromUtf8("xiaowidget"));
        xiaowidget->setGeometry(QRect(79, 150, 341, 80));
        btn_Get = new QPushButton(Widget);
        btn_Get->setObjectName(QString::fromUtf8("btn_Get"));
        btn_Get->setGeometry(QRect(510, 160, 150, 46));
        btn_Set = new QPushButton(Widget);
        btn_Set->setObjectName(QString::fromUtf8("btn_Set"));
        btn_Set->setGeometry(QRect(510, 240, 150, 46));
        widget = new smallWidget(Widget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(210, 450, 351, 80));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        btn_Get->setText(QCoreApplication::translate("Widget", "\350\216\267\345\217\226\345\200\274", nullptr));
        btn_Set->setText(QCoreApplication::translate("Widget", "\350\256\276\347\275\256\345\200\274", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
