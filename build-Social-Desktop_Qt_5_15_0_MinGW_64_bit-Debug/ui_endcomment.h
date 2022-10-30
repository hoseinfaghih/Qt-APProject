/********************************************************************************
** Form generated from reading UI file 'endcomment.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENDCOMMENT_H
#define UI_ENDCOMMENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_EndComment
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QDialog *EndComment)
    {
        if (EndComment->objectName().isEmpty())
            EndComment->setObjectName(QString::fromUtf8("EndComment"));
        EndComment->resize(400, 300);
        verticalLayout_2 = new QVBoxLayout(EndComment);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(EndComment);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        label_2 = new QLabel(EndComment);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_2);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(EndComment);

        QMetaObject::connectSlotsByName(EndComment);
    } // setupUi

    void retranslateUi(QDialog *EndComment)
    {
        EndComment->setWindowTitle(QCoreApplication::translate("EndComment", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("EndComment", "You saw all the comments.", nullptr));
        label_2->setText(QCoreApplication::translate("EndComment", "please close the window.", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EndComment: public Ui_EndComment {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENDCOMMENT_H
