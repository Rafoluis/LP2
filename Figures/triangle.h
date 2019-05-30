#ifndef CLASS_TRIANGLE_H
#define CLASS_TRIANGLE_H

#include <iostream>
#include <QMainWindow>
#include <QColor>
#include <QPainter>
#include <QPixmap>
#include <QPen>
#include "figure.h"
using namespace std;

class triangle:public figure
{
private:
    int c;

public:
    triangle(int xx=0, int yy=0, int ll_size=0);
    ~triangle();
    void draw(QPainter * painter);
};

#endif // CLASS_TRIANGLE_H
