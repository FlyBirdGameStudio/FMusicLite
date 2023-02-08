#include "PlayListPage.h"
#include "ui_PlayListPage.h"

PlayListPage::PlayListPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PlayListPage)
{
    ui->setupUi(this);
}

PlayListPage::~PlayListPage()
{
    delete ui;
}
