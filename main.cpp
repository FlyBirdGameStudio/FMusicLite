#include "UIControllers/MainWindow.h"
#include "NetWork/networkmanager.h"

#include "UIControllers/ContextMenus/TaskBarContextMenu.h"
#include "Models/NotificationTool.h"

#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    /* Init Taskbar Icon */

    NotificationTool::InitlizeIcon();
    NotificationTool::BindContextMenu();

    return a.exec();
}
