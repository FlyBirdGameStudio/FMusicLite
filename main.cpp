#include "UIControllers/MainWindow.h"
#include "NetWork/networkmanager.h"
#include "Models/NotificationTool.h"

#include <QApplication>
#include <QDebug>

//int(*p)(int, int);
void log(QString text)
{
    qDebug() << text;
}

#define LOG(STR) log(STR);

int main(int argc, char *argv[])
{
    QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    NotificationTool::InitlizeIcon();
    return a.exec();
}
