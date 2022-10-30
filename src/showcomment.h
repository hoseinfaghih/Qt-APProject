#ifndef SHOWCOMMENT_H
#define SHOWCOMMENT_H

#include <QDialog>
#include "endcomment.h"
namespace Ui {
class ShowComment;
}

class ShowComment : public QDialog
{
    Q_OBJECT

public:
    explicit ShowComment(int id1 , int id2 ,int id3 , int id4 ,QWidget *parent = nullptr);
    ~ShowComment();

private slots:
    void on_pushButton_clicked();

private:
    Ui::ShowComment *ui;
    int userid , kindid , postid, commentid ;
    QString getUser(int id1);
    EndComment *endcomment;
    ShowComment *showcomment;
};

#endif // SHOWCOMMENT_H
