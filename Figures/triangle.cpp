#include "triangle.h"

triangle::triangle(int xx,int yy, int ll_size){
    a=xx; b=yy; c=ll_size;
}

triangle::~triangle(){}

void triangle::draw(QPainter * painter)
{
    QPolygon poly;
    poly << QPoint(a,b);
    poly << QPoint(a-b,b+c);
    poly << QPoint(a+c,b+c);
    painter->drawPolygon(poly);
}
