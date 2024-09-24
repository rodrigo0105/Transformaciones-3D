/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDial>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QWidget *widget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QDial *dial;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QDial *dial_2;
    QLCDNumber *lcdNumber;
    QLCDNumber *lcdNumber_2;
    QCheckBox *checkBox;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(700, 500);
        widget = new QWidget(Widget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(500, 0, 200, 450));
        widget->setAutoFillBackground(false);
        widget->setStyleSheet(QString::fromUtf8("background-color: rgb(121, 121, 121);"));
        layoutWidget = new QWidget(widget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(30, 30, 61, 81));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        dial = new QDial(layoutWidget);
        dial->setObjectName("dial");
        dial->setMaximum(360);
        dial->setValue(63);

        verticalLayout->addWidget(dial);

        layoutWidget1 = new QWidget(widget);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(110, 30, 61, 81));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName("label_2");

        verticalLayout_2->addWidget(label_2);

        dial_2 = new QDial(layoutWidget1);
        dial_2->setObjectName("dial_2");
        dial_2->setMaximum(360);
        dial_2->setValue(45);

        verticalLayout_2->addWidget(dial_2);

        lcdNumber = new QLCDNumber(widget);
        lcdNumber->setObjectName("lcdNumber");
        lcdNumber->setGeometry(QRect(30, 130, 64, 23));
        lcdNumber_2 = new QLCDNumber(widget);
        lcdNumber_2->setObjectName("lcdNumber_2");
        lcdNumber_2->setGeometry(QRect(110, 130, 64, 23));
        checkBox = new QCheckBox(Widget);
        checkBox->setObjectName("checkBox");
        checkBox->setGeometry(QRect(510, 470, 100, 22));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        label->setText(QCoreApplication::translate("Widget", "AlFA", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "phi", nullptr));
        checkBox->setText(QCoreApplication::translate("Widget", "Usar teclado", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
