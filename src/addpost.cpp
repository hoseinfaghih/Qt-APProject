#include "addpost.h"
#include "ui_addpost.h"
#include <QFile>
#include <QTextStream>
#include <QDir>
#include <QMessageBox>

AddPost::AddPost(int id,QWidget *parent) :
    QDialog(parent),
    userid(id),
    ui(new Ui::AddPost)
{
    ui->setupUi(this);
    ui->radioButton->setChecked(true);
}

AddPost::~AddPost()
{
    delete ui;
}

void AddPost::on_pushButton_clicked()
{
    QString tweet = ui->textEdit->toPlainText();
    if (tweet == ""){
        QMessageBox::warning(this,"ERROR","Tweets is empty!!!");
        return ;
    }
    if (ui->radioButton->isChecked()){
        QString num = QString::number(userid);
        QString path = ("users/"+num+"/posts/public/");
        QFile infile (path+"number.txt");  // reading and changing the number of tweets
        infile.open(QFile::ReadOnly | QFile::Text);
        QTextStream in (&infile);
        int numberoftweets;
        in >> numberoftweets;
        infile.flush();infile.close();
        QFile outfile (path+"number.txt");
        outfile.open(QFile::WriteOnly | QFile::Text);
        QTextStream out (&outfile);
        out << numberoftweets+1;
        outfile.flush();outfile.close();

        // creating post folder
        QString postid = QString::number(numberoftweets+1);
        QDir().mkdir(path + postid);
        QDir().mkdir(path + postid +"/comments");
        QFile tweettext (path + postid + "/tweet.txt");
        tweettext.open(QFile::WriteOnly | QFile::Text);
        QTextStream outtweet (&tweettext);
        outtweet << tweet;
        tweettext.flush();tweettext.close();


        QFile likes (path + postid + "/likes.txt");
        likes.open(QFile::WriteOnly | QFile::Text);
        QTextStream outlikes (&likes);
        likes.flush();likes.close();

        QFile commentsnumber1 (path+postid+"/comments/number.txt");
        commentsnumber1.open(QFile::WriteOnly | QFile::Text);
        QTextStream outcomments (&commentsnumber1);
        outcomments << 0 ;
        commentsnumber1.flush();commentsnumber1.close();
    }
    else if (ui->radioButton_2->isChecked()){
        QString num = QString::number(userid);
        QString path = ("users/"+num+"/posts/private/");
        QFile infile (path+"number.txt");  // reading and changing the number of tweets
        infile.open(QFile::ReadOnly | QFile::Text);
        QTextStream in (&infile);
        int numberoftweets;
        in >> numberoftweets;
        infile.flush();infile.close();
        QFile outfile (path+"number.txt");
        outfile.open(QFile::WriteOnly | QFile::Text);
        QTextStream out (&outfile);
        out << numberoftweets+1;
        outfile.flush();outfile.close();

        // creating post folder
        QString postid = QString::number(numberoftweets+1);
        QDir().mkdir(path + postid);
        QDir().mkdir(path + postid +"/comments");
        QFile tweettext (path + postid + "/tweet.txt");
        tweettext.open(QFile::WriteOnly | QFile::Text);
        QTextStream outtweet (&tweettext);
        outtweet << tweet;
        tweettext.flush();tweettext.close();


        QFile likes (path + postid + "/likes.txt");
        likes.open(QFile::WriteOnly | QFile::Text);
        QTextStream outlikes (&likes);
        likes.flush();likes.close();

        QFile commentsnumber2 (path+postid+"/comments/number.txt");
        commentsnumber2.open(QFile::WriteOnly | QFile::Text);
        QTextStream outcomments (&commentsnumber2);
        outcomments << "0" ;
        commentsnumber2.flush();commentsnumber2.close();
    }
}
