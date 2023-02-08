#ifndef UIHELPER_H
#define UIHELPER_H

#include <QWidget>
#include <QFontDatabase>
#include <QPushButton>

class UIHelper
{
public:
    static void InsertAllIconFont(const QWidget*, const QFont);
    static void InsertIconFont(QPushButton*, const QString& sheet);
    static QFont LoadFontFromAssets(const QString& name, const QString& path);
};

#endif // UIHELPER_H
