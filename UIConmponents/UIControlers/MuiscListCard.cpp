#include "UIConmponents/UIControlers/MuiscListCard.h"
#include "ui_MuiscListCard.h"

MuiscListCard::MuiscListCard(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MuiscListCard)
{
    ui->setupUi(this);
}

MuiscListCard::~MuiscListCard()
{
    delete ui;
}
