/********************************************************************************
** Form generated from reading UI file 'showcomment.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOWCOMMENT_H
#define UI_SHOWCOMMENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ShowComment
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QTextEdit *textEdit;
    QPushButton *pushButton;

    void setupUi(QDialog *ShowComment)
    {
        if (ShowComment->objectName().isEmpty())
            ShowComment->setObjectName(QString::fromUtf8("ShowComment"));
        ShowComment->resize(400, 300);
        verticalLayout_2 = new QVBoxLayout(ShowComment);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(ShowComment);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(ShowComment);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout->addWidget(lineEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(ShowComment);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        textEdit = new QTextEdit(ShowComment);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        horizontalLayout_2->addWidget(textEdit);


        verticalLayout->addLayout(horizontalLayout_2);


        horizontalLayout_3->addLayout(verticalLayout);

        pushButton = new QPushButton(ShowComment);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout_3->addWidget(pushButton);


        verticalLayout_2->addLayout(horizontalLayout_3);


        retranslateUi(ShowComment);

        QMetaObject::connectSlotsByName(ShowComment);
    } // setupUi

    void retranslateUi(QDialog *ShowComment)
    {
        ShowComment->setWindowTitle(QCoreApplication::translate("ShowComment", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("ShowComment", "User :", nullptr));
        label_2->setText(QCoreApplication::translate("ShowComment", "Comment :", nullptr));
        pushButton->setText(QCoreApplication::translate("ShowComment", "NEXT", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ShowComment: public Ui_ShowComment {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOWCOMMENT_H
