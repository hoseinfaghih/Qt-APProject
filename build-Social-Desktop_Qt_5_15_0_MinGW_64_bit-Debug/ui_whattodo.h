/********************************************************************************
** Form generated from reading UI file 'whattodo.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WHATTODO_H
#define UI_WHATTODO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_WhatToDo
{
public:
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;

    void setupUi(QDialog *WhatToDo)
    {
        if (WhatToDo->objectName().isEmpty())
            WhatToDo->setObjectName(QString::fromUtf8("WhatToDo"));
        WhatToDo->resize(400, 300);
        verticalLayout_3 = new QVBoxLayout(WhatToDo);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(WhatToDo);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        label_2 = new QLabel(WhatToDo);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton = new QPushButton(WhatToDo);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(WhatToDo);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(WhatToDo);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        horizontalLayout->addWidget(pushButton_3);


        verticalLayout_2->addLayout(horizontalLayout);


        verticalLayout_3->addLayout(verticalLayout_2);


        retranslateUi(WhatToDo);

        QMetaObject::connectSlotsByName(WhatToDo);
    } // setupUi

    void retranslateUi(QDialog *WhatToDo)
    {
        WhatToDo->setWindowTitle(QCoreApplication::translate("WhatToDo", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("WhatToDo", "Hello", nullptr));
        label_2->setText(QCoreApplication::translate("WhatToDo", "<blank>", nullptr));
        pushButton->setText(QCoreApplication::translate("WhatToDo", "Setting", nullptr));
        pushButton_2->setText(QCoreApplication::translate("WhatToDo", "Home", nullptr));
        pushButton_3->setText(QCoreApplication::translate("WhatToDo", "Add Post", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WhatToDo: public Ui_WhatToDo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WHATTODO_H
