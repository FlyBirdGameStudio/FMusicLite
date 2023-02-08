#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <QFile>

#include "Models/NotificationTool.h"

#include "UIControllers/HomePage.h"
#include "UIControllers/SearchDisplay.h"
#include "UIControllers/PlayListPage.h"
#include "UIControllers/MyPage.h"

#include "NetWork/Actions/PlayMusicAction.h"

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
    , Controller(nullptr)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    /* SetUp Media Player */
    Player.reset(new MusicPlayer(ui->horizontalSlider));
    Player->BindInfoLabel(ui->TitleText);
    connect(Player.get(), &MusicPlayer::OnMusicPlayerStateChange, this, &MainWindow::OnMusicPlayerStateChange);

    /* Set Home Page */
    SetPage(new HomePage(this));

    /* OnFill Icon Font */

    ui->playbutton->setText(QChar(0xe768));
    ui->periousmusic->setText(QChar(0xe892));
    ui->nextmusic->setText(QChar(0xe893));
    ui->othermenu->setText(QChar(0xe712));

    /* OnRead Tab Bar Button Style Sheet */
    QFile file(":/Texts/TabStyle.qss");
    if(!file.open(QFile::ReadOnly))
        qDebug() << "Open Read TabStyle Sheet Error";

    tab_styles = QString::fromUtf8(file.readAll()).split("#off_style");
    file.close();

}

MainWindow::~MainWindow()
{
    NotificationTool::UninstallIcon();
    delete ui;
}

void MainWindow::PlayMusic(const QString &id)
{
    auto action = new PlayMusicAction(this, id);
    action->BeginTask();
}

void MainWindow::GetShowerSize(int &x, int &y)
{
    x = ui->shower->width();
    y = ui->shower->height();
}

void MainWindow::SetPage(QWidget *widget)
{
    foreach(auto a, ui->shower->findChildren<QWidget *>())
    {
        a->hide();
        a->deleteLater();
    }

    widget->setParent(this->ui->shower);
    widget->show();
    widget->resize(this->width(), this->height());
}

void MainWindow::DealSwitchPage()
{
    ui->me->setStyleSheet(tab_styles[1]);
    ui->home->setStyleSheet(tab_styles[1]);
    ui->playlist->setStyleSheet(tab_styles[1]);
}

/* Switch To User Info Page */
void MainWindow::on_me_clicked()
{
    DealSwitchPage();
    ui->me->setStyleSheet(tab_styles[0]);
    SetPage(new MyPage());
}

/* Switch To User Player List Page */
void MainWindow::on_playlist_clicked()
{
    DealSwitchPage();
    ui->playlist->setStyleSheet(tab_styles[0]);
    SetPage(new PlayListPage());
}

/* Switch To Home Page */
void MainWindow::on_home_clicked()
{
    DealSwitchPage();
    ui->home->setStyleSheet(tab_styles[0]);
    SetPage(new HomePage(this));
}

/* On Resize Page Container */
void MainWindow::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED(event)

    auto page = ui->shower->children();
    if(page.count() == 1)
        return;

    auto a = qobject_cast<QWidget*>(page.at(1));
    if(!a->isVisible())
        return;
    a->resize(this->width(), this->height());
}

void MainWindow::dropEvent(QDropEvent *event)
{
    Q_UNUSED(event)
    //Deal File Drag In Play
}

void MainWindow::on_searchBox_returnPressed()
{
    SetPage(new SearchDisplay(ui->searchBox->text(), this));
}

void MainWindow::OnMusicPlayerStateChange(const PlayerState &state)
{
    switch (state)
    {
    case PlayerState::OnPause:
        ui->playbutton->setText(QChar(0xe768));
        break;
    case PlayerState::OnPlaying:
        ui->playbutton->setText(QChar(0xe769));
        break;
    case PlayerState::OnStopped:
        break;
    }
}
