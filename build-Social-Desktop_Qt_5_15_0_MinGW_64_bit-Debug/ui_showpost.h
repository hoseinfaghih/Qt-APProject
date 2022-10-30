/********************************************************************************
** Form generated from reading UI file 'showpost.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOWPOST_H
#define UI_SHOWPOST_H

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

class Ui_ShowPost
{
public:
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QTextEdit *textEdit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QPushButton *pushButton;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QTextEdit *textEdit_2;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_2;
    QPushButton *pushButton_4;
    QPushButton *pushButton_3;

    void setupUi(QDialog *ShowPost)
    {
        if (ShowPost->objectName().isEmpty())
            ShowPost->setObjectName(QString::fromUtf8("ShowPost"));
        ShowPost->resize(415, 290);
        verticalLayout_3 = new QVBoxLayout(ShowPost);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(ShowPost);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(ShowPost);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout->addWidget(lineEdit);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(ShowPost);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        textEdit = new QTextEdit(ShowPost);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        horizontalLayout_2->addWidget(textEdit);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(ShowPost);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        pushButton = new QPushButton(ShowPost);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout_3->addWidget(pushButton);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_4 = new QLabel(ShowPost);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_4->addWidget(label_4);

        textEdit_2 = new QTextEdit(ShowPost);
        textEdit_2->setObjectName(QString::fromUtf8("textEdit_2"));

        horizontalLayout_4->addWidget(textEdit_2);


        verticalLayout_2->addLayout(horizontalLayout_4);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        pushButton_2 = new QPushButton(ShowPost);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        verticalLayout->addWidget(pushButton_2);

        pushButton_4 = new QPushButton(ShowPost);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        verticalLayout->addWidget(pushButton_4);


        verticalLayout_2->addLayout(verticalLayout);


        horizontalLayout_5->addLayout(verticalLayout_2);

        pushButton_3 = new QPushButton(ShowPost);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        horizontalLayout_5->addWidget(pushButton_3);


        verticalLayout_3->addLayout(horizontalLayout_5);


        retranslateUi(ShowPost);

        QMetaObject::connectSlotsByName(ShowPost);
    } // setupUi

    void retranslateUi(QDialog *ShowPost)
    {
        ShowPost->setWindowTitle(QCoreApplication::translate("ShowPost", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("ShowPost", "User :", nullptr));
        label_2->setText(QCoreApplication::translate("ShowPost", "Tweet :", nullptr));
        label_3->setText(QCoreApplication::translate("ShowPost", "<blank>", nullptr));
        pushButton->setText(QCoreApplication::translate("ShowPost", "Like!", nullptr));
        label_4->setText(QCoreApplication::translate("ShowPost", "Comment :", nullptr));
        pushButton_2->setText(QCoreApplication::translate("ShowPost", "Comment !", nullptr));
        pushButton_4->setText(QCoreApplication::translate("ShowPost", "Show Comments", nullptr));
        pushButton_3->setText(QCoreApplication::translate("ShowPost", "NEXT !", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ShowPost: public Ui_ShowPost {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOWPOST_H
