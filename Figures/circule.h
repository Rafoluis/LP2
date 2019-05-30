#ifndef CLASS_CIRCULE_H
#define CLASS_CIRCULE_H

#include <iostream>
#include <QMainWindow>
#include <QColor>
#include <QPainter>
#include <QPixmap>
#include <QPen>
#include "figure.h"
using namespace std;

class circule:public figure
{
private:
    int c;

public:
    circule(int xx=0, int yy=0, int ll_size=0);
    ~circule();
    void draw(QPainter * painter);
};

#endif // CLASS_CIRCULE_H
