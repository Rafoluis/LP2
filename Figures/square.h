#ifndef CLASS_SQUARE_H
#define CLASS_SQUARE_H

#include <iostream>
#include <QMainWindow>
#include <QColor>
#include <QPainter>
#include <QPixmap>
#include <QPen>
#include "figure.h"
#include "mainwindow.h"
using namespace std;

class square:public figure
{
private:

public:
    void draw(QPainter * painter);
};

#endif // CLASS_SQUARE_H
