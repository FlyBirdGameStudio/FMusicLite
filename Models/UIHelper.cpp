#include "UIHelper.h"


void UIHelper::InsertAllIconFont(const QWidget *widget, const QFont font)
{
    auto children = widget->children();
    foreach(auto child, children)
    {
        if(typeid(child) == typeid(QPushButton))
        {
            auto btn = qobject_cast<QPushButton*>(child);
            auto text = btn->text();
            if(!text.startsWith("#"))
                continue;
            text.remove(0, 1);
            int c = text.toInt();

            btn->setFont(font);
            btn->setText(QChar(c));
        }
    }
}

void UIHelper::InsertIconFont(QPushButton *btn, const QString& sheet)
{
    auto text = btn->text();
    if(!text.startsWith("#"))
        return;
    text.remove(0, 1);
    uint c = text.toUInt();

    btn->setStyleSheet(sheet);
    btn->setText(QChar());
}

QFont UIHelper::LoadFontFromAssets(const QString &name, const QString &path)
{
    QFontDatabase fontDb;
    if(!fontDb.families().contains(name))
        fontDb.addApplicationFont(path);

    QFont font(name);
    font.setHintingPreference(QFont::PreferNoHinting);
    return font;
}
