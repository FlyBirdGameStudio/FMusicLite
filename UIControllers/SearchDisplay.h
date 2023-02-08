#ifndef SEARCHDISPLAY_H
#define SEARCHDISPLAY_H

#include <QWidget>
#include <QList>

#include "MainWindow.h"

struct SearchResult
{
    SearchResult(const QString id, const QString title, const QString authors)
        : ID(id), Title(title), Authors(authors)
    {

    }

    QString ID;
    QString Title;
    QString Authors;
};

namespace Ui {
class SearchDisplay;
}

class SearchDisplay : public QWidget
{
    Q_OBJECT

public:
    explicit SearchDisplay(const QString& text, MainWindow* window, QWidget *parent = nullptr);
    ~SearchDisplay();

    void DisplayResult(const QList<SearchResult> results);

private slots:
    void on_PlayMusic_clicked();

private:
    MainWindow* window;
    Ui::SearchDisplay *ui;

    QList<SearchResult> results;
};

#endif // SEARCHDISPLAY_H
