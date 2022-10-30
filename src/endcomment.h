#ifndef ENDCOMMENT_H
#define ENDCOMMENT_H

#include <QDialog>

namespace Ui {
class EndComment;
}

class EndComment : public QDialog
{
    Q_OBJECT

public:
    explicit EndComment(QWidget *parent = nullptr);
    ~EndComment();

private:
    Ui::EndComment *ui;
};

#endif // ENDCOMMENT_H
