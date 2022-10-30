#include "endpost.h"
#include "ui_endpost.h"

EndPost::EndPost(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EndPost)
{
    ui->setupUi(this);
}

EndPost::~EndPost()
{
    delete ui;
}
