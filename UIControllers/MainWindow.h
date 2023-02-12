#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QFile>
#include <iostream>

#include "Models/MultiPageController.h"
#include "Models/MusicPlayer.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void PlayMusic(const QString& id);
    void GetShowerSize(int& x, int& y);
    void SetPage(QWidget* widget);

private:
    void DealSwitchPage();

private slots:
    void on_me_clicked();
    void on_playlist_clicked();
    void on_home_clicked();
    void on_searchBox_returnPressed();

    void OnMusicPlayerStateChange(const PlayerState& state);

    void on_playbutton_clicked();

    void on_periousmusic_clicked();

    void on_nextmusic_clicked();

public:
    std::shared_ptr<MusicPlayer> Player;
    QStringList tab_styles;

private:
    int SelectedID = 0;
    MultiPageController Controller;
    Ui::MainWindow *ui;

    // QWidget interface
protected:
    void resizeEvent(QResizeEvent *event) override;
    void dropEvent(QDropEvent *event) override;
};
#endif // MAINWINDOW_H
