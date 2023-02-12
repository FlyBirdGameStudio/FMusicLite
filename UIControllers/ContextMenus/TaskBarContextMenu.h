#ifndef TASKBARCONTEXTMENU_H
#define TASKBARCONTEXTMENU_H

#include "Models/UIContextMenu.h"
#include <QMessageBox>
#include <QDebug>

class TaskBarContextMenu : public UIContextMenu
{
public:
    void BuildMenu() override {

        menu->addAction("Pause/Resume");
        menu->addAction("Next Music");
        menu->addSeparator();
        menu->addAction("About");
        menu->addAction("Exit FMusic Lite");
    }

    void OnMenuActionEvent(const int &id) override {

        QMessageBox::information(sender, "About Fmusic Lite", "Nothing Here ~");

        switch(id)
        {

        }
    }
};

#endif // TASKBARCONTEXTMENU_H
