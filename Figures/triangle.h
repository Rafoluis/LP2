#ifndef CLASS_TRIANGLE_H
#define CLASS_TRIANGLE_H

#include <iostream>
#include <QMainWindow>
#include <QColor>
#include <QPainter>
#include <QPixmap>
#include <QPen>
#include "figure.h"
#include "mainwindow.h"
using namespace std;

class triangle:public figure
{
private:

public:
    void draw(QPainter * painter);
};

#endif // CLASS_TRIANGLE_H
