#ifndef UICONTEXTMENU_H
#define UICONTEXTMENU_H

#include <QMenu>

#include <iostream>

class UIContextMenu : public QObject
{
    Q_OBJECT
public:

    virtual ~UIContextMenu() {

        auto list = menu->actions();
        foreach (auto pAction, list)
            delete pAction;
    };

    virtual void BuildMenu() = 0;
    virtual void OnMenuActionEvent(const int& id) = 0;

    void BindUI(QWidget* widget)
    {
        menu.reset(new QMenu(widget));
        sender = widget;

        if(widget != nullptr){
            widget->setContextMenuPolicy(Qt::CustomContextMenu);
            connect(widget, &QWidget::customContextMenuRequested, this, &UIContextMenu::showContextMenu);
        } else {
            BuildMenu();

            auto list = menu->actions();
            foreach(auto action, list)
                connect(action, &QAction::triggered, this, &UIContextMenu::OnClickedPopMenu);
        }
    }

    QMenu* GetMenu() const {
        return menu.get();
    }

private slots:

    void showContextMenu(const QPoint &pos) {

        BuildMenu();

        auto list = menu->actions();
        foreach(auto action, list)
            connect(action, &QAction::triggered, this, &UIContextMenu::OnClickedPopMenu);

        if(sender != nullptr){
            auto p = sender->cursor().pos();
            menu->exec(p);
        } else {
            menu->exec(pos);
        }

        foreach (auto pAction, list)
            delete pAction;
    }

    void OnClickedPopMenu()
    {
        auto *pEven = qobject_cast<QAction *>(this->QObject::sender());
        auto iType = pEven->data().toInt();
        OnMenuActionEvent(iType);
    }

protected:
    QWidget* sender; // DO NOT DELETE IT!
    std::shared_ptr<QMenu> menu;
};

#endif // UICONTEXTMENU_H
