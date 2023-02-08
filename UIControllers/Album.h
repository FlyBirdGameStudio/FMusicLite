#ifndef ALBUM_H
#define ALBUM_H

#include <QWidget>

namespace Ui {
class Album;
}

class Album : public QWidget
{
    Q_OBJECT

public:
    explicit Album(QWidget *parent = nullptr);
    ~Album();

private:
    Ui::Album *ui;
};

#endif // ALBUM_H
