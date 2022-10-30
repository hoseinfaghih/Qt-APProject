#include "settingmenu.h"
#include "ui_settingmenu.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QDebug>

SettingMenu::SettingMenu(int id,QWidget *parent) :
    QDialog(parent),
    userid(id),
    ui(new Ui::SettingMenu)
{
    ui->setupUi(this);
    ui->comboBox->addItem("MALE");
    ui->comboBox->addItem("FEMALE");
}

SettingMenu::~SettingMenu()
{
    delete ui;
}

QString SettingMenu::infoChecker(int n, int m)
{
    QString num = QString::number(n);
    QString path = ("users/"+num+"/info.txt");
    QFile file (path);
    file.open(QFile::ReadOnly | QFile::Text);
    QTextStream textstream (&file);
    QChar ch = ' ';
    QStringList listinfo = textstream.readLine().split(ch);
    QString ans = listinfo[m];
    return ans;
}

void SettingMenu::changeValue(int who,int n, QString s)
{
    QString num = QString::number(who);
    QString path = ("users/" + num + "/info.txt");
    QFile filein (path) ;
    filein.open(QFile::ReadOnly | QFile::Text);
    QTextStream streamin(&filein) ;
    QChar ch = ' ';
    QStringList list = streamin.readLine().split(ch);
    filein.flush();filein.close();
    list[n] = s;
    //qDebug() << list[0] << " " << list[1] << " " << list[2] << " " <<list[3];
    QFile fileout (path) ;
    fileout.open(QFile::WriteOnly | QFile::Text);
    QTextStream streamout(&fileout) ;
    streamout << list[0] << " " << list[1] << " " <<list[2] << " " << list[3];
    fileout.flush();fileout.close();
}

int SettingMenu::findUser(QString s)
{
    int numberofusers;
    QFile file ("users/number.txt");
    file.open(QFile::ReadOnly | QFile::Text);
    QTextStream textstream (&file);
    textstream >> numberofusers;
    file.close();
    for (int i=1;i<=numberofusers;i++){
        QString x = infoChecker(i,0);
        if (x == s){
            return i;
        }
    }
    return -1;
}
void SettingMenu::on_pushButton_clicked()
{
    int numberofusers;
    QFile file ("users/number.txt");
    file.open(QFile::ReadOnly | QFile::Text);
    QTextStream textstream (&file);
    textstream >> numberofusers;
    QString username = ui->lineEdit->text();
    bool check = false;
    for (int i=1;i<=numberofusers;i++){
        if (infoChecker(i,0) == username){
            QMessageBox::warning(this,"ERROR","USERNAME ALREADY TAKEN");
            check = true;
            break;
        }
    }
   file.close();
    if (!check){
        changeValue(userid,0,username);
    }
}

void SettingMenu::on_pushButton_2_clicked()
{
    QString password = ui->lineEdit_2->text();
    changeValue(userid,1,password);
}

void SettingMenu::on_pushButton_3_clicked()
{
    QString newgender = ui->comboBox->currentText();
    changeValue(userid,3,newgender);
}

void SettingMenu::on_pushButton_4_clicked()
{
    QString addfriend = ui->lineEdit_3->text();
    int friendid = findUser(addfriend);
    if (friendid == -1){
        QMessageBox::warning(this,"ERROR","THIS USER DOES NOT EXIST");
        return ;
    }
    QString num = QString::number(userid);
    QFile friendfile ("users/"+num+"/friends.txt");
    friendfile.open(QFile::ReadOnly | QFile::Text);
    QTextStream friendtream (&friendfile);
    QChar ch = ' ';
    QStringList friendlist = friendtream.readLine().split(ch);
    friendfile.close();
    for (int i=0;i<friendlist.size();i++){
        int x = friendlist[i].toInt();
        if(x==friendid){
            QMessageBox::warning(this,"ERROR","this user is already in your friendlist");
            return ;
        }
    }
    QString lastString = QString::number(friendid);
    friendlist.append(lastString);
    QFile friendfileout ("users/"+num+"/friends.txt");
    friendfileout.open(QFile::WriteOnly | QFile::Text);
    QTextStream friendout (&friendfileout);
    for (int i=0;i<friendlist.size();i++){
        friendout << friendlist[i] << " ";
    }
    friendfileout.close();
}
void SettingMenu::on_pushButton_5_clicked()
{
    QString removefriend = ui->lineEdit_4->text();
    int friendid = findUser(removefriend);
    if (friendid == -1){
        QMessageBox::warning(this,"ERROR","THIS USER DOES NOT EXIST");
        return ;
    }
    QString num = QString::number(userid);
    QFile friendfile ("users/"+num+"/friends.txt");
    friendfile.open(QFile::ReadOnly | QFile::Text);
    QTextStream friendtream (&friendfile);
    QChar ch = ' ';
    QStringList friendlist = friendtream.readLine().split(ch);
    friendfile.close();
    bool exist = false;
    for (int i=0;i<friendlist.size();i++){
        int x = friendlist[i].toInt();
        if (x == friendid){
            exist = true;
            break;
        }
    }
    if (!exist){
        QMessageBox::warning(this,"ERROR","THIS USER IS NOT IN YOUR FRIEND LIST");
    }
    QFile fileout ("users/"+num+"/friends.txt");
    fileout.open(QFile::WriteOnly | QFile::Text);
    QTextStream streamout (&fileout);
    QString badstring = QString::number(friendid);
    for (int i=0;i<friendlist.size();i++){
        if (friendlist[i] == badstring){
            continue;
        }
        else{
            streamout << friendlist[i] << " ";
        }
    }
    fileout.close();
}
