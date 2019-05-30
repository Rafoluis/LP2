#include "square.h"

square::square(int xx,int yy, int ll_size){
    a=xx; b=yy; c=ll_size;
}

square::~square(){}

void square::draw(QPainter * painter)
{
    painter->drawRect(QRect(a,b,c,c));
}
