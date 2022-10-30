/********************************************************************************
** Form generated from reading UI file 'addpost.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDPOST_H
#define UI_ADDPOST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AddPost
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QTextEdit *textEdit;
    QPushButton *pushButton;

    void setupUi(QDialog *AddPost)
    {
        if (AddPost->objectName().isEmpty())
            AddPost->setObjectName(QString::fromUtf8("AddPost"));
        AddPost->resize(400, 300);
        verticalLayout_2 = new QVBoxLayout(AddPost);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        radioButton = new QRadioButton(AddPost);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));

        horizontalLayout->addWidget(radioButton);

        radioButton_2 = new QRadioButton(AddPost);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));

        horizontalLayout->addWidget(radioButton_2);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(AddPost);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        textEdit = new QTextEdit(AddPost);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        horizontalLayout_2->addWidget(textEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        pushButton = new QPushButton(AddPost);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout->addWidget(pushButton);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(AddPost);

        QMetaObject::connectSlotsByName(AddPost);
    } // setupUi

    void retranslateUi(QDialog *AddPost)
    {
        AddPost->setWindowTitle(QCoreApplication::translate("AddPost", "Dialog", nullptr));
        radioButton->setText(QCoreApplication::translate("AddPost", "Public", nullptr));
        radioButton_2->setText(QCoreApplication::translate("AddPost", "Private", nullptr));
        label->setText(QCoreApplication::translate("AddPost", "Message :", nullptr));
        pushButton->setText(QCoreApplication::translate("AddPost", "TWEET !", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddPost: public Ui_AddPost {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDPOST_H
