#ifndef ADDPOST_H
#define ADDPOST_H

#include <QDialog>

namespace Ui {
class AddPost;
}

class AddPost : public QDialog
{
    Q_OBJECT

public:
    explicit AddPost(int id,QWidget *parent = nullptr);
    ~AddPost();

private slots:
    void on_pushButton_clicked();

private:
    int userid;
    Ui::AddPost *ui;
};

#endif // ADDPOST_H
