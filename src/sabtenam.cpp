#include "sabtenam.h"
#include "ui_sabtenam.h"
#include <QComboBox>
#include <QDebug>
#include <QFile>
#include <QTextStream>
#include <QString>
#include <QDir>
#include <QMessageBox>
#include <QChar>

Sabtenam::Sabtenam(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Sabtenam)
{
    ui->setupUi(this);
    ui->comboBox->addItem("MALE");
    ui->comboBox->addItem("FEMALE");
}

Sabtenam::~Sabtenam()
{
    delete ui;
}

void Sabtenam::on_pushButton_clicked()
{
    QString username = ui->lineEdit->text();
    QString email = ui->lineEdit_2->text();
    QString password = ui->lineEdit_3->text();
    QString gender = ui->comboBox->currentText();
    //qDebug() << username << " " << email << " " << password << " " << gender ;
    QFile file1("users/number.txt");
    file1.open(QFile::ReadOnly | QFile::Text);
    QTextStream in(&file1);
    int numberofusers ;
    in >> numberofusers;
    file1.flush();file1.close();

    //need to check the info is unique
    for (int i=1;i<=numberofusers;i++){
        QString num = QString::number(i);
        QString pathi = ("users/"+num+"/info.txt");
        QFile filei(pathi);
        filei.open(QFile::ReadOnly | QFile::Text);
        QTextStream streami (&filei);
        QChar ch = ' ';
        QStringList listi = streami.readLine().split(ch);
        if (listi[0] == username){
            QMessageBox::warning(this,"ERROR","Username already taken");
            return ;
        }
        if (listi[2] == email){
            QMessageBox::warning(this,"ERROR","Email already taken");
            return ;
        }
    }
    /*QString path1  = "users/1/info.txt";
    QFile user1(path1);
    user1.open(QFile::ReadOnly | QFile::Text);
    QTextStream streamuser1 (&user1);
    QChar ch = ' ';
    QStringList list  = streamuser1.readLine().split(ch);
    qDebug () << list[0] ;*/

    file1.open(QFile::WriteOnly | QFile::Text);
    QTextStream out(&file1);
    out << numberofusers+1;
    QString userid = QString::number(numberofusers+1);
    QString path = "users/" + userid;
    QDir().mkdir(path);

    QFile friends(path+"/"+"friends.txt");      //Creating Friends text
    friends.open(QFile::WriteOnly | QFile::Text);
    QTextStream outfriends (&friends);
    outfriends << numberofusers + 1;
    friends.flush();friends.close();

    QFile info(path+"/"+"info.txt");        //Creating Info text
    info.open(QFile::WriteOnly | QFile::Text);
    QTextStream outinfo(&info);
    outinfo << username << " " << password << " " << email << " " << gender ;
    info.flush();info.close();

    path = path + "/posts";      //Creating posts folders
    QDir().mkdir(path);
    QDir().mkdir(path + "/public");
    QDir().mkdir(path + "/private");

    QFile publicnumber(path+"/public/"+"number.txt");      //Creating number of public posts text
    publicnumber.open(QFile::WriteOnly | QFile::Text);
    QTextStream public0(&publicnumber);
    public0 << 0;
    publicnumber.flush();publicnumber.close();
    QFile privatenumber(path+"/private/"+"number.txt");        //Creating number of private posts text
    privatenumber.open(QFile::WriteOnly | QFile::Text);
    QTextStream private0(&privatenumber);
    private0 << 0;
    privatenumber.flush();privatenumber.close();

    this->close();
}
