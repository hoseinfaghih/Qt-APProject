#include "endcomment.h"
#include "ui_endcomment.h"

EndComment::EndComment(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EndComment)
{
    ui->setupUi(this);
}

EndComment::~EndComment()
{
    delete ui;
}
