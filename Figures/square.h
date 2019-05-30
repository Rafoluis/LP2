#ifndef CLASS_SQUARE_H
#define CLASS_SQUARE_H

#include <iostream>
#include <QMainWindow>
#include <QColor>
#include <QPainter>
#include <QPixmap>
#include <QPen>
#include "figure.h"
using namespace std;

class square:public figure
{
private:
    int c;
public:
    square(int xx=0, int yy=0, int ll_size=0);
    ~square();
    void draw(QPainter * painter);
};

#endif // CLASS_SQUARE_H
