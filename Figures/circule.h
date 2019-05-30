#ifndef CLASS_CIRCULE_H
#define CLASS_CIRCULE_H

#include <iostream>
#include <QMainWindow>
#include <QColor>
#include <QPainter>
#include <QPixmap>
#include <QPen>
#include "figure.h"
#include "mainwindow.h"
using namespace std;

class circule:public figure
{
private:

public:
    void draw(QPainter * painter);
};

#endif // CLASS_CIRCULE_H
