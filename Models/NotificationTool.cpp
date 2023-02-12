#include "NotificationTool.h"

#include "UIControllers/ContextMenus/TaskBarContextMenu.h"

QSystemTrayIcon* NotificationTool::icon;

void NotificationTool::InitlizeIcon()
{
    icon = new QSystemTrayIcon();
    QIcon ticon(":/Images/FMusic.ico");
    icon->setIcon(ticon);
    icon->show();
}

void NotificationTool::UninstallIcon()
{
    icon->hide();
    icon->destroyed();
    delete icon;
}

void NotificationTool::SendMsg(QString Title, QString Msg)
{
    icon->showMessage(Title, Msg, icon->icon());
}

void NotificationTool::BindContextMenu()
{
    auto menu = new TaskBarContextMenu();
    menu->BindUI(nullptr);
    auto m = menu->GetMenu();

    icon->setContextMenu(m);
}
