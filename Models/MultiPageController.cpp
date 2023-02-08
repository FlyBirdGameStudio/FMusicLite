#include "MultiPageController.h"


MultiPageController::MultiPageController(QWidget* widget)
{
    shower.reset(widget);
}

void MultiPageController::ChangeToPage(QWidget* page)
{
    delete showing.get();
    page->setParent(shower.get());
    page->show();
    showing.reset(page);
}

void MultiPageController::ClosePage()
{

}

