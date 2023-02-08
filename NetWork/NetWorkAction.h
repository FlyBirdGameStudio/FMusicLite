#ifndef NETWORKACTION_H
#define NETWORKACTION_H

#include <QNetworkReply>

class NetWorkAction
{
public:
    virtual ~NetWorkAction() = default;

    virtual void BeginTask() = 0;
    virtual QString GetUrl() = 0;
    virtual bool OnCallBack(QNetworkReply* reply) = 0;
};

#endif // NETWORKACTION_H
