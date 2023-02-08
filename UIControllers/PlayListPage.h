#ifndef PLAYLISTPAGE_H
#define PLAYLISTPAGE_H

#include <QWidget>

namespace Ui {
class PlayListPage;
}

class PlayListPage : public QWidget
{
    Q_OBJECT

public:
    explicit PlayListPage(QWidget *parent = nullptr);
    ~PlayListPage();

private:
    Ui::PlayListPage *ui;
};

#endif // PLAYLISTPAGE_H
