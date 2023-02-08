#include "MusicPlayer.h"

#include <QDebug>

MusicPlayer::MusicPlayer(QSlider* slider, QObject *parent)
    : QObject(parent)
{
    timer.reset(new QTimer(this));
    connect(timer.get(), SIGNAL(timeout()), this, SLOT(on_timer_count()));

    this->slider.reset(slider);
    slider->setRange(0, 1000);
    connect(slider, SIGNAL(sliderPressed()), this , SLOT(on_slider_progress_sliderPressed()));
    connect(slider, SIGNAL(sliderReleased()), this, SLOT(on_slider_progress_sliderReleased()));

    Player.reset(new QMediaPlayer());
    Player->setVolume(30);
    connect(Player.get(), &QMediaPlayer::mediaStatusChanged, this, &MusicPlayer::mediaStatusChanged);
}

void MusicPlayer::BindInfoLabel(QLabel *label, QLabel *image)
{
    Q_UNUSED(image);
    Title.reset(label);
}

void MusicPlayer::Play()
{
    OnMusicPlayerStateChange(PlayerState::OnPlaying);
    Player->play();
    timer->start(1000);
}

void MusicPlayer::Pause()
{
    OnMusicPlayerStateChange(PlayerState::OnPause);
    Player->pause();
    timer->stop();
}

/* Music Switch Function */
void MusicPlayer::Next()
{
    Pause();

    PlayerIndex++;
    if(PlayerIndex >= PlayList.size())
        PlayerIndex = 0;
    auto item = PlayList.at(PlayerIndex);
    Player->setMedia(QUrl::fromLocalFile(item.Url));

    if(Title == nullptr)
        return;

    Title->setText(item.Title);

    Play();
}

void MusicPlayer::Back()
{
    Pause();

    PlayerIndex--;
    if(PlayerIndex < 0)
        PlayerIndex = PlayList.size() - 1;
    auto item = PlayList[PlayerIndex];
    Player->setMedia(QUrl::fromLocalFile(item.Url));

    if(Title == nullptr)
        return;

    Title->setText(item.Title);

    Play();
}

void MusicPlayer::AddMusic(const MusicInfo& info)
{
    PlayList.append(info);
    if(PlayList.count() == 1)
    {
        auto item = PlayList.first();

        Player->setMedia(QUrl::fromLocalFile(item.Url));
        if(Title == nullptr)
            return;

        Title->setText(item.Title);
        Play();
    }
}

void MusicPlayer::on_timer_count()
{
    if(!onStop)
        slider->setValue(Player->position() * MAX_VALUE / Player->duration());
}

void MusicPlayer::on_slider_progress_sliderReleased()
{
    Player->setPosition(slider->value() * Player->duration() / MAX_VALUE);
    onStop = false;
}

void MusicPlayer::on_slider_progress_sliderPressed()
{
    onStop = true;
}

void MusicPlayer::mediaStatusChanged(QMediaPlayer::MediaStatus status)
{
    if(status == QMediaPlayer::MediaStatus::EndOfMedia)
    {
        Next();
    }
}
