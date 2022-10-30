#include "whattodo.h"
#include "ui_whattodo.h"
#include "settingmenu.h"
#include "addpost.h"
#include "showpost.h"
#include <QFile>
#include <QString>
#include <QTextStream>

WhatToDo::WhatToDo(int id,QWidget *parent) :
    QDialog(parent),
    userid(id),
    ui(new Ui::WhatToDo)
{
    ui->setupUi(this);
    ui->label_2->setText(infoChecker(id,0)+","+infoChecker(id,2));
}

WhatToDo::~WhatToDo()
{
    delete ui;
}

QString WhatToDo::infoChecker(int n, int m)
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

void WhatToDo::on_pushButton_clicked()
{
    SettingMenu setting(userid);
    setting.setModal(true);
    setting.exec();
}

void WhatToDo::on_pushButton_2_clicked()
{
    int x = howUsers();
    for (int i=1;i<=x;i++){
        if (howPosts(i,1) > 0){
            ShowPost showpost(i,userid,1,1);
            showpost.setModal(true);
            showpost.exec();
            break;
        }
        else if (canHeSee(userid,i) && howPosts(i,2) > 0){
            ShowPost showpost(i,userid,1,2);
            showpost.setModal(true);
            showpost.exec();
            break;
        }
    }
}

void WhatToDo::on_pushButton_3_clicked()
{
    AddPost addpost(userid);
    addpost.setModal(true);
    addpost.exec();
}

int WhatToDo::howPosts(int id, int kind) // public (kind = 1) , private (kind = 2)
{
    QString num = QString::number(id);
    QString pk;
    if (kind==1){
        pk = "public";
    }
    else{
        pk = "private";
    }
    QString path = ("users/"+num+"/posts/"+pk+"/number.txt");
    QFile file (path);
    file.open(QFile::ReadOnly | QFile::Text);
    QTextStream in (&file);
    int ans ;
    in >> ans;
    file.flush();file.close();
    return ans;
}

int WhatToDo::howUsers()
{
    QFile file ("users/number.txt");
    file.open(QFile::ReadOnly | QFile::Text);
    QTextStream in (&file);
    int ans;
    in >> ans;
    file.flush();file.close();
    return ans;
}

bool WhatToDo::canHeSee(int viewer, int poster)
{
    QString sviewer = QString::number(viewer);
    QString sposter = QString::number(poster);
    QString path = ("users/"+sposter+"/friends.txt");
    QFile file (path);
    file.open(QFile::ReadOnly | QFile::Text);
    QTextStream in (&file);
    QChar ch = ' ';
    QStringList list = in.readLine().split(ch);
    for (int i=0;i<list.size();i++){
        if (list[i] == viewer){
            return 1;
        }
    }
    file.flush();file.close();
    return 0;
}
