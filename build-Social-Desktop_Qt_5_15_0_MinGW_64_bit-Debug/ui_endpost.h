/********************************************************************************
** Form generated from reading UI file 'endpost.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENDPOST_H
#define UI_ENDPOST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_EndPost
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QDialog *EndPost)
    {
        if (EndPost->objectName().isEmpty())
            EndPost->setObjectName(QString::fromUtf8("EndPost"));
        EndPost->resize(400, 300);
        verticalLayout_2 = new QVBoxLayout(EndPost);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(EndPost);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        label_2 = new QLabel(EndPost);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_2);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(EndPost);

        QMetaObject::connectSlotsByName(EndPost);
    } // setupUi

    void retranslateUi(QDialog *EndPost)
    {
        EndPost->setWindowTitle(QCoreApplication::translate("EndPost", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("EndPost", "You saw all the posts!", nullptr));
        label_2->setText(QCoreApplication::translate("EndPost", "Please close the window", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EndPost: public Ui_EndPost {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENDPOST_H
