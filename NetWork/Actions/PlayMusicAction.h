#ifndef PLAYMUSICACTION_H
#define PLAYMUSICACTION_H

#include "NetWork/NetWorkAction.h"
#include "NetWork/networkmanager.h"
#include "UIControllers/MainWindow.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>

#include <iostream>
#include <QDebug>

enum State {
    FetchInfo,
    FetchUrl
};

class PlayMusicAction : public NetWorkAction
{
public:
    PlayMusicAction(MainWindow* window, const QString& id);
    ~PlayMusicAction() override;

    void BindMusicInfo(const QString& title, const QString& imageUrl);

public:
    void BeginTask() override;
    QString GetUrl() override;
    bool OnCallBack(QNetworkReply *reply) override;

private:
    QString id;

    QString title;
    QString iamgeUrl;

    MainWindow* window;

    State state;
};

#endif // PLAYMUSICACTION_H
