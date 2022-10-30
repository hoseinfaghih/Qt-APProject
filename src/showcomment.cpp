#include "showcomment.h"
#include "ui_showcomment.h"
#include <QFile>
#include <QTextStream>
ShowComment::ShowComment(int id1 , int id2 , int id3 , int id4 , QWidget *parent) :
    QDialog(parent),
    userid(id1) ,
    kindid (id2) ,
    postid (id3) ,
    commentid (id4) ,
    ui(new Ui::ShowComment)
{
    ui->setupUi(this);
    //ui->lineEdit->setText(getUser(user));
    QString s1 = QString::number(id1);
    QString s2 = QString::number(id2);
    QString s3 = QString::number(id3);
    QString s4 = QString::number(id4);
    QString path;
    if (id2 == 1){
        path = ("users/"+s1+"/posts/public/"+s3+"/comments/"+s4+".txt");
    }
    else if (id2 == 2){
        path = ("users/"+s1+"/posts/private/"+s3+"/comments/"+s4+".txt");
    }
    QFile file (path);
    file.open(QFile::ReadOnly | QFile::Text);
    QTextStream stream (&file);
    QString comment;
    stream >> comment;
    ui->textEdit->setText(comment);
}

ShowComment::~ShowComment()
{
    delete ui;
}

QString ShowComment::getUser(int id1)
{
    QString num = QString::number(id1);
    QString path = ("users/"+num+"/info.txt");
    QFile file(path);
    file.open(QFile::ReadOnly | QFile::Text);
    QTextStream in (&file);
    QChar ch = ' ';
    QStringList list  = in.readLine().split(ch);
    file.flush();file.close();
    return list[0];
}



void ShowComment::on_pushButton_clicked()
{
    QString s1 = QString::number(userid);
    QString s2 = QString::number(kindid);
    QString s3 = QString::number(postid);
    QString s4 = QString::number(commentid);
    QString path;
    if (kindid == 1){
        path = ("users/"+s1+"/posts/public/"+s3+"/comments/number.txt");
    }
    else if (kindid == 2){
        path = ("users/"+s1+"/posts/private/"+s3+"/comments/number.txt");
    }
    QFile file(path);
    file.open(QFile::ReadOnly | QFile::Text);
    QTextStream stream (&file);
    int x;
    stream >> x;
    if (commentid < x){
        hide ();
        showcomment = new ShowComment(userid,kindid,postid,commentid+1);
        showcomment->show();
    }
    else if (commentid == x) {
        hide();
        endcomment = new EndComment;
        endcomment->show();
    }
}
