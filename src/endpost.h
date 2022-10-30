#ifndef ENDPOST_H
#define ENDPOST_H

#include <QDialog>

namespace Ui {
class EndPost;
}

class EndPost : public QDialog
{
    Q_OBJECT

public:
    explicit EndPost(QWidget *parent = nullptr);
    ~EndPost();

private:
    Ui::EndPost *ui;
};

#endif // ENDPOST_H
