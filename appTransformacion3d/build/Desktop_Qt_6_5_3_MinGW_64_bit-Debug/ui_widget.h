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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QWidget *widget;
    QLCDNumber *lcdNumber;
    QLCDNumber *lcdNumber_2;
    QLabel *label;
    QDial *dial;
    QDial *dial_2;
    QLabel *label_2;
    QSpinBox *spinBox;
    QSpinBox *spinBox_2;
    QSpinBox *spinBox_3;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QCheckBox *checkBox;
    QPushButton *pushButton;

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
        lcdNumber = new QLCDNumber(widget);
        lcdNumber->setObjectName("lcdNumber");
        lcdNumber->setGeometry(QRect(30, 130, 64, 23));
        lcdNumber_2 = new QLCDNumber(widget);
        lcdNumber_2->setObjectName("lcdNumber_2");
        lcdNumber_2->setGeometry(QRect(110, 130, 64, 23));
        label = new QLabel(widget);
        label->setObjectName("label");
        label->setGeometry(QRect(50, 30, 26, 16));
        dial = new QDial(widget);
        dial->setObjectName("dial");
        dial->setGeometry(QRect(30, 60, 59, 56));
        dial->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 127);"));
        dial->setMaximum(360);
        dial->setValue(63);
        dial_2 = new QDial(widget);
        dial_2->setObjectName("dial_2");
        dial_2->setGeometry(QRect(110, 60, 59, 56));
        dial_2->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 0, 0);"));
        dial_2->setMaximum(360);
        dial_2->setValue(30);
        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(140, 30, 17, 16));
        spinBox = new QSpinBox(widget);
        spinBox->setObjectName("spinBox");
        spinBox->setGeometry(QRect(60, 210, 46, 25));
        spinBox->setMaximum(200);
        spinBox->setSingleStep(1);
        spinBox->setValue(150);
        spinBox_2 = new QSpinBox(widget);
        spinBox_2->setObjectName("spinBox_2");
        spinBox_2->setGeometry(QRect(60, 250, 46, 25));
        spinBox_2->setMaximum(200);
        spinBox_2->setValue(100);
        spinBox_3 = new QSpinBox(widget);
        spinBox_3->setObjectName("spinBox_3");
        spinBox_3->setGeometry(QRect(60, 290, 46, 25));
        spinBox_3->setMaximum(200);
        spinBox_3->setValue(50);
        label_3 = new QLabel(widget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(20, 220, 19, 16));
        label_4 = new QLabel(widget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(20, 260, 18, 16));
        label_5 = new QLabel(widget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(20, 300, 18, 16));
        checkBox = new QCheckBox(Widget);
        checkBox->setObjectName("checkBox");
        checkBox->setGeometry(QRect(510, 470, 100, 22));
        pushButton = new QPushButton(Widget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(620, 470, 80, 25));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        label->setText(QCoreApplication::translate("Widget", "AlFA", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "PHI", nullptr));
        label_3->setText(QCoreApplication::translate("Widget", "pfX", nullptr));
        label_4->setText(QCoreApplication::translate("Widget", "pfY", nullptr));
        label_5->setText(QCoreApplication::translate("Widget", "pfZ", nullptr));
        checkBox->setText(QCoreApplication::translate("Widget", "Usar teclado", nullptr));
        pushButton->setText(QCoreApplication::translate("Widget", "reset", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
