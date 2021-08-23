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
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QPushButton *pushButton;
    QToolButton *toolButton;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QRadioButton *radioButton;
    QVBoxLayout *verticalLayout_3;
    QRadioButton *radioButton_3;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QRadioButton *rbtnMan;
    QRadioButton *radioButton_2;
    QListWidget *listWidget;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(700, 450);
        pushButton = new QPushButton(Widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(44, 307, 80, 24));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/ProfilePhoto.JPG"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon);
        toolButton = new QToolButton(Widget);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setGeometry(QRect(130, 300, 112, 39));
        QFont font;
        font.setFamily(QString::fromUtf8("Agency FB"));
        font.setPointSize(16);
        toolButton->setFont(font);
        toolButton->setIcon(icon);
        toolButton->setIconSize(QSize(32, 32));
        toolButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        groupBox_3 = new QGroupBox(Widget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(35, 9, 371, 281));
        gridLayout = new QGridLayout(groupBox_3);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox_2 = new QGroupBox(groupBox_3);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy);
        groupBox_2->setMinimumSize(QSize(100, 100));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        radioButton = new QRadioButton(groupBox_2);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));

        gridLayout_2->addWidget(radioButton, 0, 0, 1, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        radioButton_3 = new QRadioButton(groupBox_2);
        radioButton_3->setObjectName(QString::fromUtf8("radioButton_3"));

        verticalLayout_3->addWidget(radioButton_3);


        gridLayout_2->addLayout(verticalLayout_3, 1, 0, 1, 1);


        gridLayout->addWidget(groupBox_2, 0, 0, 1, 1);

        groupBox = new QGroupBox(groupBox_3);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, -1, -1, -1);
        rbtnMan = new QRadioButton(groupBox);
        rbtnMan->setObjectName(QString::fromUtf8("rbtnMan"));

        verticalLayout->addWidget(rbtnMan);

        radioButton_2 = new QRadioButton(groupBox);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));

        verticalLayout->addWidget(radioButton_2);


        verticalLayout_2->addLayout(verticalLayout);


        gridLayout->addWidget(groupBox, 0, 1, 1, 1);

        listWidget = new QListWidget(Widget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(412, 9, 256, 192));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        pushButton->setText(QCoreApplication::translate("Widget", "\347\231\273\345\275\225", nullptr));
        toolButton->setText(QCoreApplication::translate("Widget", "Route 66", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("Widget", "GroupBox", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("Widget", "\345\251\232\345\220\246", nullptr));
        radioButton->setText(QCoreApplication::translate("Widget", "\345\267\262\345\251\232", nullptr));
        radioButton_3->setText(QCoreApplication::translate("Widget", "\346\234\252\345\251\232", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Widget", "\346\200\247\345\210\253", nullptr));
        rbtnMan->setText(QCoreApplication::translate("Widget", "\347\224\267", nullptr));
        radioButton_2->setText(QCoreApplication::translate("Widget", "\345\245\263", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
