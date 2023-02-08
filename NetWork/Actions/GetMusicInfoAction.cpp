#include "GetMusicInfoAction.h"

GetMusicInfoAction::GetMusicInfoAction(const QString &id, PlayMusicAction* action)
{
    this->action = (action);

    QString u("http://cloud-music.pl-fe.cn/song/detail?ids=");
    u.append(id);
    this->url = u;
}

GetMusicInfoAction::~GetMusicInfoAction()
{

}

void GetMusicInfoAction::BeginTask()
{
    NetWorkManager::Instance->PostGetTask(this);
}

QString GetMusicInfoAction::GetUrl()
{
    return url;
}

bool GetMusicInfoAction::OnCallBack(QNetworkReply *reply)
{
    auto jsonstr = QString::fromUtf8(reply->readAll());
    auto songs = QJsonDocument::fromJson(jsonstr.toUtf8()).object().value("songs").toArray();

    //TODO
    auto obj = songs[0].toObject();
    auto name = obj.value("name").toString();

    QString arts("");
    foreach(auto a, obj.value("ar").toArray())
    {
        name.append(a["name"].toString()).append("/");
    }
    arts = arts.remove(arts.length() - 2, 1);

    action->BindMusicInfo(name.append("\n").append(arts), nullptr);
    return true;
}
