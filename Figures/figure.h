#ifndef CLASS_FIGURE_H
#define CLASS_FIGURE_H

#include <iostream>
#include <QMainWindow>
#include <QColor>
#include <QPainter>
#include <QPixmap>
#include <QPen>
#include "mainwindow.h"
using namespace std;

class figure:public MainWindow{
protected:
    string name;
public:
    virtual void draw(QPainter * painter)=0;
};


#endif // CLASS_FIGURE_H
