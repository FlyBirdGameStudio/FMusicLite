#include "Album.h"
#include "ui_Album.h"

Album::Album(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Album)
{
    ui->setupUi(this);
}

Album::~Album()
{
    delete ui;
}
