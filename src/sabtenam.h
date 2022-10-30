#ifndef SABTENAM_H
#define SABTENAM_H

#include <QDialog>

namespace Ui {
class Sabtenam;
}

class Sabtenam : public QDialog
{
    Q_OBJECT

public:
    explicit Sabtenam(QWidget *parent = nullptr);
    ~Sabtenam();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Sabtenam *ui;
};

#endif // SABTENAM_H
