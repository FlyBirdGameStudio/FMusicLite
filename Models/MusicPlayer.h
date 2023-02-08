#ifndef MUSICPLAYER_H
#define MUSICPLAYER_H

#include <QMediaPlayer>

#include <iostream>
#include <QList>
#include <QTimer>

#include <QSlider>
#include <QLabel>

#include <QImage>
#include <QPixelFormat>

#define MAX_VALUE 1000

struct MusicInfo
{
    MusicInfo(const QString url, const QString image, const QString title)
    {
        Url = url;
        ImageUrl = image;
        Title = title;
    }

    QString Url;
    QString ImageUrl;
    QString Title;
};

enum PlayerState
{
    OnPause,
    OnPlaying,
    OnStopped
};

class MusicPlayer : public QObject
{
    Q_OBJECT

public:
    explicit MusicPlayer(QSlider* slider, QObject *parent = nullptr);
    void BindInfoLabel(QLabel* label, QLabel* image = nullptr);

    void Play();
    void Pause();

    void Next();
    void Back();

    void AddMusic(const MusicInfo& info);

signals:
    void OnMusicPlayerStateChange(const PlayerState& state);

private:
    void FetchMusicInfo(const QString& id);

private slots:
    void on_timer_count();
    void on_slider_progress_sliderReleased();
    void on_slider_progress_sliderPressed();
    void mediaStatusChanged(QMediaPlayer::MediaStatus status);

private:
    QList<MusicInfo> PlayList;
    std::shared_ptr<QMediaPlayer> Player;
    std::shared_ptr<QTimer> timer;
    std::shared_ptr<QSlider> slider;

    std::shared_ptr<QLabel> Title;
    std::shared_ptr<QLabel> Image;

    bool onStop = false;
    int PlayerIndex = 0;
};


#endif // MUSICPLAYER_H
