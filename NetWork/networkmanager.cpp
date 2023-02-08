#include "networkmanager.h"
#include <QDebug>

NetWorkManager* NetWorkManager::Instance = new NetWorkManager;

NetWorkManager::NetWorkManager()
{
    naManager.reset(new QNetworkAccessManager());
    QMetaObject::Connection connRet = QObject::connect(naManager.get(), SIGNAL(finished(QNetworkReply*)), this, SLOT(requestFinished(QNetworkReply*)));
    Q_ASSERT(connRet);

}

void NetWorkManager::PostGetTask(NetWorkAction* basic)
{
    QNetworkRequest request;
    request.setUrl(basic->GetUrl());
    CallBacks.append(basic);
    naManager->get(request);
}

void NetWorkManager::requestFinished(QNetworkReply *reply)
{
    auto callback = CallBacks.takeFirst();
    auto result = callback->OnCallBack(reply);
    if(result != true)
        qDebug() << "Error When Excuting Action";
    if(AutoDelete)
        delete callback;
}
