#ifndef NOTIFICATIONTOOL_H
#define NOTIFICATIONTOOL_H

#include <QSystemTrayIcon>

class NotificationTool
{
public:
    static void InitlizeIcon();
    static void UninstallIcon();
    static void SendMsg(QString Title, QString Msg);
private:
    static QSystemTrayIcon* icon;
};

#endif // NOTIFICATIONTOOL_H
