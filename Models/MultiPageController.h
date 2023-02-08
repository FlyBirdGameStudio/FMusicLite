#ifndef MULTIPAGECONTROLLER_H
#define MULTIPAGECONTROLLER_H

#include <QWidget>
#include <iostream>

class MultiPageController
{
public:
    MultiPageController(QWidget* widget);

    void ChangeToPage(QWidget* page);
    void ClosePage();

private:
    std::shared_ptr<QWidget> shower;
    std::shared_ptr<QWidget> showing;
};

#endif // MULTIPAGECONTROLLER_H
