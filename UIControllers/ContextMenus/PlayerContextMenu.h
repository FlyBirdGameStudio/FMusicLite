#ifndef PLAYERCONTEXTMENU_H
#define PLAYERCONTEXTMENU_H

#include "Models/UIContextMenu.h"

#include <QMessageBox>

class PlayerContextMenu : public UIContextMenu
{
public:
    void BuildMenu() override {
        menu->addAction("测试1");
        menu->addAction("测试2");
        menu->addAction("测试3");
    }

    void OnMenuActionEvent(const int &id) override {
        QMessageBox::about(nullptr, "Hints", "On Click -> " + QString::number(id));
    }
};

#endif // PLAYERCONTEXTMENU_H
