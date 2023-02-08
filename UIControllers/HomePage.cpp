#include "HomePage.h"
#include "ui_HomePage.h"

#include <QDebug>

HomePage::HomePage(MainWindow* window, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HomePage)
{
    ui->setupUi(this);
    this->window = window;
}

HomePage::~HomePage()
{
    delete ui;
}

void HomePage::on_play_button_clicked()
{
    qDebug() << ui->id_edit->text();
    window->PlayMusic(ui->id_edit->text());
}
