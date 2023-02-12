#ifndef MUISCLISTCARD_H
#define MUISCLISTCARD_H

#include <QWidget>

namespace Ui {
class MuiscListCard;
}

class MuiscListCard : public QWidget
{
    Q_OBJECT

public:
    explicit MuiscListCard(QWidget *parent = nullptr);
    ~MuiscListCard();

private:
    Ui::MuiscListCard *ui;
};

#endif // MUISCLISTCARD_H
