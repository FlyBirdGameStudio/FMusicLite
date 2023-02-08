#include "SearchDisplay.h"
#include "ui_SearchDisplay.h"

#include "Models/NotificationTool.h"

#include "NetWork/Actions/SearchMusicAction.h"

SearchDisplay::SearchDisplay(const QString& text, MainWindow* window, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SearchDisplay)
{
    auto action = new SearchMusicAction(text, this);
    action->BeginTask();

    this->window = window;

    ui->setupUi(this);

    ui->PlayMusic->setText(QChar(0xe768));
    ui->AddToPlayList->setText(QChar(0xecc8));
    ui->AddToAlbum->setText(QChar(0xe93c));
}

SearchDisplay::~SearchDisplay()
{
    results.clear();
    delete ui;
}

void SearchDisplay::DisplayResult(const QList<SearchResult> results)
{
    this->results = results;
    foreach (auto item, results)
        ui->resultDisplay->addItem(item.Title.append(" ").append(item.Authors));
}

void SearchDisplay::on_PlayMusic_clicked()
{
    int row = ui->resultDisplay->currentRow();
    auto id = results[row].ID;
    window->PlayMusic(id);
    NotificationTool::SendMsg("Begin Play Music", id);
}
