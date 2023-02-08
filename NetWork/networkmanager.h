#ifndef NETWORKMANAGER_H
#define NETWORKMANAGER_H

#include <QNetworkRequest>
#include <QNetworkReply>
#include <QNetworkAccessManager>
#include <QObject>
#include <iostream>
#include <QList>

#include "NetWork/NetWorkAction.h"

class NetWorkManager : public QObject
{
    Q_OBJECT
public:
    NetWorkManager();

    void PostGetTask(NetWorkAction* basic);

public:
    static NetWorkManager* Instance;
    bool AutoDelete = true;

private slots:
    void requestFinished(QNetworkReply* reply);

private:
    QList<NetWorkAction*> CallBacks;
    std::shared_ptr<QNetworkAccessManager> naManager;
};

#endif // NETWORKMANAGER_H
