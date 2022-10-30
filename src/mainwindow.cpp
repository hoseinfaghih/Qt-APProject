#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sabtenam.h"

#include <QString>
#include <QDebug>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QDir>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
   QString username = ui->lineEdit->text();
   QString password = ui->lineEdit_2->text();
   //Read numberofusers
   QFile filehow("users/number.txt");
   filehow.open(QFile::ReadOnly | QFile::Text);
   QTextStream streamhow (&filehow);
   int numberofusers ;
   streamhow >> numberofusers;
   bool check = false;
   for (int i=1;i<=numberofusers;i++){
       QString num = QString::number(i);
       QString pathi = ("users/"+num+"/info.txt");
       QFile filei (pathi);
       filei.open(QFile::ReadOnly | QFile::Text);
       QChar ch = ' ';
       QTextStream streami (&filei);
       QStringList listi = streami.readLine().split(ch);

       if (listi[0]==username && listi[1]==password){
           check = true;
           hide();
           what = new WhatToDo(i);
           what->show();
       }
   }
   if (!check){
       QMessageBox::warning(this,"ERROR","WE DON'T HAVE THIS USER. PLEASE REGISTER !");
   }
}

void MainWindow::on_pushButton_2_clicked()
{
    Sabtenam reg;
    reg.setModal(true);
    reg.exec();
}
