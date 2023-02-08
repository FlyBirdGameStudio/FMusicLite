#ifndef GETMUSICINFOACTION_H
#define GETMUSICINFOACTION_H

#include "NetWork/NetWorkAction.h"
#include "NetWork/networkmanager.h"

#include "NetWork/Actions/PlayMusicAction.h"

#include <iostream>

#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>

class GetMusicInfoAction : public NetWorkAction
{
public:
    GetMusicInfoAction(const QString& id, PlayMusicAction* action);
    ~GetMusicInfoAction() override;

public:
    void BeginTask() override;
    QString GetUrl() override;
    bool OnCallBack(QNetworkReply *reply) override;

private:
    QString url;
    PlayMusicAction* action;
};

#endif // GETMUSICINFOACTION_H
