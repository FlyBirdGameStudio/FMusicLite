#include "MyPage.h"
#include "ui_MyPage.h"

MyPage::MyPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyPage)
{
    ui->setupUi(this);
}

MyPage::~MyPage()
{
    delete ui;
}
