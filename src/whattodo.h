#ifndef WHATTODO_H
#define WHATTODO_H

#include <QDialog>

namespace Ui {
class WhatToDo;
}

class WhatToDo : public QDialog
{
    Q_OBJECT

public:
    explicit WhatToDo(int id,QWidget *parent = nullptr);
    ~WhatToDo();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    int howPosts (int id,int kind);
    int howUsers ();
    bool canHeSee (int viewer,int poster);
    QString infoChecker(int n,int m);
    int userid;
    Ui::WhatToDo *ui;
};

#endif // WHATTODO_H
