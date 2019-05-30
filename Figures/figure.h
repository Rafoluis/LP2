#ifndef CLASS_FIGURE_H
#define CLASS_FIGURE_H

#include <iostream>
#include <QMainWindow>
#include <QColor>
#include <QPainter>
#include <QPixmap>
#include <QPen>
using namespace std;

class figure{

protected:
    int a;
    int b;
    string name;
public:
    virtual void draw(QPainter * painter)=0;
    virtual ~figure();

};


#endif // CLASS_FIGURE_H
