#ifndef HOMEPAGE_H
#define HOMEPAGE_H

#include <QWidget>
#include "MainWindow.h"
#include "Models/Page.h"

namespace Ui {
class HomePage;
}

class HomePage : public QWidget
{
    Q_OBJECT

public:
    explicit HomePage(MainWindow* window, QWidget *parent = nullptr);
    ~HomePage();

private slots:
    void on_play_button_clicked();

private:
    MainWindow* window;
    Ui::HomePage *ui;
};

#endif // HOMEPAGE_H
