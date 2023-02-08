#ifndef SEARCHMUSICACTION_H
#define SEARCHMUSICACTION_H

#include "NetWork/NetWorkAction.h"
#include "NetWork/networkmanager.h"

#include "UIControllers/SearchDisplay.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>

#include <QDebug>
#include <iostream>
#include <QMap>

class SearchMusicAction : public NetWorkAction
{
public:
    SearchMusicAction(const QString& keyword, SearchDisplay* display)
    {
        this->keyword = keyword;
        this->display = display;
    }

public:
    void BeginTask() override {
        NetWorkManager::Instance->PostGetTask(this);
    }

    QString GetUrl() override {
        return "http://cloud-music.pl-fe.cn/search?keywords=" + keyword;
    }

    bool OnCallBack(QNetworkReply *reply) override {

        QList<SearchResult>  map;

        auto jsonstr = QString::fromUtf8(reply->readAll());
        auto result = QJsonDocument::fromJson(jsonstr.toUtf8()).object().value("result").toObject();
        auto songs = result.value("songs").toArray();

        foreach (auto value, songs)
        {
            auto obj = value.toObject();

            int idi = obj.value("id").toInt();
            auto id = QString::number(idi);
            auto name = obj.value("name").toString();

            QString artist("");
            foreach (auto art, obj.value("artists").toArray())
                artist.append(art.toObject().value("name").toString()).append('/');

            SearchResult res(id, name, artist);
            map.append(res);
        }

        display->DisplayResult(map);
        return true;
    }

private:
    SearchDisplay* display;
    QString keyword;
};

#endif // SEARCHMUSICACTION_H
