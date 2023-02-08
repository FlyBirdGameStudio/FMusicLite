#ifndef UICONTEXTMENU_H
#define UICONTEXTMENU_H

#include <QPushButton>
#include <QMenu>

#include <iostream>

class UIContextMenu {
public:
    UIContextMenu(QPushButton* widget)
    {
        menu.reset(new QMenu());
        widget->setMenu(menu.get());
    }
    virtual ~UIContextMenu() = 0;

    virtual void BuildMenu() = 0;

private:
    std::shared_ptr<QMenu> menu;
};

#endif // UICONTEXTMENU_H
