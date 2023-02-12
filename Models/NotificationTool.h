#ifndef NOTIFICATIONTOOL_H
#define NOTIFICATIONTOOL_H

#include <QSystemTrayIcon>

class NotificationTool
{
public:
    static void InitlizeIcon();
    static void UninstallIcon();
    static void SendMsg(QString Title, QString Msg);
    static void BindContextMenu();

    static QSystemTrayIcon* GetIcon() {
        return icon;
    }
private slots:
    static void OnClick();

private:
    static QSystemTrayIcon* icon;
};

#endif // NOTIFICATIONTOOL_H
