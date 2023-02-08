#ifndef MYPAGE_H
#define MYPAGE_H

#include <QWidget>

namespace Ui {
class MyPage;
}

class MyPage : public QWidget
{
    Q_OBJECT

public:
    explicit MyPage(QWidget *parent = nullptr);
    ~MyPage();

private:
    Ui::MyPage *ui;
};

#endif // MYPAGE_H
