#ifndef SHOWPOST_H
#define SHOWPOST_H

#include <QDialog>
#include "endpost.h"
#include "showcomment.h"
namespace Ui {
class ShowPost;
}

class ShowPost : public QDialog
{
    Q_OBJECT

public:
    explicit ShowPost(int id1,int id2,int id3,int id4 ,QWidget *parent = nullptr);
    ~ShowPost();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    int howPosts (int id,int kind);
    int howUsers ();
    bool canHeSee (int viewer,int poster);
    QString getPost (int id1,int id2,int id3); //id1 = user , id2 = kind of post , id3 = postid
    QString getUser(int id1);//user id
    int likecount (int id1,int id2 , int id3); //id1 = user , id2 = kind of post , id3 = postid
    int senderid , recieverid, postid ,kindid;
    EndPost *endpost;
    ShowPost *nextwindow;
    ShowComment *showcomment;
    Ui::ShowPost *ui;
};

#endif // SHOWPOST_H
