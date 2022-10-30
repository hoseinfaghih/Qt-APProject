#ifndef SETTINGMENU_H
#define SETTINGMENU_H

#include <QDialog>

namespace Ui {
class SettingMenu;
}

class SettingMenu : public QDialog
{
    Q_OBJECT

public:
    explicit SettingMenu(int id,QWidget *parent = nullptr);
    ~SettingMenu();


private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

private:
    QString infoChecker(int n , int m);
    void changeValue (int who,int n,QString s);
    int userid;
    int findUser(QString s);
    Ui::SettingMenu *ui;
};

#endif // SETTINGMENU_H
