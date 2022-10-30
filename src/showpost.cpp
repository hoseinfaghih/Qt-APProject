#include "showpost.h"
#include "ui_showpost.h"

#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QDir>

ShowPost::ShowPost(int id1,int id2,int id3,int id4,QWidget *parent) :
    QDialog(parent),
    senderid(id1),
    recieverid (id2) ,
    postid (id3) ,
    kindid (id4) ,
    ui(new Ui::ShowPost)
{
    ui->setupUi(this);
    ui->lineEdit->setText(getUser(id1));
    ui->textEdit->setText(getPost(id1,id4,id3));
    int x = likecount(id1,id4,id3);
    QString sx = QString::number(x/2);
    ui->label_3->setText("Likes : " + sx);
}

ShowPost::~ShowPost()
{
    delete ui;
}

int ShowPost::howPosts(int id, int kind)
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

int ShowPost::howUsers()
{
    QFile file ("users/number.txt");
    file.open(QFile::ReadOnly | QFile::Text);
    QTextStream in (&file);
    int ans;
    in >> ans;
    file.flush();file.close();
    return ans;
}

bool ShowPost::canHeSee(int viewer, int poster)
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

QString ShowPost::getPost(int id1, int id2, int id3) //id1 = userid , id2 = kind of post , id3 = postid
{
    QString num1 = QString::number(id1);
    QString num3 = QString::number(id3);
    QString path ;
    if (id2 == 1){
        path = ("users/"+num1+"/posts/public/"+num3+"/tweet.txt");
    }
    if (id2 == 2){
        path = ("users/"+num1+"/posts/private/"+num3+"/tweet.txt");
    }
    QFile file(path);
    file.open(QFile::ReadOnly | QFile::Text);
    QTextStream in (&file);
    QString tweet;
    in >> tweet;
    file.flush();file.close();
    return tweet;
}

QString ShowPost::getUser(int id1)
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

int ShowPost::likecount(int id1, int id2, int id3)
{
    QString num1 = QString::number(id1);
    QString num3 = QString::number(id3);
    QString path ;
    if (id2 == 1){
        path = ("users/"+num1+"/posts/public/"+num3+"/likes.txt");
    }
    if (id2 == 2){
        path = ("users/"+num1+"/posts/private/"+num3+"/likes.txt");
    }
    QFile file(path);
    file.open(QFile::ReadOnly | QFile::Text);
    QTextStream in (&file);
    QChar ch = ' ';
    QStringList list = in.readLine().split(ch);
    file.flush();file.close();
    return list.size();
}

void ShowPost::on_pushButton_3_clicked()
{
    bool flag = false;
    for (int i = 1;i<=howUsers();i++){
        for (int j = 1 ; j <= 2; j++){
            for (int k = 1 ; k <= howPosts(i,j);k++){
                if ((j==1) && ((i > senderid) || (i == senderid && j > kindid) || (i == senderid && j == kindid && k > postid))){
                    flag = true;
                    hide();
                    nextwindow = new ShowPost(i,recieverid,k,j);
                    nextwindow->show();
                    return;
                }
                else if (((j==2) && (canHeSee(recieverid,i))) && ((i > senderid) || (i == senderid && j > kindid) || (i == senderid && j == kindid && k > postid))){
                    flag =  true;
                    hide();
                    nextwindow = new ShowPost(i,recieverid,k,j);
                    nextwindow->show();
                    return;
                }
            }
        }
    }
    if (!flag){
        hide();
        endpost = new EndPost;
        endpost->show();
    }

}

void ShowPost::on_pushButton_4_clicked() //show comments
{
    QString userid = QString::number(senderid);
    QString pid = QString::number(postid);
    QString path;
    if (kindid == 1){
        path = ("users/"+userid+"/posts/public/"+pid+"/comments/number.txt");
    }
    else if (kindid == 2){
        path = ("users/"+userid+"/posts/private/"+pid+"/comments/number.txt");
    }
    QFile file(path);
    file.open(QFile::ReadOnly | QFile::Text);
    QTextStream stream (&file);
    int x;
    stream >> x;
    file.flush();file.close();
    QFile outfile(path);
    outfile.open(QFile::WriteOnly | QFile::Text);
    QTextStream outstream (&outfile);
    outstream << x+1;
    outfile.flush();outfile.close();
    if (x == 0){
        QMessageBox::warning(this,"ERROR","THERE IS NO COMMENT FOR THIS POST");
        return ;
    }
    showcomment = new ShowComment(senderid,kindid,postid,1);
    showcomment->show();
}

void ShowPost::on_pushButton_clicked() // like
{
    QString userid = QString::number(senderid);
    QString pid = QString::number(postid);
    QString path;
    if (kindid == 1){
        path = ("users/"+userid+"/posts/public/"+pid+"/likes.txt");
    }
    else if (kindid == 2){
        path = ("users/"+userid+"/posts/private/"+pid+"/likes.txt");
    }
    QFile file (path);
    file.open(QFile::ReadOnly | QFile::Text);
    QTextStream stream(&file);
    QChar ch = ' ';
    QStringList list = stream.readLine().split(ch);
    file.flush();file.close();
    bool flag = true;
    for (int i=0;i<list.size();i++){
        int x = list[i].toInt();
        if (x==recieverid){
            flag = false;
            QMessageBox::warning(this,"ERROR","YOU LIKED THIS POST BEFORE");
            break;
        }
    }
    if (flag){
        QString s = QString::number (recieverid);
        list.append(s);
        QFile outfile(path);
        outfile.open(QFile::WriteOnly | QFile::Text);
        QTextStream outstream (&outfile);
        for (int i=0;i<list.size();i++){
            outstream << list[i] << " ";
        }
        outfile.flush();outfile.close();
    }
}

void ShowPost::on_pushButton_2_clicked() //comment
{
    QString newcomment = ui->textEdit_2->toPlainText();
    QString userid = QString::number(senderid);
    QString pid = QString::number(postid);
    QString path;
    if (kindid == 1){
        path = ("users/"+userid+"/posts/public/"+pid+"/comments/number.txt");
    }
    else if (kindid == 2){
        path = ("users/"+userid+"/posts/private/"+pid+"/comments/number.txt");
    }
    QFile file(path);
    file.open(QFile::ReadOnly | QFile::Text);
    QTextStream stream (&file);
    int x;
    stream >> x;
    file.flush();file.close();
    x++;
    QString sx = QString::number(x);
    path = ("users/"+userid+"/posts/public/"+pid+"/comments/"+sx+".txt");
    QFile outfile (path);
    outfile.open(QFile::WriteOnly | QFile::Text);
    QTextStream outstream(&outfile);
    outstream << newcomment;
    outfile.flush();outfile.close();

}
