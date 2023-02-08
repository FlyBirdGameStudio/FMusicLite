#include "PlayMusicAction.h"

#include "NetWork/Actions/GetMusicInfoAction.h"

PlayMusicAction::PlayMusicAction(MainWindow *window, const QString &id)
{
    state = State::FetchInfo;

    this->window = (window);
    this->id = id;
}

PlayMusicAction::~PlayMusicAction()
{

}

void PlayMusicAction::BindMusicInfo(const QString &title, const QString &imageUrl)
{
    this->title = title;
    this->iamgeUrl = imageUrl;

    state = State::FetchUrl;
    this->BeginTask();
}

void PlayMusicAction::BeginTask()
{
    switch(state)
    {
    case FetchInfo: {
        auto action = new GetMusicInfoAction(id, this);
        action->BeginTask();
        break;
    }
    case FetchUrl:

        NetWorkManager::Instance->PostGetTask(this);
        break;
    }
}

QString PlayMusicAction::GetUrl()
{
    QString s("http://music.163.com/api/song/enhance/player/url?id=123456&ids=[");
    s.append(id).append("]&br=3200000");
    return s;
}

bool PlayMusicAction::OnCallBack(QNetworkReply *reply)
{
    auto json = (QString::fromUtf8(reply->readAll()));

    auto array = QJsonDocument::fromJson(json.toUtf8()).object().value("data");
    auto url = array.toArray()[0].toObject().value("url").toString();

    MusicInfo info(url, iamgeUrl, title);

    window->Player->AddMusic(info);
    return true;
}
