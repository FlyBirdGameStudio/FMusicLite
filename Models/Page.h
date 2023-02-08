#ifndef PAGE_H
#define PAGE_H

class Page
{
public:
    virtual ~Page() = 0;

    virtual void PageResize(const int w, const int h) = 0;
};

#endif // PAGE_H
